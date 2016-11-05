#ifndef file_path_hh
#define file_path_hh
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
#endif //file_path_hh