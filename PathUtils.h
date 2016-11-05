#ifndef path_utils_hh
#define path_utils_hh
#include <string>
#include <cstring>
#define ROOT_DIRECTORY ("$root")
class FilePath
{
  public:
    char *directory = NULL;
    char *fileName = NULL;
    ~FilePath()
    {
        if (this->directory == NULL)
        {
            delete this->directory;
            this->directory = NULL;
        }
        if (this->fileName == NULL)
        {
            delete this->fileName;
            this->fileName = NULL;
        }
    }
};

class PathUtils
{
  public:
    PathUtils()
    {
    }

    static FilePath *parse(const char *path);
};

#endif //path_utils_hh