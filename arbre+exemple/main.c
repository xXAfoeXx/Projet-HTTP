#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

void decoupeLettre(noeud* pere);

int main(int argc, char const *argv[]) {

  char str[] = "Bonjour je m'appelle Arthur"; //Chaine = requete

  noeud* rac = crRacine(str, "Phrase", 27); // On cree la racine avec la requete

  noeud* fils = crFils(rac, str, "Intro", 7); // On recupere un pointeur pointant sur le nouveau fils de "rac"
  noeud* fils2 = crFils(rac, str+8, "Sujet", 2); // Idem mais on remarque que si on utilise encore crFils, cela cree un frere du 1er fils
  decoupeLettre(crFrere(rac->fils, str+11, "Verbe", 9)); // Plusieurs operations : on cree le frere et on decoupe directement en lettre
  decoupeLettre(crFrere(fils, str+21, "Prenom", 6)); // Idem


  decoupeLettre(rac->fils); // On peut decouper en lettre a part ATTENTION ici c'est le fils de rac sous entendu celui de la structure
  decoupeLettre(fils2); // Avec une autre notation 

  affNoeud(fils2->fils->frere); // On peut afficher un noeud independement du reste ; ici on affiche la lettre e

  printf("--------------Affichage------------\n");
  affArbre(rac); // Affiche l'arbre entier avec la structure de donnee

  viderArbre(rac); // Permet de vider l'arbre

  return 0;
}

void decoupeLettre(noeud* pere){ // Fonction decoupant une cellule en lettre

  for(int i = 0; i < pere->size; i++){
    crFils(pere, (pere->value)+i, "Lettre", 1); // Cree un fils pour une lettre

  }

}
