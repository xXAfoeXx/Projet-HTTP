#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foncParseur.h"
#include "arbre.h"
#include "foncAnnexe.h"



int estToken (char* c)
{
	return 1;
}


int cookie_octet (char c)
{
	return 	(c == 0x21 || (c >= 0x23 && c <= 0x2B) || (c >= 0x2D && c <= 0x3A) || (c >= 0x3C && c <= 0x5B) || (c >= 0x5D && c <= 0x7E));
}

int cookie_parse(noeud* pere)
{
	char* c = pere->value;
	char* start_name = NULL;
	char* start_value = NULL;

	int dquote = 0;
	int size_name = 0;
	int size_value = 0;

	int i = 0;					// utilisé uniquement juste en dessous
	while (OWS(c, &i))					c += i;

	while (*c != '\n')
	{
		size_name = 0;
		size_value = 0;
		start_name = c;
		dquote = 0;

		if (!estToken(c))		return -1;

		while (*c != '=' && *c != '\n')
		{
			c++;
			size_name++;
		}
		c++;

		start_value = c;
		while (*c != ';' && *c != '\n')
		{
			if (*c == '\"')		dquote ++;

/*
			else if (*c == ' ' && *c == '\t')					// enleve les SP ou HTAB en fin de ligne si il s'agit du dernier cookie string
			{													// le soucis, c'est que ça marche pas
				while (*c == ' ' && *c == '\t')		c++;		// c'est là que quand on pointe vers un SP ou un HTAB, ça rentre pas alors que ça devrait
				if (*c == '\n')			return 0;
				else 	return -1;
			}
*/
			else if (!cookie_octet(*c))				return -1;
			c++;
			size_value ++;
		}

		if (dquote != 0 && dquote != 2) 		return -1;

		crFils( crFils (pere, start_name, "cookie name", size_name) , start_value, "cookie value", size_value);

		if (*c == ';' && *(c+1) == ' ')		c += 2;
	}
	return 0;
}

// Comme je t'avais dit, expect_parse n'a pas été débuggé

int expect_parse(noeud* pere)
{
	char* start = pere->value;
	int i = 0;
	while (OWS(start, &i))					start += i;
	if(! strncmp(start, "100_continue", strlen("100_continue"))) 		return -1;
	start += strlen("100_continue");
	while (OWS(start, &i))					start += i;
	if (*start == '\r' && *(start + 1) == '\n') 		return 0;
	return -1;
}


// J'ai pas touché à ce qui est en dessous, j'ai copié collé pour que ça compile

int OWS(char* p, int* i){
  int tmp = *i;
  while(p[*i] == ' ' || p[*i] == '\t'){
    (*i)++;
  }
  //vrai = changement
  return tmp != *i; // renvoi vrai ou faux selon s'il y a eu modification ou non
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





int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
