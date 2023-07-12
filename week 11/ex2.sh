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
cp /bin/cat ./bin/cats
ldd /bin/bash | egrep -o '/lib.*\.[0-9]'
for i in $(ldd /bin/bash | egrep -o '/lib.*\.[0-9]'); do cp --parents $i .; done
ldd /bin/ls | egrep -o '/lib.*\.[0-9]'
for i in $(ldd /bin/ls | egrep -o '/lib.*\.[0-9]'); do cp --parents $i .; done
ldd /bin/echo | egrep -o '/lib.*\.[0-9]'
for i in $(ldd /bin/echo | egrep -o '/lib.*\.[0-9]'); do cp --parents $i .; done
ldd /bin/cat | egrep -o '/lib.*\.[0-9]'
for i in $(ldd /bin/cat | egrep -o '/lib.*\.[0-9]'); do cp --parents $i .; done
./ex2.out >> ex2.txt
