COMP = gcc
#OPTIONS = -lm
OPTIONS_CC = -g -Wall

main: main.o arbre.o gestFichier.o foncParseur.o foncAnnexe.o api.o
	$(COMP) -o main main.o arbre.o gestFichier.o foncParseur.o foncAnnexe.o api.o $(OPTIONS)

main.o: main.c arbre.h gestFichier.h foncParseur.h foncAnnexe.h api.h
	$(COMP) -o main.o -c main.c $(OPTIONS_CC)

arbre.o: arbre.c arbre.h
	$(COMP) -o arbre.o -c arbre.c $(OPTIONS_CC)

gestFichier.o: gestFichier.c gestFichier.h
	$(COMP) -o gestFichier.o -c gestFichier.c $(OPTIONS_CC)

foncParseur.o: foncParseur.c foncParseur.h
	$(COMP) -o foncParseur.o -c foncParseur.c $(OPTIONS_CC)

foncAnnexe.o: foncAnnexe.c foncAnnexe.h
	$(COMP) -o foncAnnexe.o -c foncAnnexe.c $(OPTIONS_CC)

api.o: api.c api.h
	$(COMP) -o api.o -c api.c $(OPTIONS_CC)
