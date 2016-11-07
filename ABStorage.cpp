#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include "PageBlobAdapter.h"
#include "CloudPageBlobBuilder.h"
#include "ASBlockDevice.h"
#include "PathUtils.h"
#include "buse.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr,
            "Usage:\n"
            "  %s /dev/nbd0\n"
            "Don't forget to load nbd kernel module (`modprobe nbd`) and\n"
            "run example from root.\n",
            argv[0]);
    return 1;
  }

  openlog("fusestorage", LOG_CONS | LOG_PID, LOG_USER);

  ASConfig *asConfig = new ASConfig("andliumysql1", "POi29VbeHAAHBiXyj/gy+MYdR1CuWG5kthAlQZQfm0rmk9zNiMo3lXfJqFgOW8gZC77tsiBVXIRIL9NDMLPkuQ==");
  FilePath *filePath = new FilePath();

  filePath->directory = new char[strlen("abc") + 1];
  strcpy(filePath->directory, "abc");

  filePath->fileName = new char[strlen("testdisk.vhd") + 1];
  strcpy(filePath->fileName, "testdisk.vhd");

  ASBlockDevice::asEnv = new ASFSEnv();

  CloudPageBlobBuilder cloudPageBlobBuilder;
  azure::storage::cloud_page_blob pageBlob = cloudPageBlobBuilder.build_cloud_page_blob(asConfig, filePath);
  ASBlockDevice::asAdapter = new PageBlobAdapter(pageBlob);

  uint64_t size = ASBlockDevice::asAdapter->getSize();

  syslog(LOG_INFO, "page blob size is %lu\n", size);

  static struct buse_operations aop = {
      .read = ASBlockDevice::xmp_read,
      .write = ASBlockDevice::xmp_write,
      .disc = ASBlockDevice::xmp_disc,
      .flush = ASBlockDevice::xmp_flush,
      .trim = ASBlockDevice::xmp_trim,
      .size = size,
  };
  // get size of the blob

  //AzureStorageFS::data = malloc(aop.size);

  //return buse_main(argv[1], &aop, (void *)&AzureStorageFS::xmpl_debug);
  return 0;
}
