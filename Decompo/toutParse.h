#include <stdio.h>
#include <stlib.h>

/*

Voici la liste de TOUTES les fonctions de parse qu'on va devoir faire.

Elles ne sont toutes au programme de l'étape 2.
Pour l'étape 2, je pense qu'on a besoin d'aller au 3 ou 4 ème étage

Les tabulations défissent les références des fonctions :

> fonction1_parse(noeud* pere);
>	fonction2_parse(noeud* pere);

signifie que l'implémentation de fonction1(noeud* pere) aura besoin d'une
implémentation (ultérieure) de fonction2(noeud* pere).

Les lignes commentées signifies que la fonction nécessaire est
déjà donné plus haut.

Note : certaines lignes de semantique.h ne sont pas définies ici.

La racine ici est HTTP_message(noeud* pere).

*/


noeud* HTTP_message_parse(noeud* pere);											// start_line * ( header_field CRLF ) CRLF [ message_body ]
	noeud* start_line_parse(noeud* pere);										// request_line / status_line
		noeud* request_line_parse(noeud* pere);									// method SP request_target SP HTTP_version CRLF
			noeud* method_parse(noeud* pere);									// token
				noeud* token_parse(noeud* pere);								// 1* tchar
					noeud* tchar_parse(noeud* pere);							// "!" / "#" / "$" / "%" / "&" / "'" / "*" / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~" / DIGIT / ALPHA
			noeud* request_target_parse(noeud* pere);							// origin_form
				noeud* origin_form_parse(noeud* pere);							// absolute_path [ "?" query ]
					noeud* absolute_path_parse(noeud* pere);					// 1* ( "/" segment )
						noeud* segment_parse(noeud* pere);						// * pchar
							noeud* pchar_parse(noeud* pere);					// unreserved / pct_encoded / sub_delims / ":" / "@"
								noeud* unreserved(noeud* pere):					// ALPHA / DIGIT / "-" / "." / "_" / "~"
								noeud* pct_encoded_parse(noeud* pere);			// "%" HEXDIG HEXDIG
								noeud* sub_delims_parse(noeud* pere);			// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
					noeud* query_parse(noeud* pere);							// * ( pchar / "/" / "?" )0
//						noeud* pchar_parse(noeud* pere);						// unreserved / pct_encoded / sub_delims / ":" / "@"
			noeud* HTTP_version_parse(noeud* pere);								// HTTP_name "/" DIGIT "." DIGIT
				noeud* HTTP_name_parse(noeud* pere);							// %x48.54.54.50
		noeud* status_line_parse(noeud* pere);									// HTTP_version SP status_code SP reason_phrase CRLF
//			noeud* HTTP_version_parse(noeud* pere);								// HTTP_name "/" DIGIT "." DIGIT
//				noeud* HTTP_name_parse(noeud* pere);							// %x48.54.54.50
			noeud* status_code_parse(noeud* pere);								// 3 DIGIT
			noeud* reason_phrase_parse(noeud* pere);							// * ( HTAB / SP / VCHAR / obs_text )
				noeud* obs_text_parse(noeud* pere);								// %x80_FF
	noeud* header_field_parse(noeud* pere);										// Connection_header / Content_Length_header / Content_Type_header / Cookie_header / Transfer_Encoding_header / Expect_header
																				// Host_header / Accept_header / Accept_Charset_header / Accept_Encoding_header / Accept_Language_header / Referer_header
																				// User_Agent_header / ( field_name ":" OWS field_value OWS )
		noeud* Connection_header_parse(noeud* pere);							// "Connection" ":" OWS Connection OWS
			noeud* OWS_parse(noeud* pere);										// * ( SP / HTAB )
			noeud* Connection_parse(noeud* pere);								// * ( "," OWS ) connection_option * ( OWS "," [ OWS connection_option ] )
			 	noeud* connection_option_parse(noeud* pere);					// token
		noeud* Content_Length_header_parse(noeud* pere);						// "Content_Length" ":" OWS Content_Length OWS
			noeud* Content_Length_parse(noeud* pere);							// 1* DIGIT
		noeud* Content_Type_header_parse(noeud* pere);							// "Content_Type" ":" OWS Content_Type OWS
			noeud* Content_Type_parse(noeud* pere);								// media_type
				noeud* media_type_parse(noeud* pere);							// type "/" subtype * ( OWS ";" OWS parameter )
					noeud* type_parse(noeud* pere);								// token
					noeud* subtype_parse(noeud* pere);							// token
					noeud* parameter_parse(noeud* pere);						// token "=" ( token / quoted_string )
						noeud* quoted_string_parse(noeud* pere);				// DQUOTE * ( qdtext / quoted_pair ) DQUOTE
							noeud* qdtext_parse(noeud* pere);					// HTAB / SP / "!" / %x23_5B / %x5D_7E / obs_text
