#include "struc.h"


int addNoeud(noeud** abr,char* field,char* fieldvalue,int etage){
  noeud* monNoeud = NULL;
  if(*abr != NULL){
    monNoeud = *abr;
    if (monNoeud->etage == etage) {
        while (monNoeud->frere != NULL) monNoeud = monNoeud->frere;
        monNoeud->frere = creerNoeud(field,fieldvalue,etage);

    }
    else if (/* condition */) {
      /* code */
    }
  }
}

noeud* creerNoeud(char* field,char* fieldvalue,int etage){
  noeud* nouvelelem = NULL;
  if ((nouvelelem = malloc(sizeof(noeud))) == NULL){
    printf("ERREUR MEMOIRE\n");
    return NULL;
  }
  nouvelelem->field = field;

  return nouvelelem;
}

void afficherAbr(*noeud){

}

int supprimerNoeud(){

}
