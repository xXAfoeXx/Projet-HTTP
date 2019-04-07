#include <stdio.h>
#include <stlib.h>

/*

Voici la liste de TOUTES les fonctions de parse qu'on va devoir faire.

Elles ne sont toutes au programme de l'étape 2.
Pour l'étape 2, je pense qu'on a besoin d'aller au 3 ou 4 ème étage

Les tabulations défissent les références des fonctions :

> fonction1();
>	fonction2();

signifie que l'implémentation de fonction1() aura besoin d'une
implémentation (ultérieure) de fonction2().

Les lignes commentées signifies que la fonction nécessaire est
déjà donné plus haut.

Note : certaines lignes de semantique.h ne sont pas définies ici.

La racine ici est HTTP_message().

*/


int HTTP_message();												// start_line * ( header_field CRLF ) CRLF [ message_body ]
	int start_line();											// request_line / status_line
		int request_line();										// method SP request_target SP HTTP_version CRLF
			int method ();										// token
				int token ();									// 1* tchar
					int tchar();								// "!" / "#" / "$" / "%" / "&" / "'" / "*" / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~" / DIGIT / ALPHA
			int request_target();								// origin_form
				int origin_form();								// absolute_path [ "?" query ]
					int absolute_path ();						// 1* ( "/" segment )
						int segment();							// * pchar
							int pchar();						// unreserved / pct_encoded / sub_delims / ":" / "@"
								int unreserved():				// ALPHA / DIGIT / "-" / "." / "_" / "~"
								int pct_encoded();				// "%" HEXDIG HEXDIG
								int sub_delims();				// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
					int query();								// * ( pchar / "/" / "?" )0
//						int pchar();							// unreserved / pct_encoded / sub_delims / ":" / "@"
			int HTTP_version();									// HTTP_name "/" DIGIT "." DIGIT
				int HTTP_name();								// %x48.54.54.50
		int status_line();										// HTTP_version SP status_code SP reason_phrase CRLF
//			int HTTP_version();									// HTTP_name "/" DIGIT "." DIGIT
//				int HTTP_name();								// %x48.54.54.50
			int status_code();									// 3 DIGIT
			int reason_phrase();								// * ( HTAB / SP / VCHAR / obs_text )
				int obs_text();									// %x80_FF
	int header_field();											// Connection_header / Content_Length_header / Content_Type_header / Cookie_header / Transfer_Encoding_header / Expect_header
																// Host_header / Accept_header / Accept_Charset_header / Accept_Encoding_header / Accept_Language_header / Referer_header
																// User_Agent_header / ( field_name ":" OWS field_value OWS )
		int Connection_header();								// "Connection" ":" OWS Connection OWS
			int OWS();											// * ( SP / HTAB )
			int Connection();									// * ( "," OWS ) connection_option * ( OWS "," [ OWS connection_option ] )
			 	int connection_option();						// token
		int Content_Length_header();							// "Content_Length" ":" OWS Content_Length OWS
			int Content_Length();								// 1* DIGIT
		int Content_Type_header();								// "Content_Type" ":" OWS Content_Type OWS
			int Content_Type();									// media_type
				int media_type();								// type "/" subtype * ( OWS ";" OWS parameter )
					int type();									// token
					int subtype();								// token
					int parameter();							// token "=" ( token / quoted_string )
						int quoted_string();					// DQUOTE * ( qdtext / quoted_pair ) DQUOTE
							int qdtext();						// HTAB / SP / "!" / %x23_5B / %x5D_7E / obs_text
//								int obs_text();					// %x80_FF
							int quoted_pair();					// "\" ( HTAB / SP / VCHAR / obs_text )
//								int obs_text();					// %x80_FF
		int Cookie_header();									// "Cookie:" OWS cookie_string OWS
			int cookie_string();								// cookie_pair * ( ";" SP cookie_pair )
				int cookie_pair();								// cookie_name "=" cookie_value
					int cookie_name();							// token
					int cookie_value();							//( DQUOTE * cookie_octet DQUOTE ) / * cookie_octet
						int cookie_octet();						// %x21 / %x23_2B / %x2D_3A / %x3C_5B / %x5D_7E
		int Transfer_Encoding_header ();						// "Transfer_Encoding" ":" OWS Transfer_Encoding OWS
			int Transfer_Encoding();							// * ( "," OWS ) transfer_coding * ( OWS "," [ OWS transfer_coding ] )
				int transfer_coding();							// "chunked" / "compress" / "deflate" / "gzip" / transfer_extension
					int transfer_extension();					// token * ( OWS ";" OWS transfer_parameter )
						int transfer_parameter();				// token BWS "=" BWS ( token / quoted_string )
//							int quoted_string();				// DQUOTE * ( qdtext / quoted_pair ) DQUOTE
		int Expect_header();									// "Expect" ":" OWS Expect OWS
			int Expect();										// "100_continue"
		int Host_header();										// "Host" ":" OWS Host OWS
			int host();											// IP_literal / IPv4address / reg_name
				int IP_literal();								// "[" ( IPv6address / IPvFuture ) "]"
					int IPv6address();							// 6 ( h16 ":" ) ls32 / "::" 5 ( h16 ":" ) ls32 / [ h16 ] "::" 4 ( h16 ":" ) ls32 / [ h16 *1 ( ":" h16 ) ] "::" 3 ( h16 ":" ) ls32 / [ h16 *2 ( ":" h16 ) ] "::" 2 ( h16 ":" ) ls32 / [ h16 *3 ( ":" h16 ) ] "::" h16 ":" ls32 / [ h16 *4 ( ":" h16 ) ] "::" ls32 / [ h16 *5 ( ":" h16 ) ] "::" h16 / [ h16 *6 ( ":" h16 ) ] "::"
					int IPvFuture();							// "v" 1* HEXDIG "." 1* ( unreserved / sub_delims / ":" )
