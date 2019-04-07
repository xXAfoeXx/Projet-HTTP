
#ifndef FONCPARSEUR_H
#define FONCPARSEUR_H
#include "arbre.h"

noeud* parse(char* str, int taille);

noeud* http_message_parse(noeud* pere);


noeud* start_line_parse(noeud* pere);

noeud* request_line_parse(noeud* pere);

noeud* request_target_parse(noeud* pere);


noeud* header_field_parse(noeud* pere);

int connection_parse(noeud* pere);

int content_length_parse(noeud* pere);

int user_agent_parse(noeud* pere);

int accept_parse(noeud* pere);

int accept_language_parse(noeud* pere);

int accept_encoding_parse(noeud* pere);

int content_type_parse(noeud* pere);

int cookie_parse(noeud* pere);

int transfer_encoding_parse(noeud* pere);

int expect_parse(noeud* pere);

int host_parse(noeud* pere);

int accept_charset_parse(noeud* pere);

int referer_parse(noeud* pere);


int OWS(char* p, int* i);

#endif
