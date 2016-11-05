#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include "AzureStorageFS.h"
#include "buse.h"

static void *data;
static int xmpl_debug = 1;

static int xmp_read(void *buf, u_int32_t len, u_int64_t offset, void *userdata)
{
  if (*(int *)userdata)
    fprintf(stderr, "R - %lu, %u\n", offset, len);
  memcpy(buf, (char *)data + offset, len);
  return 0;
}

static int xmp_write(const void *buf, u_int32_t len, u_int64_t offset, void *userdata)
{
  if (*(int *)userdata)
    fprintf(stderr, "W - %lu, %u\n", offset, len);
  memcpy((char *)data + offset, buf, len);
  return 0;
}

static void xmp_disc(void *userdata)
{
  (void)(userdata);
  fprintf(stderr, "Received a disconnect request.\n");
}

static int xmp_flush(void *userdata)
{
  (void)(userdata);
  fprintf(stderr, "Received a flush request.\n");
  return 0;
}

static int xmp_trim(u_int64_t from, u_int32_t len, void *userdata)
{
  (void)(userdata);
  fprintf(stderr, "T - %lu, %u\n", from, len);
  return 0;
}


static struct buse_operations aop = {
  .read = xmp_read,
  .write = xmp_write,
  .disc = xmp_disc,
  .flush = xmp_flush,
  .trim = xmp_trim,
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


  data = malloc(aop.size);

  return buse_main(argv[1], &aop, (void *)&xmpl_debug);
}
