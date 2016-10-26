GCC = gcc -g
all: randTest.o
	$(GCC) randTest.c -o randomEx  

clean:
	rm *~
	rm *.o

run:
	./randomEx
