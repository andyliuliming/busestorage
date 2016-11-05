#ifndef azure_storage_adapter_hh
#define azure_storage_adapter_hh
#include "PathUtils.h"
#include "FileDescriptor.h"
#include <map>
#include <string>
#include <syslog.h>
#include "was/storage_account.h"
#include "was/blob.h"
#include "AzureStorageConfig.h"

class char_array_buffer : public std::streambuf {
public:
    char_array_buffer(char *data, unsigned int len);
 
private:
    int_type underflow();
    int_type uflow();
    int_type pbackfail(int_type ch);
    std::streamsize showmanyc();
 
    char * const begin_;
    char * const end_;
    char * current_;
};

class AzureStorageAdapter
{
private:
  AzureStorageConfig *azureStorageConfig;
  azure::storage::cloud_storage_account *storage_account;
  azure::storage::cloud_blob_client *blob_client;

public:
  AzureStorageAdapter(AzureStorageConfig *config)
  {
    this->azureStorageConfig = config;
    std::string connectionStr = std::string("DefaultEndpointsProtocol=http;EndpointSuffix=core.chinacloudapi.cn;AccountName=") + config->storageAccountName + ";AccountKey=" + config->storageAccountKey;
    utility::string_t storage_connection_string(_XPLATSTR(connectionStr));
    this->storage_account = new azure::storage::cloud_storage_account(azure::storage::cloud_storage_account::parse(storage_connection_string));
    this->blob_client = new azure::storage::cloud_blob_client(this->storage_account->create_cloud_blob_client());
  }
  inline long getSize(FilePath *filePath)
  {
    syslog(LOG_INFO, "AzureStorageAdapter::getSize %s %s\n", filePath->directory, filePath->fileName);
    azure::storage::cloud_blob_container container = blob_client->get_container_reference(_XPLATSTR(filePath->directory));
    if (container.exists())
    {
      syslog(LOG_INFO, "AzureStorageAdapter::getSize2\n");
      //TODO: cache the blob in memory.
      azure::storage::cloud_block_blob blob1 = container.get_block_blob_reference(_XPLATSTR(filePath->fileName));
      blob1.download_attributes();
      syslog(LOG_INFO, "AzureStorageAdapter::getSize3\n");
      return blob1.properties().size();
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
    azure::storage::cloud_block_blob blob1 = container.get_block_blob_reference(_XPLATSTR(filePath->fileName));
    
    auto fileBlobStream = blob1.open_read();
    
    //char_array_buffer sbuf(buf, size);

    //fileBlobStream.seek(offset, std::ios_base::beg);
     //fileBlobStream.read(sbuf, size);

    //blobstream.read();
    //return result;
    return 0;
  }
  ~AzureStorageAdapter()
  {
  }
};

#endif //azure_storage_adapter_hh