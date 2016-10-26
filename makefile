all: randTest.c
	gcc randTest.c -o randomEx  

clean:
	rm *~
	rm *.o

run:
	./randomEx
