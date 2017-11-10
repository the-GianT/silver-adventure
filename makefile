all: work10.o
	gcc work10.o
work10.o: work10.c
	gcc -c work10.c
run: all
	./a.out
clean:
	rm *~
	rm *.o