//								noeud* obs_text_parse(noeud* pere);				// %x80_FF
							noeud* quoted_pair_parse(noeud* pere);				// "\" ( HTAB / SP / VCHAR / obs_text )
//								noeud* obs_text_parse(noeud* pere);				// %x80_FF
		noeud* Cookie_header_parse(noeud* pere);								// "Cookie:" OWS cookie_string OWS
			noeud* cookie_string_parse(noeud* pere);							// cookie_pair * ( ";" SP cookie_pair )
				noeud* cookie_pair_parse(noeud* pere);							// cookie_name "=" cookie_value
					noeud* cookie_name_parse(noeud* pere);						// token
					noeud* cookie_value_parse(noeud* pere);						//( DQUOTE * cookie_octet DQUOTE ) / * cookie_octet
						noeud* cookie_octet_parse(noeud* pere);					// %x21 / %x23_2B / %x2D_3A / %x3C_5B / %x5D_7E
		noeud* Transfer_Encoding_header _parse(noeud* pere);					// "Transfer_Encoding" ":" OWS Transfer_Encoding OWS
			noeud* Transfer_Encoding_parse(noeud* pere);						// * ( "," OWS ) transfer_coding * ( OWS "," [ OWS transfer_coding ] )
				noeud* transfer_coding_parse(noeud* pere);						// "chunked" / "compress" / "deflate" / "gzip" / transfer_extension
					noeud* transfer_extension_parse(noeud* pere);				// token * ( OWS ";" OWS transfer_parameter )
						noeud* transfer_parameter_parse(noeud* pere);			// token BWS "=" BWS ( token / quoted_string )
//							noeud* quoted_string_parse(noeud* pere);			// DQUOTE * ( qdtext / quoted_pair ) DQUOTE
		noeud* Expect_header_parse(noeud* pere);								// "Expect" ":" OWS Expect OWS
			noeud* Expect_parse(noeud* pere);									// "100_continue"
		noeud* Host_header_parse(noeud* pere);									// "Host" ":" OWS Host OWS
			noeud* host_parse(noeud* pere);										// IP_literal / IPv4address / reg_name
				noeud* IP_literal_parse(noeud* pere);							// "[" ( IPv6address / IPvFuture ) "]"
					noeud* IPv6address_parse(noeud* pere);						// 6 ( h16 ":" ) ls32 / "::" 5 ( h16 ":" ) ls32 / [ h16 ] "::" 4 ( h16 ":" ) ls32 / [ h16 *1 ( ":" h16 ) ] "::" 3 ( h16 ":" ) ls32 / [ h16 *2 ( ":" h16 ) ] "::" 2 ( h16 ":" ) ls32 / [ h16 *3 ( ":" h16 ) ] "::" h16 ":" ls32 / [ h16 *4 ( ":" h16 ) ] "::" ls32 / [ h16 *5 ( ":" h16 ) ] "::" h16 / [ h16 *6 ( ":" h16 ) ] "::"
					noeud* IPvFuture_parse(noeud* pere);						// "v" 1* HEXDIG "." 1* ( unreserved / sub_delims / ":" )
