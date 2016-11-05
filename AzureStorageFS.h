#ifndef azure_storage_fs_hh
#define azure_storage_fs_hh

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
#include "AzureStorageConfig.h"
#include "AzureStorageFSEnv.h"
#include "AzureStorageAdapter.h"

class AzureStorageFS
{
  private:
	static const char *_root;
    static void AbsPath(char dest[PATH_MAX], const char *path);

  public:
    static AzureStorageFSEnv *asEnv;
    static AzureStorageAdapter *asAdapter;

    static void set_rootdir(const char *path);
    static int wrap_getattr(const char *path, struct stat *statbuf);
    static int wrap_readlink(const char *path, char *link, size_t size);
    static int wrap_mknod(const char *path, mode_t mode, dev_t dev);
    static int wrap_mkdir(const char *path, mode_t mode);
    static int wrap_unlink(const char *path);
    static int wrap_rmdir(const char *path);
    static int wrap_symlink(const char *path, const char *link);
    static int wrap_rename(const char *path, const char *newpath);
    static int wrap_link(const char *path, const char *newpath);
    static int wrap_chmod(const char *path, mode_t mode);
    static int wrap_chown(const char *path, uid_t uid, gid_t gid);
    static int wrap_truncate(const char *path, off_t newSize);
    static int wrap_utime(const char *path, struct utimbuf *ubuf);
    static int wrap_open(const char *path, struct fuse_file_info *fileInfo);
    static int wrap_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo);
    static int wrap_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo);
    static int wrap_statfs(const char *path, struct statvfs *statInfo);
    static int wrap_flush(const char *path, struct fuse_file_info *fileInfo);
    static int wrap_release(const char *path, struct fuse_file_info *fileInfo);
    static int wrap_fsync(const char *path, int datasync, struct fuse_file_info *fi);
    static int wrap_setxattr(const char *path, const char *name, const char *value, size_t size, int flags);
    static int wrap_getxattr(const char *path, const char *name, char *value, size_t size);
    static int wrap_listxattr(const char *path, char *list, size_t size);
    static int wrap_removexattr(const char *path, const char *name);
    static int wrap_opendir(const char *path, struct fuse_file_info *fileInfo);
    static int wrap_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fileInfo);
    static int wrap_releasedir(const char *path, struct fuse_file_info *fileInfo);
    static int wrap_fsyncdir(const char *path, int datasync, struct fuse_file_info *fileInfo);
    static void *wrap_init(struct fuse_conn_info *conn);
};

#endif //azure_storage_fs_hh