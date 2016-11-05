#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include "AzureStorageFS.h"
#include "buse.h"




static struct buse_operations aop = {
  .read = AzureStorageFS::xmp_read,
  .write = AzureStorageFS::xmp_write,
  .disc = AzureStorageFS::xmp_disc,
  .flush = AzureStorageFS::xmp_flush,
  .trim = AzureStorageFS::xmp_trim,
  .size = 128 * 1024 * 1024,
};

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, 
        "Usage:\n"
        "  %s /dev/nbd0\n"
        "Don't forget to load nbd kernel module (`modprobe nbd`) and\n"
        "run example from root.\n", argv[0]);
    return 1;
  }

  AzureStorageConfig *asConfig = new AzureStorageConfig("andliumysql1","POi29VbeHAAHBiXyj/gy+MYdR1CuWG5kthAlQZQfm0rmk9zNiMo3lXfJqFgOW8gZC77tsiBVXIRIL9NDMLPkuQ==");

  AzureStorageFS::asEnv = new AzureStorageFSEnv();

  AzureStorageFS::asAdapter = new AzureStorageAdapter(asConfig);
  
  openlog("fusestorage", LOG_CONS | LOG_PID, LOG_USER);


  AzureStorageFS::data = malloc(aop.size);

  return buse_main(argv[1], &aop, (void *)&AzureStorageFS::xmpl_debug);
}