//						noeud* unreserved(noeud* pere):							// ALPHA / DIGIT / "-" / "." / "_" / "~"
//						noeud* sub_delims_parse(noeud* pere);					// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
				noeud* IPv4address_parse(noeud* pere);							// dec_octet "." dec_octet "." dec_octet "." dec_octet
					noeud* dec_octet_parse(noeud* pere);						// "25" %x30_35 / "2" %x30_34 DIGIT / "1" 2 DIGIT / %x31_39 DIGIT / DIGIT
				noeud* reg_name_parse(noeud* pere);								// * ( unreserved / pct_encoded / sub_delims )
//						noeud* unreserved(noeud* pere):							// ALPHA / DIGIT / "-" / "." / "_" / "~"
//						noeud* pct_encoded_parse(noeud* pere);					// "%" HEXDIG HEXDIG
//						noeud* sub_delims_parse(noeud* pere);					// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
		noeud* Accept_header_parse(noeud* pere);								// "Accept" ":" OWS Accept OWS
			noeud* Accept_parse(noeud* pere);									// [ ( "," / ( media_range [ accept_params ] ) ) * ( OWS "," [ OWS ( media_range [ accept_params ] ) ] ) ]
				noeud* media_range_parse(noeud* pere);							// ( "*/*" / ( type "/" subtype ) / ( type "/*" ) ) * ( OWS ";" OWS parameter )
//					noeud* type_parse(noeud* pere);								// token
//					noeud* subtype_parse(noeud* pere);							// token
//					noeud* parameter_parse(noeud* pere);						// token "=" ( token / quoted_string )
				noeud* accept_params_parse(noeud* pere);						// weight * accept_ext
					noeud* weight_parse(noeud* pere);							// OWS ";" OWS "q=" qvalue
						noeud* qvalue_parse(noeud* pere);						// ( "0" [ "." *3 DIGIT ] ) / ( "1" [ "." *3 "0" ] )
					noeud* accept_ext_parse(noeud* pere);						// OWS ";" OWS token [ "=" ( token / quoted_string ) ]
//						noeud* quoted_string_parse(noeud* pere);				// DQUOTE * ( qdtext / quoted_pair ) DQUOTE
		noeud* Accept_Charset_header_parse(noeud* pere);						// "Accept_Charset" ":" OWS Accept_Charset OWS
			noeud* Accept_Charset_parse(noeud* pere);							// * ( "," OWS ) ( ( charset / "*" ) [ weight ] ) * ( OWS "," [ OWS ( ( charset / "*" ) [ weight ] ) ] )
				noeud* charset_parse(noeud* pere);								// token
//				noeud* weight_parse(noeud* pere);								// OWS ";" OWS "q=" qvalue
		noeud* Accept_Encoding_header_parse(noeud* pere);						// "Accept_Encoding" ":" OWS Accept_Encoding OWS
			noeud* Accept_Encoding_parse(noeud* pere);							// [ ( "," / ( codings [ weight ] ) ) * ( OWS "," [ OWS ( codings [ weight ] ) ] ) ]
				noeud* codings_parse(noeud* pere);								// content_coding / "identity" / "*"
					noeud* content_coding_parse(noeud* pere);					// token
//				noeud* weight_parse(noeud* pere);								// OWS ";" OWS "q=" qvalue
		noeud* Accept_Language_header_parse(noeud* pere);						// "Accept_Language" ":" OWS Accept_Language OWS
			noeud* Accept_Language_parse(noeud* pere);							// * ( "," OWS ) ( language_range [ weight ] ) * ( OWS "," [ OWS ( language_range [ weight ] ) ] )
				noeud* language_range_parse(noeud* pere);						// ( 1*8 ALPHA * ( "-" 1*8 alphanum ) ) / "*"
					noeud* alphanum_parse(noeud* pere);							// ALPHA / DIGIT
