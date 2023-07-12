link /mnt/c/Users/hp/Desktop/Progs/week1/file.txt _ex2.txt
find /mnt/c/Users/hp/Desktop/Progs/week1 -inum 2533274790627673 >> ex2.txt
find /mnt/c/Users/hp/Desktop/Progs/week1 -inum 2533274790627673 -exec rm {} \;