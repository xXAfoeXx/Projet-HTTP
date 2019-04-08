
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foncParseur.h"
#include "arbre.h"
#include "foncAnnexe.h"

noeud* parse(char* str, int taille){
  noeud* rac = crRacine(str, "HTTP-message", taille);
  http_message_parse(rac);

  return rac;
}


noeud* http_message_parse(noeud* pere){

  int start = 0;
  int first = 1;

  for(int i = 0; i < pere->size; i++){
    //Si on tombe sur un retour a la ligne et qu'il n'y a pas d'espace
    if(pere->value[i] == '\n' && pere->value[i-1] != '\n' && pere->value[i-2] != '\n' && pere->value[i+1] != ' '){
      if (first) {
         start_line_parse(crFils(pere, pere->value+start, "start-line", i-start));
         first = 0;
      }
      else header_field_parse(crFils(pere, pere->value+start, "header-field", i-start)); //-1 pour enlever le retour à la ligne

      start = i+1; //+1 pour le retour a la ligne supprime
    }
  }

  return pere;
}

noeud* start_line_parse(noeud* pere){

  int i = 0;
  char* str;

  while(i < pere->size && pere->value[i] != ' '){
    i++;
  }

  str = strParSize(pere->value, i);

  // Pour ce projet on ne considere que les requetes
  // Ainsi, si on tombe sur autre chose qu'un GET
  //On quitte de suite le programme

  if(!strcmp(str, "GET")){
    request_line_parse(crFils(pere, pere->value, "request-line", pere->size));
    free(str);
  }
  else{
    printf("Cette requete n'en est pas une : %s\n", str);
    free(str);
    exit(3);
  }


  return pere;
}


noeud* request_line_parse(noeud* pere){

  int sp = 0;
  int start = 0;

  for(int i = 0; i < pere->size; i++){
    if(pere->value[i] == ' ' || i == pere->size-1){
      if(sp == 0){ // Au premier espace
        crFils(pere, pere->value+start, "method", i-start);
        start = i + 1;
        sp++;
      }
      else if(sp == 1){ // Au 2e
        request_target_parse(crFils(pere, pere->value+start, "request-target", i-start));
        start = i + 1;
        sp++;
      }
      else if(sp == 2){ // Au 3e
        crFils(pere, pere->value+start, "HTTP-version", i-start);
        start = i + 1;
        sp++;
      }
    }
  }

  return pere;
}

noeud* request_target_parse(noeud* pere){

  int i = 0;

  //On identifie le type de requete cible via leur synthax
  if (pere->value[0] == '/') {
    crFils(pere, pere->value, "absolute-path", pere->size);
  }
  else if (pere->value[0] == '*') {
    crFils(pere, pere->value, "asterisk-form", pere->size);
  }
  else{
    while(i < pere->size && (pere->value[i] != ':' || pere->value[i] != '@')){
      i++;
    }
    if (pere->value[i] == ':') {
      crFils(pere, pere->value, "absolute-URI", pere->size);
    }
    else if (pere->value[i] == '@') {
      crFils(pere, pere->value, "authority", pere->size);
    }
  }

  return pere;
}



noeud* header_field_parse(noeud* pere){
  char* hn;
  noeud* fils;
  for(int i = 0; i < pere->size; i++){
    if(pere->value[i] == ':'){
      hn = strParSize(pere->value, i);//On recupere la chaine en fonction du pointeur et de la taille.
      hn = enMinuscule(hn);//Conversion en minuscule pour ne pas se soucier de la casse

      //+1 pour le ':'
      i++;
      OWS(pere->value, &i);//elimine les OWS entre : et la valeur
      fils = crFils(pere, pere->value+i, hn, pere->size-i);

      if(!strcmp(hn, "connection")){
        connection_parse(fils);
      }
      else if(!strcmp(hn, "user-agent")){
        user_agent_parse(fils);
      }
      else if(!strcmp(hn, "accept")){
        accept_parse(fils);
      }
      else if(!strcmp(hn, "accept-language")){
        accept_language_parse(fils);
      }
      else if(!strcmp(hn, "accept-encoding")){
        accept_encoding_parse(fils);
      }
      else if(!strcmp(hn, "content-length")){
        content_length_parse(fils);
      }
      //free(hn);
      //Besoin ici de garder le pointeur, probleme de memoire ?
      return pere;
    }
  }

  affNoeud(pere);
  printf("Erreur header-name\n");
  exit(3);
}

