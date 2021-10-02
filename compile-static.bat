gcc -O3 -c -D STATIC source\hash.c -oobjects\hash.o
ar rcs hash.lib objects\hash.o
pause