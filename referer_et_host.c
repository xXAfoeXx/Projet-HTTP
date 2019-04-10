
#include <ctype.h>

int host_parse(noeud* pere){
	if(ip_literal(pere) || ipv4adress(pere) || reg_name(pere) ){
		return 0;
	}
	return -1;
}

int ip_literal(noeud* pere){
	int start;
	char* a_parser = pere->value
	if(a_parser[0]== '['){
		if((start = ipv6adress(a_parser) )!=0 || (start = ipvfuture(a_parser)) !=0){
			if(*(a_parser+start) == ']'){
				OWS(a_parser+start,start);
				a_parser += start;
				if(a_parser[0]== '\n';){
					crFils(pere,(pere->value)+1,"IP-literal",start-1);
					return 1;
				}
			}
		
	}
	return 0;
}



int ipvfuture(char* a_parser){
	int test = 0;
	int décalage =0;
	if(a_parser[0]= 'v'){
		decalage ++;
		a_parser ++;
		while( (décalage = est_hexa(a_parser)) != 0){
			test+=1;
			a_parser+=decalage;
			taille += decalage;
		}
		if(a_parser == '.' && test != 0){
			test = 0;
			while ( est_unreserved(a_parser) || est_sub_delim(a_parser) || a_parser[0]== ':'){
				taille ++;
				a_parser ++;
				test++;
			}
			if(test != 0){
				return taille;
			}
		}
		
	}
	return 0;
}


int ipv4adress(noeud* pere){
	char* a_parser = pere->value;
	int decalage=0;
	int taille =0;
	
	if( decalage = est_dec_octet(a_parser) != 0){
		a_parser += decalage;
		taille = decalage;
	}
	else return 0;
	
	for(int i = 0; i<3;i++){
		
		if(a_parser[0]== '.') {
			a_parser++;
			taille ++;
		}
		else return 0;
		
		if( decalage = est_dec_octet(a_parser) != 0){
			a_parser += decalage;
			taille +=decalage;
		}
		else return 0;
	}
	decalage = 0;
	OWS(a_parser,decalage);
	a_parser += decalage;
	if(a_parser[0]== '\n'){
		crFils(pere,pere->value,"IPv4adresse",taille);
		return 1;
	}
	else return 0;
}


int reg_name(pere){
	char* a_parser = pere->value;
	int decalage=0;
	int taille =0;
	while( decalage = est_unreserved(a_parser) || decalage = est_pct_encoded(a_parser) || decalge = est_sub_delim(a_parser) ){
		a_parser += decalage;
		taille += decalage;
	}
	decalage = 0;
	OWS(a_parser,decalage);
	a_parser += decalage;
	if(a_parser[0]== '\n'){
		crFils(pere,pere->value,"reg-name",taille);
	}
}

int est_digit(char* chaine){	//return 1 si le permier caractere est un digit, 0 sinon
	if( isdigit(*a_parser) ) return 1;
	else return 0;
}

int est_query(char* a_parser){
	int decalage = 0;
	while( est_p_char(a_parser) || a_parser[0]== '/' ||a_parser[0]== '?'){
		decalge++;
		a_parser++;
	}
	return decalage;
}

int est_p_char(char* a_parser){
	int decalge = 0;
	if( decalge = est_unreserved(a_parser) || decalage = est_pct_encoded(a_parser) || decalage = est_sub_delim(a_parser) || a_parser[0]== ';' || a_parser[0]== '@'){
		if(decalage = 0) decalage ++;
		return decalage;
	}
	return 0;
}


int est_sub_delim(char* a_parser){
	if(a_parser[0]== '!' || a_parser[0]== '$' || a_parser[0]== '&' || a_parser[0]== '\'' || a_parser[0]== '(' || a_parser[0]== ')' || a_parser[0]== '*' || a_parser[0]== '+' || a_parser[0]== ',' || a_parser[0]== ';' || a_parser[0]== '=' ) {
		return 1;
	}
	return 0;
}

int est_alpha(char* a_parser){
	if( isalpha(*a_parser)) return 1;
	return 0;
}

int est_unreserved(char* a_parser){
	if(est_digit(a_parser) || est_alpha(a_parser) || a_parser[0]== '-' || a_parser[0]== '.' || a_parser[0]== '_' || a_parser[0]== '~'){
		return 1;
	}
	return 0;
}
int ipv6adress(char* a_parser){

	return 0;
}


int est_hexa(char* a_parser){
	if(est_digit(a_parser) || a_parser[0] == 'a' || a_parser[0]== 'A' || a_parser[0]== 'b' || a_parser[0]== 'B' || a_parser[0]== 'c' || a_parser[0]== 'C' || a_parser[0]== 'd' || a_parser[0]== 'D' || a_parser[0]== 'e' || a_parser[0]== 'E' || a_parser[0]== 'f' || a_parser[0]== 'F') {
		return 1;
	}
	return 0;
}


int est_dec_octet(char* a_parser){
	if ( a_parser[0] == '2' && a_parser[1] == '5' && a_parser[2] > 0x29 && a_parser[2] < 0x36) return 3;
	else if ( a_parser[0] == '2' && a_parser[1] > 0x29 && a_parser[1] < 0x36 && est_digit(a_parser+2) ) return 3;
	else if ( a_parser[0] == '1' && est_digit(a_parser+1) && est_digit(a_parser+2) ) return 3;
	else if ( est_digit(a_parser) && a_parser[0] != '0' && est_digit[a_parser+1] ) return 2;
	else if ( est_digit(a_parser) ) return 1;
	return 0;
}


int est_pct_encoded(char* a_parser){
	if(a_parser[0]== '%' && est_hexa(a_parser[1]) && est_hexa(a_parser[2])){
		return 3;
	}
	return 0;
}
