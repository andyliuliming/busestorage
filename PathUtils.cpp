#include "PathUtils.h"

#include <syslog.h>
FilePath *PathUtils::parse(const char *path)
{
    // if have more than one '/' then it's file, or it's a dir because
    // aure storage only support one container and one path.
    // '/' is root path
    // '/abc' is a file, we make the directory as $root
    // '/abc/def' is a file
    // '/abc/' is a directory
    std::string pathStr = path;
    std::size_t firstSlash = pathStr.find('/');
    std::size_t lastOfSlash = pathStr.find_last_of('/');
    FilePath *filePath = new FilePath();
    if (firstSlash == lastOfSlash)
    {
        filePath->directory = new char[strlen(ROOT_DIRECTORY) + 1];
        strcpy(filePath->directory, ROOT_DIRECTORY);
    }
    else
    {
        int totalLen = strlen(path);
        filePath->directory = new char[lastOfSlash];
        strncpy(filePath->directory, path + 1, lastOfSlash - 1);
        filePath->directory[lastOfSlash-1]='\0';

        int fileNameLen = totalLen - lastOfSlash;
        filePath->fileName = new char[fileNameLen + 1];

        strncpy(filePath->fileName, path + lastOfSlash + 1, fileNameLen);
        //syslog(LOG_INFO, "origin path %s\n", path);
        //syslog(LOG_INFO, "directory %s fileName %s\n", filePath->directory, filePath->fileName);
    }
    return filePath;
}