noeud* connection_parse(noeud* pere){
  int i = 0;
  int start = 0;
  //Manipulation si le champ commence par "," OWS
  if(pere->value[i] == ','){
    i += 1;
    OWS(pere->value, &i);
  }
  start = i;

  while(i < pere->size){

    //Si on est en fin de ligne ou qu'il y a un separateur on cree un nv fils
    if(i == pere->size-1 || pere->value[i] == ','){
      crFils(pere, pere->value+start, "connection_option", i-start);
      start = i + 1; // + 1 pour passer la virgule
      OWS(pere->value, &start);
    }

    i++;
  }
  return pere;
}

noeud* content_length_parse(noeud* pere){




  return pere;
}

noeud* user_agent_parse(noeud* pere){

  int start = 0;
  int com = 0;
  int i = 0;

  while(i < pere->size){

    // Separateur : ' ' ou tab ou fin de ligne sauf si dans dans un commentaire
    if(com == 0 && (pere->value[i] == ' ' || pere->value[i] == '\t' || i == pere->size-1)){

      //Si ce n'est pas un commentaire, ca ne commence pas par une parenthese
      if(pere->value[start] != '('){
        crFils(pere, pere->value+start, "product", i-start);
      }
      else{
        crFils(pere, pere->value+start, "comment", i-start);
      }

      //mecanisme du fait que le separateur est un espace
      if(OWS(pere->value, &i)){
        start = i;
      }
      else{
        start = i + 1; // + 1 pour passer le caractere de separation
      }
    }

    if(pere->value[i] == '(') com += 1;
    else if(pere->value[i] == ')') com -= 1;

    i++;
  }

  return pere;
}

noeud* accept_parse(noeud* pere){

  int i = 0;
  int start = 0;
  int pvirg = 0; // Pour savoir si ensuite on cree un media range ou accept param

  if(pere->value[i] == ','){
    i+=1;
    start+=1;
  }

  while(i < pere->size){
    //Si c'est un ; de seperation de media range, accept param
    if(pere->value[i] == ';' && (pere->value[i+1] == 'q' || ( pere->value[i+1] == ' ' && pere->value[i+2] == 'q')))
    {
      crFils(pere, pere->value+start, "media-range", i-start);
      start = i + 1;
      pvirg = 1;
    }

    if (pere->value[i] == ',' || i == pere->size-1) {
      if(!pvirg) crFils(pere, pere->value+start, "media-range", i-start);
      else crFils(pere, pere->value+start, "accept-param", i-start);
      start = i + 1;
      pvirg = 0;
    }
    i++;
  }


  return pere;
}

noeud* accept_language_parse(noeud* pere){

  int i = 0;
  int start = 0;
  int pvirg = 0; // Pour savoir si ensuite on cree un media range ou accept param

  // avancer jusqu'a la premiere occurence
  while(pere->value[i] == ','){
    i+=1;
    OWS(pere->value, &i);
  }

  start = i;

  while(i < pere->size){
    //Si c'est un ; de seperation
    if(pere->value[i] == ';')
    {
      crFils(pere, pere->value+start, "language-range", i-start);
      start = i + 1;
      pvirg = 1;
    }

    if (pere->value[i] == ',' || i == pere->size-1) {
      if(!pvirg) crFils(pere, pere->value+start, "language-range", i-start);
      else crFils(pere, pere->value+start, "weight", i-start);
      start = i + 1;
      OWS(pere->value, &start);
      pvirg = 0;
    }
    i++;
  }

  return pere;
}

noeud* accept_encoding_parse(noeud* pere){

  int i = 0;
  int start = 0;
  int pvirg = 0; // Pour savoir si ensuite on cree un media range ou accept param

  if(pere->value[i] == ','){
    i+=1;
    start+=1;
  }

  while(i < pere->size){
    //Si c'est un ; de seperation de media range, accept param
    if(pere->value[i] == ';' && (pere->value[i+1] == 'q' || ( pere->value[i+1] == ' ' && pere->value[i+2] == 'q')))
    {
      crFils(pere, pere->value+start, "codings", i-start);
      start = i + 1;
      OWS(pere->value, &start);
      pvirg = 1;
    }

    if (pere->value[i] == ',' || i == pere->size-1) {
      if(!pvirg) crFils(pere, pere->value+start, "codings", i-start);
      else crFils(pere, pere->value+start, "weight", i-start);
      start = i + 1;
      OWS(pere->value, &start);
      pvirg = 0;
    }
    i++;
  }


  return pere;
}










int OWS(char* p, int* i){
  int tmp = *i;
  while(p[*i] == ' ' || p[*i] == '\t'){
    (*i)++;
  }
  //vrai = changement
  return tmp != *i; // renvoi vrai ou faux selon s'il y a eu modification ou non
}
