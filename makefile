
all: txtfind isort

main.o: myLib.o main.c 
	gcc -Wall -g -c main.c
myLib.o: myLib.c myLib.h 
	gcc -Wall -g -fPIC -c myLib.c
myLib.a: myLib.o 
	ar -rcs myLib.a myLib.o
txtfind: main.o myLib.a
	gcc -Wall -g -o txtfind main.o myLib.a
isort.o: isort.c 
	gcc -Wall -g -c isort.c
.PHONY: clean all

clean:
	rm *.o *.a *.so txtfind isort.o isort 