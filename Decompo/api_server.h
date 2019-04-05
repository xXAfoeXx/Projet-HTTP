#include <stdio.h>
#include <stlib.h>

// Dans ce fichier pour l'instant, je mets les trucs à tester 1 par 1, vous devriez comprendre



int HTTP_message();												// start-line * ( header-field CRLF ) CRLF [ message-body ]
	int start_line();											// request-line / status-line
		int request_line();										// method SP request-target SP HTTP-version CRLF
			int method ();										// token
				int token ();									// 1* tchar
					int tchar();								// "!" / "#" / "$" / "%" / "&" / "'" / "*" / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~" / DIGIT / ALPHA
			int request_target();								// origin-form
				int origin_form();								// absolute-path [ "?" query ]
					int absolute_path ();						// 1* ( "/" segment )
						int segment();							// * pchar
							int pchar();						// unreserved / pct-encoded / sub-delims / ":" / "@"
					int query();								// * ( pchar / "/" / "?" )0
//						int pchar();							// unreserved / pct-encoded / sub-delims / ":" / "@"
			int HTTP_version();									// HTTP-name "/" DIGIT "." DIGIT
				int HTTP_name();								// %x48.54.54.50
		int status_line();										// HTTP-version SP status-code SP reason-phrase CRLF
//			int HTTP_version();									// HTTP-name "/" DIGIT "." DIGIT
//				int HTTP_name();								// %x48.54.54.50
			int status_code();									// 3 DIGIT
			int reason_phrase();								// * ( HTAB / SP / VCHAR / obs-text )
				int obs_text();									// %x80-FF
	int header_field();											// Connection-header / Content-Length-header / Content-Type-header / Cookie-header / Transfer-Encoding-header / Expect-header / Host-header / Accept-header / Accept-Charset-header / Accept-Encoding-header / Accept-Language-header / Referer-header / User-Agent-header / ( field-name ":" OWS field-value OWS )
		int Connection_header();								// "Connection" ":" OWS Connection OWS
		int Content_Length_header();							// "Content-Length" ":" OWS Content-Length OWS
		int Content_Type_header();								// "Content-Type" ":" OWS Content-Type OWS
		int Cookie_header();									//  "Cookie:" OWS cookie-string OWS 
	int message_body();											//* OCTET
