#ifndef abstract_page_blob_adapter_hh
#define abstract_page_blob_adapter_hh
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
class AbstractPageBlobAdapter
{
public:
  virtual uint64_t getSize()=0;
  virtual int read(char *buf, size_t size, off_t offset)=0;
  virtual int write(char *buf, size_t size, off_t offset)=0;
};

#endif //abstract_page_blob_adapter_hh