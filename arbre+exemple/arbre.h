


typedef struct noeud {
  char* value; // Chaine de caractère indiquand le nom de la cellule (ex : star-line)
  char* field; // pointeur sur le debut de la chaine de caractere
  int size; //taille de la chaine fieldValue
  struct noeud* fils; //Pointeur vers le fils (en dessous)
  struct noeud* frere; //Pointeur vers le frere (vers la droite)
} noeud;

noeud* crRacine(char* value, char* field, int size);

noeud* crCellule(char* value, char* field, int size);

noeud* crFils(noeud* pere, char* value, char* field, int size);

noeud* crFrere(noeud* frere, char* value, char* field, int size);

noeud* fils(noeud* pere);
noeud* frere(noeud* frere);

void affArbre(noeud* rac);
void affParSize(char* str, int size);
void affNoeud(noeud* cell);

void viderArbre(noeud* racine);
