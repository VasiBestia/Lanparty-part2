build:
	gcc fisiere.c/*.c main.c -I./fisiere.h -o main

clean:
	del -f main
