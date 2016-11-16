#ifndef raid0_page_blob_adapter_hh
#define raid0_page_blob_adapter_hh
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "AbstractPageBlobAdapter.h"
#include "PathUtils.h"
#include "FileDescriptor.h"
#include "was/storage_account.h"
#include "was/blob.h"

/*
 first calculate the pageBlob index, and then read/write it
*/
class Raid0PageBlobAdapter : public virtual AbstractPageBlobAdapter
{
  private:
    std::vector<azure::storage::cloud_page_blob> &pageBlobs;
    size_t sectionSize;

  public:
    Raid0PageBlobAdapter(std::vector<azure::storage::cloud_page_blob> &pageBlobs, size_t sectionSize) : pageBlobs(pageBlobs), sectionSize(sectionSize)
    {
    }
    inline uint64_t getSize()
    {
        return -1;
    }

    inline int read(char *buf, size_t size, off_t offset)
    {
        // concurrency::streams::container_buffer<std::vector<char>> containerBuffer;
        // concurrency::streams::ostream output_stream(containerBuffer);
        // blob.download_range_to_stream(output_stream, offset, size);
        // std::vector<char> collec = containerBuffer.collection();
        // int sizeRead = collec.size();
        // char *char_arr = collec.data();
        // memcpy(buf, char_arr, sizeRead);

        // return sizeRead;
        return -1;
    }
    inline int write(char *buf, size_t size, off_t offset)
    {
        // std::vector<uint8_t> uploadBuffer(buf, buf + size);

        // auto stream = concurrency::streams::bytestream::open_istream(uploadBuffer);
        // blob.upload_pages(stream, offset, utility::string_t());
        return -1;
    }
};

#endif //raid0_page_blob_adapter_hh