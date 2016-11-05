#include "AzureStorageFS.h"
#include "PathUtils.h"
#include <syslog.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
AzureStorageFSEnv *AzureStorageFS::asEnv = NULL;
AzureStorageAdapter *AzureStorageFS::asAdapter = NULL;
int AzureStorageFS::xmpl_debug = 1;
void *AzureStorageFS::data = NULL;