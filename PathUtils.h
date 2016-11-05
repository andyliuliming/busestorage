#ifndef path_utils_hh
#define path_utils_hh
#include <string>
#include <cstring>
#include "FilePath.h"
#define ROOT_DIRECTORY ("$root")
class PathUtils
{
  public:
    PathUtils()
    {
    }

    static FilePath *parse(const char *path);
};

#endif //path_utils_hh