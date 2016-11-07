#ifndef cloud_page_blob_builder_hh
#define cloud_page_blob_builder_hh
#include "ABSException.h"
#include "was/storage_account.h"
#include "was/blob.h"
#include "FilePath.h"
#include "ASConfig.h"
class CloudPageBlobBuilder
{
  public:
    azure::storage::cloud_page_blob build_cloud_page_blob(ASConfig *config, FilePath *filePath) const
    {
        std::string connectionStr = std::string("DefaultEndpointsProtocol=http;EndpointSuffix=core.chinacloudapi.cn;AccountName=") 
            + config->storageAccountName + ";AccountKey=" + config->storageAccountKey;
        utility::string_t storage_connection_string(_XPLATSTR(connectionStr));
        auto storage_account = azure::storage::cloud_storage_account::parse(storage_connection_string);

        azure::storage::cloud_blob_client blob_client = storage_account.create_cloud_blob_client();
        azure::storage::cloud_blob_container container = blob_client.get_container_reference(_XPLATSTR(filePath->directory));
        if (container.exists())
        {
            azure::storage::cloud_page_blob blob1 = container.get_page_blob_reference(_XPLATSTR(filePath->fileName));
            return blob1;
        }
        else
        {
            throw ABSException();
        }
    }
};
#endif 