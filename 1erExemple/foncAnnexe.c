
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foncAnnexe.h"
#include <ctype.h>

char* enMinuscule(char* str){
  for(int i =0; str[i] != '\0'; i++){
    str[i] = tolower(str[i]);
  }
  return str;
}
