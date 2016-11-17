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
    int pageBlobsLength;
    size_t sectionSize;

  public:
    Raid0PageBlobAdapter(std::vector<azure::storage::cloud_page_blob> &pageBlobs, size_t sectionSize) : pageBlobs(pageBlobs), sectionSize(sectionSize)
    {
        this->pageBlobsLength = pageBlobs.size();
    }

    inline uint64_t getSize()
    {
        uint64_t totalSize = 0;
        for (int i = 0; i < pageBlobsLength; i++)
        {
            pageBlobs[i].download_attributes();
            auto blobProp = pageBlobs[i].properties();
            totalSize += blobProp.size();
        }
        return totalSize;
    }

    inline int read(char *buf, size_t size, off_t offset)
    {
        concurrency::streams::container_buffer<std::vector<char>> containerBuffer;
        concurrency::streams::ostream output_stream(containerBuffer);
        int sizeRemain = 0;
        off_t curOffset = offset;

        while (sizeRemain > 0)
        {
            int xDirectIndex = curOffset / (sectionSize * pageBlobsLength);
            int yDirectIndex = (curOffset / sectionSize) % pageBlobsLength;

            off_t offsetInner = curOffset % sectionSize;
            int stepReadSize = ((offsetInner + sizeRemain) > sectionSize) ? (sectionSize - offsetInner) : (sizeRemain);

            pageBlobs[yDirectIndex].download_range_to_stream(output_stream, xDirectIndex * sectionSize + offsetInner, stepReadSize);
            sizeRemain -= stepReadSize;
        }
        std::vector<char> collec = containerBuffer.collection();
        int sizeRead = collec.size();
        char *char_arr = collec.data();
        memcpy(buf, char_arr, sizeRead);
        return 0;
    }

    inline int write(char *buf, size_t size, off_t offset)
    {
        int sizeRemain = 0;
        off_t curOffset = offset;

        while (sizeRemain > 0)
        {
            int xDirectIndex = curOffset / (sectionSize * pageBlobsLength);
            int yDirectIndex = (curOffset / sectionSize) % pageBlobsLength;

            off_t offsetInner = curOffset % sectionSize;
            int stepWriteSize = ((offsetInner + sizeRemain) > sectionSize) ? (sectionSize - offsetInner) : (sizeRemain);

            std::vector<uint8_t> uploadBuffer(buf + (size - sizeRemain), buf + (size - sizeRemain) + stepWriteSize);
            auto stream = concurrency::streams::bytestream::open_istream(uploadBuffer);
            pageBlobs[yDirectIndex].upload_pages(stream, xDirectIndex * sectionSize + offsetInner, utility::string_t());

            sizeRemain -= stepWriteSize;
        }

        return -1;
    }
};

#endif //raid0_page_blob_adapter_hh