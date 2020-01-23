all: quadinfo.c 
        gcc -g -Wall -o quadinfo quadinfo.c -lm

  clean: 
        $(RM) quadinfo