//						int unreserved():						// ALPHA / DIGIT / "-" / "." / "_" / "~"
//						int sub_delims();						// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
				int IPv4address();								// dec_octet "." dec_octet "." dec_octet "." dec_octet
					int dec_octet();							// "25" %x30_35 / "2" %x30_34 DIGIT / "1" 2 DIGIT / %x31_39 DIGIT / DIGIT
				int reg_name();									// * ( unreserved / pct_encoded / sub_delims )
//						int unreserved():						// ALPHA / DIGIT / "-" / "." / "_" / "~"
//						int pct_encoded();						// "%" HEXDIG HEXDIG
//						int sub_delims();						// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="

		int Accept_header();									// "Accept" ":" OWS Accept OWS
			int Accept();										// [ ( "," / ( media_range [ accept_params ] ) ) * ( OWS "," [ OWS ( media_range [ accept_params ] ) ] ) ]
				int media_range();								// ( "*/*" / ( type "/" subtype ) / ( type "/*" ) ) * ( OWS ";" OWS parameter )
//					int type();									// token
//					int subtype();								// token
//					int parameter();							// token "=" ( token / quoted_string )
				int accept_params();							// weight * accept_ext
					int weight();								// OWS ";" OWS "q=" qvalue
						int qvalue();							// ( "0" [ "." *3 DIGIT ] ) / ( "1" [ "." *3 "0" ] )
					int accept_ext();							// OWS ";" OWS token [ "=" ( token / quoted_string ) ]
//						int quoted_string();					// DQUOTE * ( qdtext / quoted_pair ) DQUOTE
		int Accept_Charset_header();							// "Accept_Charset" ":" OWS Accept_Charset OWS
			int Accept_Charset();								// * ( "," OWS ) ( ( charset / "*" ) [ weight ] ) * ( OWS "," [ OWS ( ( charset / "*" ) [ weight ] ) ] )
				int charset();									// token
//				int weight();									// OWS ";" OWS "q=" qvalue
		int Accept_Encoding_header();							// "Accept_Encoding" ":" OWS Accept_Encoding OWS
			int Accept_Encoding();								// [ ( "," / ( codings [ weight ] ) ) * ( OWS "," [ OWS ( codings [ weight ] ) ] ) ]
				int codings();									// content_coding / "identity" / "*"
					int content_coding();						// token
//				int weight();									// OWS ";" OWS "q=" qvalue
		int Accept_Language_header();							// "Accept_Language" ":" OWS Accept_Language OWS
			int Accept_Language();								// * ( "," OWS ) ( language_range [ weight ] ) * ( OWS "," [ OWS ( language_range [ weight ] ) ] )
				int language_range();							// ( 1*8 ALPHA * ( "-" 1*8 alphanum ) ) / "*"
					int alphanum();								// ALPHA / DIGIT
//				int weight();									// OWS ";" OWS "q=" qvalue
		int Referer_header();									// "Referer" ":" OWS Referer OWS
			int Referer();										// absolute_URI / partial_URI
				int absolute_URI();								// scheme ":" hier_part [ "?" query ]
					int hier_part();							// "//" authority path_abempty / path_absolute / path_rootless / path_empty
						int authority();						// [ userinfo "@" ] host [ ":" port ]
							int userinfo();						// * ( unreserved / pct_encoded / sub_delims / ":" )
//								int unreserved():				// ALPHA / DIGIT / "-" / "." / "_" / "~"
//								int pct_encoded();				// "%" HEXDIG HEXDIG
//								int sub_delims();				// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
//							int host();							// IP_literal / IPv4address / reg_name
							int port();							// * DIGIT
						int path_abempty();						// * ( "/" segment )
//							int segment();						// * pchar
						int path_absolute();					// "/" [ segment_nz * ( "/" segment ) ]
							int segment_nz();					// 1* pchar
//							int segment();						// * pchar
						int path_rootless();					// segment_nz * ( "/" segment )
//							int segment();						// * pchar
						int path_empty();						// ""
//					int query();								// * ( pchar / "/" / "?" )0
			int partial_URI();									// relative_part [ "?" query ]
				int relative_part();							// "//" authority path_abempty / path_absolute / path_noscheme / path_empty
//						int authority();						// [ userinfo "@" ] host [ ":" port ]
//						int path_abempty();						// * ( "/" segment )
//						int path_absolute();					// "/" [ segment_nz * ( "/" segment ) ]
						int path_noscheme();					// segment_nz_nc * ( "/" segment )
							int segment_nz_nc();				// 1* ( unreserved / pct_encoded / sub_delims / "@" )
//								int unreserved():				// ALPHA / DIGIT / "-" / "." / "_" / "~"
//								int pct_encoded();				// "%" HEXDIG HEXDIG
//								int sub_delims();				// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
//							int segment();						// * pchar
//						int path_empty();						// ""
//					int query();								// * ( pchar / "/" / "?" )0
		int User_Agent_header();								// "User_Agent" ":" OWS User_Agent OWS
			int User_Agent();									// product * ( RWS ( product / comment ) )
				int product();									// token [ "/" product_version ]
					int product_version();						// token
				int comment();									// "(" * ( ctext / quoted_pair / comment ) ")"
					int ctext();								// HTAB / SP / %x21_27 / %x2A_5B / %x5D_7E / obs_text
//						int obs_text();							// %x80_FF
//					int quoted_pair();							// "\" ( HTAB / SP / VCHAR / obs_text )
//					int comment();								// "(" * ( ctext / quoted_pair / comment ) ")"
		int field_name();										// token
//			int token ();										// 1* tchar
	int message_body();											//* OCTET