//				noeud* weight_parse(noeud* pere);								// OWS ";" OWS "q=" qvalue
		noeud* Referer_header_parse(noeud* pere);								// "Referer" ":" OWS Referer OWS
			noeud* Referer_parse(noeud* pere);									// absolute_URI / partial_URI
				noeud* absolute_URI_parse(noeud* pere);							// scheme ":" hier_part [ "?" query ]
					noeud* hier_part_parse(noeud* pere);						// "//" authority path_abempty / path_absolute / path_rootless / path_empty
						noeud* authority_parse(noeud* pere);					// [ userinfo "@" ] host [ ":" port ]
							noeud* userinfo_parse(noeud* pere);					// * ( unreserved / pct_encoded / sub_delims / ":" )
//								noeud* unreserved(noeud* pere):					// ALPHA / DIGIT / "-" / "." / "_" / "~"
//								noeud* pct_encoded_parse(noeud* pere);			// "%" HEXDIG HEXDIG
//								noeud* sub_delims_parse(noeud* pere);			// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
//							noeud* host_parse(noeud* pere);						// IP_literal / IPv4address / reg_name
							noeud* port_parse(noeud* pere);						// * DIGIT
						noeud* path_abempty_parse(noeud* pere);					// * ( "/" segment )
//							noeud* segment_parse(noeud* pere);					// * pchar
						noeud* path_absolute_parse(noeud* pere);				// "/" [ segment_nz * ( "/" segment ) ]
							noeud* segment_nz_parse(noeud* pere);				// 1* pchar
//							noeud* segment_parse(noeud* pere);					// * pchar
						noeud* path_rootless_parse(noeud* pere);				// segment_nz * ( "/" segment )
//							noeud* segment_parse(noeud* pere);					// * pchar
						noeud* path_empty_parse(noeud* pere);					// ""
//					noeud* query_parse(noeud* pere);							// * ( pchar / "/" / "?" )0
			noeud* partial_URI_parse(noeud* pere);								// relative_part [ "?" query ]
				noeud* relative_part_parse(noeud* pere);						// "//" authority path_abempty / path_absolute / path_noscheme / path_empty
//						noeud* authority_parse(noeud* pere);					// [ userinfo "@" ] host [ ":" port ]
//						noeud* path_abempty_parse(noeud* pere);					// * ( "/" segment )
//						noeud* path_absolute_parse(noeud* pere);				// "/" [ segment_nz * ( "/" segment ) ]
						noeud* path_noscheme_parse(noeud* pere);				// segment_nz_nc * ( "/" segment )
							noeud* segment_nz_nc_parse(noeud* pere);			// 1* ( unreserved / pct_encoded / sub_delims / "@" )
//								noeud* unreserved(noeud* pere):					// ALPHA / DIGIT / "-" / "." / "_" / "~"
//								noeud* pct_encoded_parse(noeud* pere);			// "%" HEXDIG HEXDIG
//								noeud* sub_delims_parse(noeud* pere);			// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
//							noeud* segment_parse(noeud* pere);					// * pchar
//						noeud* path_empty_parse(noeud* pere);					// ""
//					noeud* query_parse(noeud* pere);							// * ( pchar / "/" / "?" )0
		noeud* User_Agent_header_parse(noeud* pere);							// "User_Agent" ":" OWS User_Agent OWS
			noeud* User_Agent_parse(noeud* pere);								// product * ( RWS ( product / comment ) )
				noeud* product_parse(noeud* pere);								// token [ "/" product_version ]
					noeud* product_version_parse(noeud* pere);					// token
				noeud* comment_parse(noeud* pere);								// "(" * ( ctext / quoted_pair / comment ) ")"
					noeud* ctext_parse(noeud* pere);							// HTAB / SP / %x21_27 / %x2A_5B / %x5D_7E / obs_text
//						noeud* obs_text_parse(noeud* pere);						// %x80_FF
//					noeud* quoted_pair_parse(noeud* pere);						// "\" ( HTAB / SP / VCHAR / obs_text )
//					noeud* comment_parse(noeud* pere);							// "(" * ( ctext / quoted_pair / comment ) ")"
		noeud* field_name_parse(noeud* pere);									// token
//			noeud* token _parse(noeud* pere);									// 1* tchar
	noeud* message_body_parse(noeud* pere);										//* OCTET
