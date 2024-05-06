
all: grille.o main.o
	gcc grille.o main.o -o main

grille.o: grille.c grille.h
	gcc -c -Wall grille.c

main.o: main.c grille.h
	gcc -c -Wall main.c


clean : 
	rm -f *.o main
		