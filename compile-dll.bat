gcc -O3 -c -D BUILD -D WINDOWS source\hash.c -oobjects\hash.o
ld -s -shared objects\hash.o -ohash.dll
pause