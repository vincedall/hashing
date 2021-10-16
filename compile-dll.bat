gcc -std=c99 -m64 -Wall -O3 -shared -D BUILD -D WINDOWS source\hash.c -ohash.dll
pause