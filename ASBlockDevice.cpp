#include "ASBlockDevice.h"
#include "PathUtils.h"
#include "PageBlobAdapter.h"
#include <syslog.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
ASFSEnv *ASBlockDevice::asEnv = NULL;
PageBlobAdapter *ASBlockDevice::asAdapter = NULL;
int ASBlockDevice::xmpl_debug = 1;