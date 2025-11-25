# LBYARCH-MCO2
Repository for LBYARCH MCO2

To run:
```
nasm -f win64 asmsdot.asm
gcc -c main.c -o main.obj -m64
gcc sdot.c main.obj asmsdot.obj -o main.exe -m64
main.exe
```