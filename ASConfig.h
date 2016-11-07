#ifndef as_config_hh
#define as_config_hh
#include <string>
class ASConfig
{
  public:
    std::string storageAccountName;
    std::string storageAccountKey;
    
    ASConfig(const char * storageAccountName, const char * storageAccountKey)
    {
        this->storageAccountName = storageAccountName;
        this->storageAccountKey = storageAccountKey;
    }
};

#endif //as_config_hh