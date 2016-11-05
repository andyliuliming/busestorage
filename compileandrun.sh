#! /bin/sh
cmake .
make clean
make

killall fusestorage
./bin/fusestorage ../testfs

cat ../testfs/abc/ssladmin