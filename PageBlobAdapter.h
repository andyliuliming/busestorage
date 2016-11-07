#ifndef page_blob_adapter_hh
#define page_blob_adapter_hh
#include "PathUtils.h"
#include "FileDescriptor.h"
#include <map>
#include <string>
#include <syslog.h>
#include "was/storage_account.h"
#include "was/blob.h"
#include "AzureStorageConfig.h"

class char_array_buffer : public std::streambuf
{
public:
  char_array_buffer(char *data, unsigned int len);

private:
  int_type underflow();
  int_type uflow();
  int_type pbackfail(int_type ch);
  std::streamsize showmanyc();

  char *const begin_;
  char *const end_;
  char *current_;
};

class PageBlobAdapter
{
private:
  AzureStorageConfig *azureStorageConfig;
  azure::storage::cloud_storage_account *storage_account;
  azure::storage::cloud_blob_client *blob_client;

public:
  PageBlobAdapter(AzureStorageConfig *config)
  {
    this->azureStorageConfig = config;
    std::string connectionStr = std::string("DefaultEndpointsProtocol=http;EndpointSuffix=core.chinacloudapi.cn;AccountName=") + config->storageAccountName + ";AccountKey=" + config->storageAccountKey;
    utility::string_t storage_connection_string(_XPLATSTR(connectionStr));
    this->storage_account = new azure::storage::cloud_storage_account(azure::storage::cloud_storage_account::parse(storage_connection_string));
    this->blob_client = new azure::storage::cloud_blob_client(this->storage_account->create_cloud_blob_client());
  }

  inline uint64_t getSize(FilePath *filePath)
  {
    syslog(LOG_INFO, "PageBlobAdapter::getSize %s %s\n", filePath->directory, filePath->fileName);
    azure::storage::cloud_blob_container container = blob_client->get_container_reference(_XPLATSTR(filePath->directory));
    if (container.exists())
    {
      //TODO: cache the blob in memory.
      azure::storage::cloud_page_blob blob1 = container.get_page_blob_reference(_XPLATSTR(filePath->fileName));
      blob1.download_attributes();

      auto blobProp = blob1.properties();

      return blobProp.size();
    }
    else
    {
      return 0;
    }
  }

  inline int read(FilePath *filePath, char *buf, size_t size, off_t offset)
  {
    //TODO: cache the container in memory.
    azure::storage::cloud_blob_container container = blob_client->get_container_reference(_XPLATSTR(filePath->directory));
    azure::storage::cloud_page_blob blob1 = container.get_page_blob_reference(_XPLATSTR(filePath->fileName));
    //TODO download the stream without copying data
    concurrency::streams::container_buffer<std::vector<char>> containerBuffer;
    concurrency::streams::ostream output_stream(containerBuffer);
    blob1.download_range_to_stream(output_stream, offset, size);
    std::vector<char> collec = containerBuffer.collection();
    int sizeRead = collec.size();
    char *char_arr = collec.data();
    memcpy(buf, char_arr, sizeRead);

    return sizeRead;
  }

  inline int write(FilePath *filePath, char *buf, size_t size, off_t offset)
  {
    azure::storage::cloud_blob_container container = blob_client->get_container_reference(_XPLATSTR(filePath->directory));
    azure::storage::cloud_page_blob blob1 = container.get_page_blob_reference(_XPLATSTR(filePath->fileName));
    //TODO upload the stream without copying data
    std::vector<uint8_t> uploadBuffer(buf, buf + size);

    auto stream = concurrency::streams::bytestream::open_istream(uploadBuffer);
    blob1.upload_pages(stream, offset, utility::string_t());
    return 0;
  }

  ~PageBlobAdapter()
  {
  }
};

#endif //page_blob_adapter_hh