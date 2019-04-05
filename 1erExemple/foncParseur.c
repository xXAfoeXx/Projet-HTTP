
#include <stdio.h>
#include <stdlib.h>
#include "foncParseur.h"
#include "arbre.h"

noeud* parse(char* str, int taille){
  noeud* rac = crRacine(str, "HTTP-message", taille);
  http_message_parse(rac);

  return rac;
}

noeud* http_message_parse(noeud* pere){

  int start = 0;
  int first = 1;


  for(int i = 0; i < pere->size; i++){
    if(pere->value[i] == '\n'){
      if (first) {
         crFils(pere, pere->value+start, "start-line", i-start);
         first = 0;
      }
      else crFils(pere, pere->value+start, "header-field", i-start);
      start = i+1;
    }
  }

  return pere;
}
