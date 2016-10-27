all: randTest.o
	gcc randTest.c -o randomEx  

clean:
	rm *.o
	rm randomEx

run:
	./randomEx
