
#include <stdio.h>
#include <stdlib.h>
#include "gestFichier.h"

char* chargerFichier(char* nomFichier){
  int taille = tailleFichier(nomFichier);
  int i = 0;
  char c;
  FILE* fichier = fopen(nomFichier, "r");

  char* msg = malloc(taille*sizeof(char));

  if(fichier != NULL){

    do{
      c = fgetc(fichier);
      msg[i] = c;
      i++;
    }while(i < taille && c != EOF);

    fclose(fichier);
  }
  else{
    printf("Erreur fichier\n");
    exit(1);
  }

  return msg;

}

int tailleFichier(char* nomFichier){

    FILE* fichier = fopen(nomFichier, "r");
    int taille = 0;
    char c;

    if (fichier != NULL) {

      do{
        c = fgetc(fichier);
        taille++;
      }while(c != EOF);

      taille--; //caractère EOF

      fclose(fichier);
    }
    else{
      printf("Erreur fichier\n");
      exit(1);
    }


    return taille;

}
