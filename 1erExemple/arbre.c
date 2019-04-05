
/*Gestion de l'arbre */

#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"



noeud* crCellule(char* value, char* field, int size){
  // Creation d'une cellule
  noeud* cell = malloc(sizeof(noeud));
  cell->value = value;
  cell->field = field;
  cell->size = size;
  cell->fils = NULL;
  cell->frere = NULL;

  return cell;
}

noeud* crRacine(char* value, char* field, int size){
  return crCellule(value, field, size);
}

noeud* crFils(noeud* pere, char* value, char* field, int size){
  // Si le pere a deja un fils on va ajouter un frere au fils
  if(pere->fils != NULL){
    return crFrere(pere->fils, value, field, size); // On retourne un pointeur sur l'element cree
  }
  // Sinon on ajoute le fils
  else{
    pere->fils = crCellule(value, field, size);
  }

  return pere->fils; // On retourne un pointeur sur ce qui a ete cree
}

noeud* crFrere(noeud* frere, char* value, char* field, int size){
  //Si le noeud a deja un frere, on cherche le suivant
  //Sous une forme recursive
  if (frere->frere != NULL) {
    return crFrere(frere->frere, value, field, size); // On retourne un pointeur sur l'element cree
  }
  // Sinon si il n'a pas de frere, on le lui ajoute
  else{
    frere->frere = crCellule(value, field, size);
  }

  return frere->frere; // On retourne un pointeur sur l'element cree

}

// On reviendra sur l'utilite de ces fonctions ?
noeud* fils(noeud* pere){
  return pere->fils;
}

noeud* frere(noeud* frere){
  return frere->frere;
}


// On affiche l'arbre

void affArbre(noeud* rac){
  noeud* courant = rac;

  //On affiche tous les freres
  while (courant != NULL) {
    affNoeud(courant);
    courant = courant->frere;
  }

  //Puis on affiche le fils et les freres de ces fils
  //2 boucles pour avoir un affichage comprehensible
  courant = rac;
  // Pour chaque frere

  while (courant != NULL) {
    // On affiche le fils (si y en a un)
    if(courant->fils != NULL){
      printf("\n");
      printf("%% %s %%: \n", courant->field);
      printf("{\n");
      affArbre(courant->fils);
      printf("}\n");
    }
    courant = courant->frere; // On passe au frere suivant
  }
}

void affParSize(char* str, int size){

  for(int i = 0; i < size; i++){
    printf("%c", str[i]);
  }

}

void affNoeud(noeud* cell){
  printf("%% %s %%: ", cell->field);
  affParSize(cell->value, cell->size);
  printf("\n");
}


void viderArbre(noeud* racine){
  // Fonction pour vider un arbre

  // Si il y a un frere on vide le frere
  if(racine->frere != NULL){
    viderArbre(racine->frere);
  }
  //Pareil si il y a un fils
  else if(racine->fils != NULL){
    viderArbre(racine->fils);
  }
  //Un fois le fils et le frere vide, on libere le noeud
  free(racine);
}
