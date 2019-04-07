

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foncParseur.h"
#include "arbre.h"
#include "api.h"

noeud* rac = NULL;

void* getRootTree(){
  return rac;
}

_Token *searchTree(void *start,char *name){
  return chercherArbre(start, name);
}



char *getElementTag(void *node,int *len){
  *len = strlen(((noeud*)node)->field);
  return ((noeud*)node)->field;
}

char *getElementValue(void *node,int *len){
  *len = ((noeud*)node)->size;
  return ((noeud*)node)->value;
}

void purgeElement(_Token **r){
  viderRecherche(*r);
}

void purgeTree(void *root){
  viderArbre(root);
}

int parseur(char *req, int len){
  rac = parse(req, len);

  return rac != NULL;
}
