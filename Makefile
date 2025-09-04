

CC=gcc 
RM = rm -f 

default: all

all : main

main : src/main.c
	$(CC) src/main.c -o main

clean : 
	RM main

