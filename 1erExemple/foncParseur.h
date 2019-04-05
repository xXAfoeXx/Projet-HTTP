
#ifndef FONCPARSEUR_H
#define FONCPARSEUR_H
#include "arbre.h"

noeud* parse(char* str, int taille);

noeud* http_message_parse(noeud* pere);

#endif
