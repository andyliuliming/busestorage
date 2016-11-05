#include <fuse.h>
#include <stdio.h>
#include <iostream>
#include <syslog.h>
#include "AzureStorageFS.h"
struct fuse_operations examplefs_oper;

int main(int argc, char *argv[])
{
    int fuse_stat;
    AzureStorageConfig *asConfig = new AzureStorageConfig("andliumysql1","POi29VbeHAAHBiXyj/gy+MYdR1CuWG5kthAlQZQfm0rmk9zNiMo3lXfJqFgOW8gZC77tsiBVXIRIL9NDMLPkuQ==");

    AzureStorageFS::asEnv = new AzureStorageFSEnv();

    AzureStorageFS::asAdapter = new AzureStorageAdapter(asConfig);
    
    openlog("fusestorage", LOG_CONS | LOG_PID, LOG_USER);

    examplefs_oper.getattr = AzureStorageFS::wrap_getattr;
    examplefs_oper.readlink = AzureStorageFS::wrap_readlink;
    examplefs_oper.getdir = NULL;
    examplefs_oper.mknod = AzureStorageFS::wrap_mknod;
    examplefs_oper.mkdir = AzureStorageFS::wrap_mkdir;
    examplefs_oper.unlink = AzureStorageFS::wrap_unlink;
    examplefs_oper.rmdir = AzureStorageFS::wrap_rmdir;
    examplefs_oper.symlink = AzureStorageFS::wrap_symlink;
    examplefs_oper.rename = AzureStorageFS::wrap_rename;
    examplefs_oper.link = AzureStorageFS::wrap_link;
    examplefs_oper.chmod = AzureStorageFS::wrap_chmod;
    examplefs_oper.chown = AzureStorageFS::wrap_chown;
    examplefs_oper.truncate = AzureStorageFS::wrap_truncate;
    examplefs_oper.utime = AzureStorageFS::wrap_utime;
    examplefs_oper.open = AzureStorageFS::wrap_open;
    examplefs_oper.read = AzureStorageFS::wrap_read;
    examplefs_oper.write = AzureStorageFS::wrap_write;
    examplefs_oper.statfs = AzureStorageFS::wrap_statfs;
    examplefs_oper.flush = AzureStorageFS::wrap_flush;
    examplefs_oper.release = AzureStorageFS::wrap_release;
    examplefs_oper.fsync = AzureStorageFS::wrap_fsync;
    examplefs_oper.setxattr = AzureStorageFS::wrap_setxattr;
    examplefs_oper.getxattr = AzureStorageFS::wrap_getxattr;
    examplefs_oper.listxattr = AzureStorageFS::wrap_listxattr;
    examplefs_oper.removexattr = AzureStorageFS::wrap_removexattr;
    examplefs_oper.opendir = AzureStorageFS::wrap_opendir;
    examplefs_oper.readdir = AzureStorageFS::wrap_readdir;
    examplefs_oper.releasedir = AzureStorageFS::wrap_releasedir;
    examplefs_oper.fsyncdir = AzureStorageFS::wrap_fsyncdir;
    examplefs_oper.init = AzureStorageFS::wrap_init;

    syslog(LOG_INFO, "try to mount!\n");
    fuse_stat = fuse_main(argc, argv, &examplefs_oper, NULL);

    syslog(LOG_INFO, "fuse_main returned %d\n", fuse_stat);

    return fuse_stat;
}
