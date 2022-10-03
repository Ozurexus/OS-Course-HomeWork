gcc -pthread ex3.c -o ex && (time ./ex 10000000 1) 2> ex3.txt
gcc -pthread ex3.c -o ex && (time ./ex 10000000 2) 2>> ex3.txt
gcc -pthread ex3.c -o ex && (time ./ex 10000000 4) 2>> ex3.txt
gcc -pthread ex3.c -o ex && (time ./ex 10000000 10) 2>> ex3.txt
gcc -pthread ex3.c -o ex && (time ./ex 10000000 100) 2>> ex3.txt
