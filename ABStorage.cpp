#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include "SinglePageBlobAdapter.h"
#include "Raid0PageBlobAdapter.h"
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
            "run from root.\n",
            argv[0]);
    return 1;
  }

  openlog("abstorage", LOG_CONS | LOG_PID, LOG_USER);

  ASConfig *asConfig = new ASConfig("andliumysql1", "POi29VbeHAAHBiXyj/gy+MYdR1CuWG5kthAlQZQfm0rmk9zNiMo3lXfJqFgOW8gZC77tsiBVXIRIL9NDMLPkuQ==");

  FilePath *disk1Path = new FilePath();
  disk1Path->directory = new char[strlen("abc") + 1];
  strcpy(disk1Path->directory, "abc");
  disk1Path->fileName = new char[strlen("testdisk.vhd") + 1];
  strcpy(disk1Path->fileName, "testdisk.vhd");

  FilePath *disk2Path = new FilePath();
  disk2Path->directory = new char[strlen("abc1") + 1];
  strcpy(disk2Path->directory, "abc1");
  disk2Path->fileName = new char[strlen("testdisk.vhd") + 1];
  strcpy(disk2Path->fileName, "testdisk.vhd");

  CloudPageBlobBuilder cloudPageBlobBuilder;
  azure::storage::cloud_page_blob pageBlob1 = cloudPageBlobBuilder.build_cloud_page_blob(asConfig, disk1Path);
  azure::storage::cloud_page_blob pageBlob2 = cloudPageBlobBuilder.build_cloud_page_blob(asConfig, disk2Path);

  ASBlockDevice::asAdapter = new SinglePageBlobAdapter(pageBlob1);

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
  return buse_main(argv[1], &aop, (void *)&ASBlockDevice::xmpl_debug);
}
