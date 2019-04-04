COMP = gcc
#OPTIONS = -lm
OPTIONS_CC = -g -Wall

main: main.o arbre.o
	$(COMP) -o main main.o arbre.o $(OPTIONS)

main.o: main.c arbre.h
	$(COMP) -o main.o -c main.c $(OPTIONS_CC)

arbre.o: arbre.c arbre.h
	$(COMP) -o arbre.o -c arbre.c $(OPTIONS_CC)
