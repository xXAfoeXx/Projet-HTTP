
#ifndef FONCPARSEUR_H
#define FONCPARSEUR_H
#include "arbre.h"

noeud* parse(char* str, int taille);

noeud* http_message_parse(noeud* pere);


noeud* start_line_parse(noeud* pere);

noeud* request_line_parse(noeud* pere);

noeud* request_target_parse(noeud* pere);


noeud* header_field_parse(noeud* pere);

noeud* connection_parse(noeud* pere);

noeud* content_length_parse(noeud* pere);

noeud* user_agent_parse(noeud* pere);

noeud* accept_parse(noeud* pere);

noeud* accept_language_parse(noeud* pere);

noeud* accept_encoding_parse(noeud* pere);


int OWS(char* p, int* i);

#endif
