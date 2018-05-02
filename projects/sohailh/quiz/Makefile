CFLAGS = -Wall -fpic -coverage -lm

testme: testme.c
	gcc -o testme -g testme.c $(CFLAGS) 
	./testme

all: testme.c
	gcc -o testme -g testme.c $(CFLAGS)
	./testme

clean:
	rm -f *.o  *.gcov *.gcda *.gcno *.so *.out *.exe testme
