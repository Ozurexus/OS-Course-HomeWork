echo "Maxim" > lofsdisk/file1.txt
echo "Piniagin" > lofsdisk/file2.txt
gcc -static ex2.c -o lofsdisk/ex2.out
sudo chroot lofsdisk /ex2.out > lofsdisk/ex2.txt
cd lofsdisk
mkdir bin
mkdir lib
mkdir lib64
cp /bin/bash ./bin/bash
cp /bin/ls ./bin/ls
cp /bin/echo ./bin/echo
cp /bin/cat ./bin/cat
echo "Output needed libraries"
ldd /bin/bash | egrep -o '/lib.*\.[0-9]'
ldd /bin/ls | egrep -o '/lib.*\.[0-9]'
ldd /bin/echo | egrep -o '/lib.*\.[0-9]'
ldd /bin/cat | egrep -o '/lib.*\.[0-9]'
cp /lib/x86_64-linux-gnu/libtinfo.so.6 ./lib/libtinfo.so.6
cp /lib64/ld-linux-x86-64.so.2 ./lib64/ld-linux-x86-64.so.2
cp /lib/x86_64-linux-gnu/libselinux.so.1 ./lib/libselinux.so.1
cp /lib/x86_64-linux-gnu/libc.so.6 ./lib/libc.so.6
cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 ./lib/libpcre2-8.so.0
sudo chroot . /ex2.out >> ex2.txt