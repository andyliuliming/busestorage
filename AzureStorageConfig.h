#ifndef azure_storage_config_hh
#define azure_storage_config_hh
#include <string>
class AzureStorageConfig
{
  public:
    std::string storageAccountName;
    std::string storageAccountKey;
    AzureStorageConfig(const char * storageAccountName, const char * storageAccountKey)
    {
        this->storageAccountName = storageAccountName;
        this->storageAccountKey = storageAccountKey;
    }
};

#endif //azure_storage_config_hh