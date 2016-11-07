#ifndef as_fs_env_hh
#define as_fs_env_hh
#include "PathUtils.h"
#include "FileDescriptor.h"
#include <map>
#include <string>
class ASFSEnv
{
  private:
    std::map<long, FileDescriptor> m;

  public:
    long fd;
    ASFSEnv()
    {
        this->fd = 0;
    }
    long generateFD(const char *path)
    {
        this->fd++;
        FilePath *filePath = PathUtils::parse(path);
        if (NULL != filePath)
        {
            delete filePath;
            filePath = NULL;
        }
        m.insert(std::pair<int, FileDescriptor>(this->fd, FileDescriptor(path)));
        return this->fd;
    }
};

#endif //as_fs_env_hh