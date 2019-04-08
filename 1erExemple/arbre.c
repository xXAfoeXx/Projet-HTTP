
/*Gestion de l'arbre */

#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"
#include <string.h>



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

  char* str2 = strParSize(str, size);
  printf("%s", str2);

  free(str2);

}

char* strParSize(char* str, int size){

  char* str2 = malloc((size+1)*sizeof(char));
  for(int i = 0; i < size; i++){
    str2[i] = str[i];
  }
  str2[size] = '\0';

  return str2;
}

void affNoeud(noeud* cell){
  printf("%s:", cell->field);
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


_Token* chercherArbre(noeud* rac, char* nom){
  noeud* courant = rac;
  _Token* tok = NULL;
  _Token* tokTmp = NULL;
  _Token* last = NULL;

  //On regarde tous les freres
  while (courant != NULL) {
    //Construction a l'envers
    if(!strcmp(courant->field, nom)){
      tok = ajoutTok(courant);
      if (last == NULL) last = tok;
      tok->next = tokTmp;
      tokTmp = tok;
    }
    courant = courant->frere;
  }

  //Puis on regarde le fils et les freres de ces fils

  courant = rac;
  // Pour chaque frere

  while (courant != NULL) {
    // On regarde le fils (si y en a un)
    if(courant->fils != NULL){
      //On ajoute a la fin de la liste
      if(last != NULL) last->next = chercherArbre(courant->fils, nom);
      else if(tok == NULL) tok = chercherArbre(courant->fils, nom);
      //Et on met a jour last
      while(last != NULL && last->next != NULL){
        last = last->next;
      }
    }
    courant = courant->frere; // On passe au frere suivant
  }

  return tok;
}

_Token* ajoutTok(noeud* n){
  _Token* tok = malloc(sizeof(_Token));
  tok->node = n;
  tok->next = NULL;

  return tok;

}

void afficherTok(_Token* tok){
  int i = 0;

  _Token* courant = tok;
  printf("---Recherche---\n");
  //Affichage a l'envers
  while(courant != NULL){
    //affNoeud(courant->node);
    courant = courant->next;
    i++;
  }

  courant = tok;
  affRec(courant);

  printf("%d resultat(s)\n", i);
}

void affRec(_Token* tok){
  if(tok != NULL){
    affRec(tok->next);
    affNoeud(tok->node);
  }
}

void viderRecherche(_Token* tok){

  if(tok == NULL){

  }
  else{
    viderRecherche(tok->next);
    free(tok);
  }

}
