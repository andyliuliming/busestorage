#ifndef page_blob_adapter_hh
#define page_blob_adapter_hh
#include "PathUtils.h"
#include "FileDescriptor.h"
#include <map>
#include <string>
#include <syslog.h>
#include "was/storage_account.h"
#include "was/blob.h"
#include "ASConfig.h"

class SinglePageBlobAdapter
{
private:
  azure::storage::cloud_page_blob &blob;

public:
  SinglePageBlobAdapter(azure::storage::cloud_page_blob &page_blob) : blob(page_blob)
  {
  }

  inline uint64_t getSize()
  {
    blob.download_attributes();
    auto blobProp = blob.properties();
    return blobProp.size();
  }

  inline int read(char *buf, size_t size, off_t offset)
  {
    //TODO: cache the container in memory.

    //TODO download the stream without copying data
    concurrency::streams::container_buffer<std::vector<char>> containerBuffer;
    concurrency::streams::ostream output_stream(containerBuffer);
    blob.download_range_to_stream(output_stream, offset, size);
    std::vector<char> collec = containerBuffer.collection();
    int sizeRead = collec.size();
    char *char_arr = collec.data();
    memcpy(buf, char_arr, sizeRead);

    return sizeRead;
  }

  inline int write(char *buf, size_t size, off_t offset)
  {
    //TODO upload the stream without copying data
    std::vector<uint8_t> uploadBuffer(buf, buf + size);

    auto stream = concurrency::streams::bytestream::open_istream(uploadBuffer);
    blob.upload_pages(stream, offset, utility::string_t());
    return 0;
  }
  ~SinglePageBlobAdapter()
  {
  }
};

#endif //page_blob_adapter_hh