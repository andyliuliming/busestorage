#ifndef file_descriptor_hh
#define file_descriptor_hh
#include <string>
class FileDescriptor
{
  public:
    std::string path;
    FileDescriptor(const char *path)
    {
        this->path = path;
    }
};

#endif //file_descriptor_hh