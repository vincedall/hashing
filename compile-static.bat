gcc -std=c99 -m64 -Wall -O3 -static -nostdlib -ffreestanding -c -D STATIC source\hash.c -oobjects\hash.o
ar rcs hash.lib objects\hash.o
pause