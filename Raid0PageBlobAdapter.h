#ifndef raid0_page_blob_adapter_hh
#define raid0_page_blob_adapter_hh
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "was/storage_account.h"
#include "was/blob.h"

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
        return -1;
    }
    inline int write(char *buf, size_t size, off_t offset)
    {
        return -1;
    }
};

#endif //raid0_page_blob_adapter_hh