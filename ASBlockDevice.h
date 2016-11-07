#ifndef as_block_device_hh
#define as_block_device_hh

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fuse.h>
#include <libgen.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include "ASConfig.h"
#include "ASFSEnv.h"
#include "PageBlobAdapter.h"

class ASBlockDevice
{
private:
public:
  static ASFSEnv *asEnv;
  static PageBlobAdapter *asAdapter;

  static int xmpl_debug;

  static int xmp_read(void *buf, u_int32_t len, u_int64_t offset, void *userdata)
  {
    if (*(int *)userdata)
    {
      fprintf(stderr, "R - %lu, %u\n", offset, len);
    }
    asAdapter->read((char*)buf, len, offset);

    //memcpy(buf, (char *)data + offset, len);
    return 0;
  }

  static int xmp_write(const void *buf, u_int32_t len, u_int64_t offset, void *userdata)
  {
    if (*(int *)userdata)
    {
      fprintf(stderr, "W - %lu, %u\n", offset, len);
    }
    asAdapter->write((char*)buf, len, offset);
    //memcpy((char *)data + offset, buf, len);
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
};

#endif //as_block_device_hh