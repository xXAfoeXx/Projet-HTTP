typedef struct noeud {
  char* fieldValue;
  char* field;
  int etage;
  noeud* fils;
  noeud* frere;
  int taille; //taille de la chaine fieldValue
} noeud;
