#include "ASBlockDevice.h"
#include "PathUtils.h"
#include "SinglePageBlobAdapter.h"
#include <syslog.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
ASFSEnv *ASBlockDevice::asEnv = NULL;
SinglePageBlobAdapter *ASBlockDevice::asAdapter = NULL;
int ASBlockDevice::xmpl_debug = 1;