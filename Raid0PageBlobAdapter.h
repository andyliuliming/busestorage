#ifndef raid0_page_blob_adapter_hh
#define raid0_page_blob_adapter_hh
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
class Raid0PageBlobAdapter : public virtual AbstractPageBlobAdapter
{
  public:
    Raid0PageBlobAdapter(vector<azure::storage::cloud_page_blob> &pageBlobs)
    {
        //azure::storage::cloud_page_blob
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