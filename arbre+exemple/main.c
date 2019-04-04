#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

void decoupeLettre(noeud* pere);

int main(int argc, char const *argv[]) {

  char str[] = "Bonjour je m'appelle Arthur";

  noeud* rac = crRacine(str, "Phrase", 27);

  noeud* fils = crFils(rac, str, "Intro", 7);
  noeud* fils2 = crFils(rac, str+8, "Sujet", 2);
  decoupeLettre(crFrere(rac->fils, str+11, "Verbe", 9));
  decoupeLettre(crFrere(fils, str+21, "Prenom", 6));


  decoupeLettre(rac->fils);
  decoupeLettre(fils2);

  affNoeud(fils2->fils->frere);

  printf("--------------Affichage------------\n");
  affArbre(rac);

  viderArbre(rac);

  return 0;
}

void decoupeLettre(noeud* pere){

  for(int i = 0; i < pere->size; i++){
    crFils(pere, (pere->value)+i, "Lettre", 1); // Cree un fils de pour une lettre

  }

}
