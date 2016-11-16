#ifndef abstract_page_blob_adapter_hh
#define abstract_page_blob_adapter_hh
class AbstractPageBlobAdapter
{
  private:
  public:
    inline virtual uint64_t getSize();
    inline virtual int read(char *buf, size_t size, off_t offset);
    inline virtual int write(char *buf, size_t size, off_t offset);
};

#endif //abstract_page_blob_adapter_hh