#include "AzureStorageBlockDevice.h"
#include "PathUtils.h"
#include <syslog.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
AzureStorageFSEnv *AzureStorageBlockDevice::asEnv = NULL;
PageBlobAdapter *AzureStorageBlockDevice::asAdapter = NULL;
int AzureStorageBlockDevice::xmpl_debug = 1;
void *AzureStorageBlockDevice::data = NULL;