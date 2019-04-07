/*

Cette page est un copié-collé-mis-en-forme
de la page allRFC.html disponible sur Chamilo.

*/

int URI();					// scheme ":" hier_part [ "?" query ] [ "#" fragment ]
int hier_part();					// "//" authority path_abempty / path_absolute / path_rootless / path_empty
int URI_reference();					// URI / relative_ref
int absolute_URI();					// scheme ":" hier_part [ "?" query ]
int relative_ref();					// relative_part [ "?" query ] [ "#" fragment ]
int relative_part();					// "//" authority path_abempty / path_absolute / path_noscheme / path_empty
int scheme();					// ALPHA * ( ALPHA / DIGIT / "+" / "-" / "." )
int authority();					// [ userinfo "@" ] host [ ":" port ]
int userinfo();					// * ( unreserved / pct_encoded / sub_delims / ":" )
int host();					// IP_literal / IPv4address / reg_name
int port();					// * DIGIT
int IP_literal();					// "[" ( IPv6address / IPvFuture ) "]"
int IPvFuture();					// "v" 1* HEXDIG "." 1* ( unreserved / sub_delims / ":" )
int IPv6address();					// 6 ( h16 ":" ) ls32 / "::" 5 ( h16 ":" ) ls32 / [ h16 ] "::" 4 ( h16 ":" ) ls32 / [ h16 *1 ( ":" h16 ) ] "::" 3 ( h16 ":" ) ls32 / [ h16 *2 ( ":" h16 ) ] "::" 2 ( h16 ":" ) ls32 / [ h16 *3 ( ":" h16 ) ] "::" h16 ":" ls32 / [ h16 *4 ( ":" h16 ) ] "::" ls32 / [ h16 *5 ( ":" h16 ) ] "::" h16 / [ h16 *6 ( ":" h16 ) ] "::"
int h16();					// 1*4 HEXDIG
int ls32();					// ( h16 ":" h16 ) / IPv4address
int IPv4address();					// dec_octet "." dec_octet "." dec_octet "." dec_octet
int dec_octet();					// "25" %x30_35 / "2" %x30_34 DIGIT / "1" 2 DIGIT / %x31_39 DIGIT / DIGIT
int reg_name();					// * ( unreserved / pct_encoded / sub_delims )
int path();					// path_abempty / path_absolute / path_noscheme / path_rootless / path_empty
int path_abempty();					// * ( "/" segment )
int path_absolute();					// "/" [ segment_nz * ( "/" segment ) ]
int path_noscheme();					// segment_nz_nc * ( "/" segment )
int path_rootless();					// segment_nz * ( "/" segment )
int path_empty();					// ""
int segment();					// * pchar
int segment_nz();					// 1* pchar
int segment_nz_nc();					// 1* ( unreserved / pct_encoded / sub_delims / "@" )
int pchar();					// unreserved / pct_encoded / sub_delims / ":" / "@"
int query();					// * ( pchar / "/" / "?" )
int fragment();					// * ( pchar / "/" / "?" )
int pct_encoded();					// "%" HEXDIG HEXDIG
int unreserved();					// ALPHA / DIGIT / "-" / "." / "_" / "~"
int reserved();					// gen_delims / sub_delims
int gen_delims();					// ":" / "/" / "?" / "#" / "[" / "]" / "@"
int sub_delims();					// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
int language_range();					// ( 1*8 ALPHA * ( "-" 1*8 alphanum ) ) / "*"
int alphanum();					// ALPHA / DIGIT
int Language_Tag();					// langtag / privateuse / grandfathered
int langtag();					// language [ "-" script ] [ "-" region ] * ( "-" variant ) * ( "-" extension ) [ "-" privateuse ]
int language();					// 2*3 ALPHA [ "-" extlang ] / 4 ALPHA / 5*8 ALPHA
int extlang();					// 3 ALPHA *2 ( "-" 3 ALPHA )
int script();					// 4 ALPHA
int region();					// 2 ALPHA / 3 DIGIT
int variant();					// 5*8 alphanum / ( DIGIT 3 alphanum )
int extension();					// singleton 1* ( "-" ( 2*8 alphanum ) )
int singleton();					// DIGIT / %x41_57 / %x59_5A / %x61_77 / %x79_7A
int privateuse();					// "x" 1* ( "-" ( 1*8 alphanum ) )
int grandfathered();					// irregular / regular
int irregular();					// "en_GB_oed" / "i_ami" / "i_bnn" / "i_default" / "i_enochian" / "i_hak" / "i_klingon" / "i_lux" / "i_mingo" / "i_navajo" / "i_pwn" / "i_tao" / "i_tay" / "i_tsu" / "sgn_BE_FR" / "sgn_BE_NL" / "sgn_CH_DE"
int regular();					// "art_lojban" / "cel_gaulish" / "no_bok" / "no_nyn" / "zh_guoyu" / "zh_hakka" / "zh_min" / "zh_min_nan" / "zh_xiang"
int BWS();					// OWS
int Connection();					// * ( "," OWS ) connection_option * ( OWS "," [ OWS connection_option ] )
int Content_Length();					// 1* DIGIT
int HTTP_message();					// start_line * ( header_field CRLF ) CRLF [ message_body ]
int HTTP_name();					// %x48.54.54.50
int HTTP_version();					// HTTP_name "/" DIGIT "." DIGIT
int Host();					// uri_host [ ":" port ]
int OWS();					// * ( SP / HTAB )
int RWS();					// 1* ( SP / HTAB )
int TE();					// [ ( "," / t_codings ) * ( OWS "," [ OWS t_codings ] ) ]
int Trailer();					// * ( "," OWS ) field_name * ( OWS "," [ OWS field_name ] )
int Transfer_Encoding();					// * ( "," OWS ) transfer_coding * ( OWS "," [ OWS transfer_coding ] )
int Upgrade();					// * ( "," OWS ) protocol * ( OWS "," [ OWS protocol ] )
int Via();					// * ( "," OWS ) ( received_protocol RWS received_by [ RWS comment ] ) * ( OWS "," [ OWS ( received_protocol RWS received_by [ RWS comment ] ) ] )
int absolute_form();					// absolute_URI
int absolute_path();					// 1* ( "/" segment )
int asterisk_form();					// "*"
int authority_form();					// authority
int chunk();					// chunk_size [ chunk_ext ] CRLF chunk_data CRLF
int chunk_data();					// 1* OCTET
int chunk_ext();					// * ( ";" chunk_ext_name [ "=" chunk_ext_val ] )
int chunk_ext_name();					// token
int chunk_ext_val();					// token / quoted_string
int chunk_size();					// 1* HEXDIG
int chunked_body();					// * chunk last_chunk trailer_part CRLF
int comment();					// "(" * ( ctext / quoted_pair / comment ) ")"
int connection_option();					// token
int ctext();					// HTAB / SP / %x21_27 / %x2A_5B / %x5D_7E / obs_text
int field_content();					// field_vchar [ 1* ( SP / HTAB ) field_vchar ]
int field_name();					// token
int field_value();					// * ( field_content / obs_fold )
int field_vchar();					// VCHAR / obs_text
int http_URI();					// "http://" authority path_abempty [ "?" query ] [ "#" fragment ]
int https_URI();					// "https://" authority path_abempty [ "?" query ] [ "#" fragment ]
int last_chunk();					// 1* "0" [ chunk_ext ] CRLF
int message_body();					// * OCTET
int method();					// token
int obs_fold();					// CRLF 1* ( SP / HTAB )
int obs_text();					// %x80_FF
int origin_form();					// absolute_path [ "?" query ]
int partial_URI();					// relative_part [ "?" query ]
int protocol();					// protocol_name [ "/" protocol_version ]
int protocol_name();					// token
int protocol_version();					// token
int pseudonym();					// token
int qdtext();					// HTAB / SP / "!" / %x23_5B / %x5D_7E / obs_text
int quoted_pair();					// "\" ( HTAB / SP / VCHAR / obs_text )
int quoted_string();					// DQUOTE * ( qdtext / quoted_pair ) DQUOTE
int rank();					// ( "0" [ "." *3 DIGIT ] ) / ( "1" [ "." *3 "0" ] )
int reason_phrase();					// * ( HTAB / SP / VCHAR / obs_text )
int received_by();					// ( uri_host [ ":" port ] ) / pseudonym
int received_protocol();					// [ protocol_name "/" ] protocol_version
int request_line();					// method SP request_target SP HTTP_version CRLF
int request_target();					// origin_form
int start_line();					// request_line / status_line
int status_code();					// 3 DIGIT
int status_line();					// HTTP_version SP status_code SP reason_phrase CRLF
int t_codings();					// "trailers" / ( transfer_coding [ t_ranking ] )
int t_ranking();					// OWS ";" OWS "q=" rank
int tchar();					// "!" / "#" / "$" / "%" / "&" / "'" / "*" / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~" / DIGIT / ALPHA
int token();					// 1* tchar
int trailer_part();					// * ( header_field CRLF )
int transfer_coding();					// "chunked" / "compress" / "deflate" / "gzip" / transfer_extension
int transfer_extension();					// token * ( OWS ";" OWS transfer_parameter )
int transfer_parameter();					// token BWS "=" BWS ( token / quoted_string )
int uri_host();					// host
int Accept();					// [ ( "," / ( media_range [ accept_params ] ) ) * ( OWS "," [ OWS ( media_range [ accept_params ] ) ] ) ]
int Accept_Charset();					// * ( "," OWS ) ( ( charset / "*" ) [ weight ] ) * ( OWS "," [ OWS ( ( charset / "*" ) [ weight ] ) ] )
int Accept_Encoding();					// [ ( "," / ( codings [ weight ] ) ) * ( OWS "," [ OWS ( codings [ weight ] ) ] ) ]
int Accept_Language();					// * ( "," OWS ) ( language_range [ weight ] ) * ( OWS "," [ OWS ( language_range [ weight ] ) ] )
int Allow();					// [ ( "," / method ) * ( OWS "," [ OWS method ] ) ]
int Content_Encoding();					// * ( "," OWS ) content_coding * ( OWS "," [ OWS content_coding ] )
int Content_Language();					// * ( "," OWS ) Language_Tag * ( OWS "," [ OWS Language_Tag ] )
int Content_Location();					// absolute_URI / partial_URI
int Content_Type();					// media_type
int Date();					// HTTP_date
int Expect();					// "100_continue"
int GMT();					// %x47.4D.54
int HTTP_date();					// IMF_fixdate / obs_date
int IMF_fixdate();					// day_name "," SP date1 SP time_of_day SP GMT
int Location();					// URI_reference
int Max_Forwards();					// 1* DIGIT
int Referer();					// absolute_URI / partial_URI
int Retry_After();					// HTTP_date / delay_seconds
int Server();					// product * ( RWS ( product / comment ) )
int User_Agent();					// product * ( RWS ( product / comment ) )
int Vary();					// "*" / ( * ( "," OWS ) field_name * ( OWS "," [ OWS field_name ] ) )
int accept_ext();					// OWS ";" OWS token [ "=" ( token / quoted_string ) ]
int accept_params();					// weight * accept_ext
int asctime_date();					// day_name SP date3 SP time_of_day SP year
int charset();					// token
int codings();					// content_coding / "identity" / "*"
int content_coding();					// token
int date1();					// day SP month SP year
int date2();					// day "-" month "-" 2 DIGIT
int date3();					// month SP ( 2 DIGIT / ( SP DIGIT ) )
int day();					// 2 DIGIT
int day_name();					// %x4D.6F.6E / %x54.75.65 / %x57.65.64 / %x54.68.75 / %x46.72.69 / %x53.61.74 / %x53.75.6E
int day_name_l();					// %x4D.6F.6E.64.61.79 / %x54.75.65.73.64.61.79 / %x57.65.64.6E.65.73.64.61.79 / %x54.68.75.72.73.64.61.79 / %x46.72.69.64.61.79 / %x53.61.74.75.72.64.61.79 / %x53.75.6E.64.61.79
int delay_seconds();					// 1* DIGIT
int hour();					// 2 DIGIT
int media_range();					// ( "*/*" / ( type "/" subtype ) / ( type "/*" ) ) * ( OWS ";" OWS parameter )
int media_type();					// type "/" subtype * ( OWS ";" OWS parameter )
int minute();					// 2 DIGIT
int month();					// %x4A.61.6E / %x46.65.62 / %x4D.61.72 / %x41.70.72 / %x4D.61.79 / %x4A.75.6E / %x4A.75.6C / %x41.75.67 / %x53.65.70 / %x4F.63.74 / %x4E.6F.76 / %x44.65.63
int obs_date();					// rfc850_date / asctime_date
int parameter();					// token "=" ( token / quoted_string )
int product();					// token [ "/" product_version ]
int product_version();					// token
int qvalue();					// ( "0" [ "." *3 DIGIT ] ) / ( "1" [ "." *3 "0" ] )
int rfc850_date();					// day_name_l "," SP date2 SP time_of_day SP GMT
int second();					// 2 DIGIT
int subtype();					// token
int time_of_day();					// hour ":" minute ":" second
int type();					// token
int weight();					// OWS ";" OWS "q=" qvalue
int year();					// 4 DIGIT
int ETag();					// entity_tag
int If_Match();					// "*" / ( * ( "," OWS ) entity_tag * ( OWS "," [ OWS entity_tag ] ) )
int If_Modified_Since();					// HTTP_date
int If_None_Match();					// "*" / ( * ( "," OWS ) entity_tag * ( OWS "," [ OWS entity_tag ] ) )
int If_Unmodified_Since();					// HTTP_date
int Last_Modified();					// HTTP_date
int entity_tag();					// [ weak ] opaque_tag
int etagc();					// "!" / %x23_7E
int opaque_tag();					// DQUOTE * etagc DQUOTE
int weak();					// %x57.2F
int Accept_Ranges();					// acceptable_ranges
int Content_Range();					// byte_content_range / other_content_range
int If_Range();					// entity_tag / HTTP_date
int Range();					// byte_ranges_specifier / other_ranges_specifier
int acceptable_ranges();					// ( * ( "," OWS ) range_unit * ( OWS "," [ OWS range_unit ] ) ) / "none"
int byte_content_range();					// bytes_unit SP ( byte_range_resp / unsatisfied_range )
int byte_range();					// first_byte_pos "-" last_byte_pos
int byte_range_resp();					// byte_range "/" ( complete_length / "*" )
int byte_range_set();					// * ( "," OWS ) ( byte_range_spec / suffix_byte_range_spec ) * ( OWS "," [ OWS ( byte_range_spec / suffix_byte_range_spec ) ] )
int byte_range_spec();					// first_byte_pos "-" [ last_byte_pos ]
int byte_ranges_specifier();					// bytes_unit "=" byte_range_set
int bytes_unit();					// "bytes"
int complete_length();					// 1* DIGIT
int first_byte_pos();					// 1* DIGIT
int last_byte_pos();					// 1* DIGIT
int other_content_range();					// other_range_unit SP other_range_resp
int other_range_resp();					// * CHAR
int other_range_set();					// 1* VCHAR
int other_range_unit();					// token
int other_ranges_specifier();					// other_range_unit "=" other_range_set
int range_unit();					// bytes_unit / other_range_unit
int suffix_byte_range_spec();					// "-" suffix_length
int suffix_length();					// 1* DIGIT
int unsatisfied_range();					// "*/" complete_length
int Age();					// delta_seconds
int Cache_Control();					// * ( "," OWS ) cache_directive * ( OWS "," [ OWS cache_directive ] )
int Expires();					// HTTP_date
int Pragma();					// * ( "," OWS ) pragma_directive * ( OWS "," [ OWS pragma_directive ] )
int Warning();					// * ( "," OWS ) warning_value * ( OWS "," [ OWS warning_value ] )
int cache_directive();					// token [ "=" ( token / quoted_string ) ]
int delta_seconds();					// 1* DIGIT
int extension_pragma();					// token [ "=" ( token / quoted_string ) ]
int pragma_directive();					// "no_cache" / extension_pragma
int warn_agent();					// ( uri_host [ ":" port ] ) / pseudonym
int warn_code();					// 3 DIGIT
int warn_date();					// DQUOTE HTTP_date DQUOTE
int warn_text();					// quoted_string
int warning_value();					// warn_code SP warn_agent SP warn_text [ SP warn_date ]
int Proxy_Authenticate();					// * ( "," OWS ) challenge * ( OWS "," [ OWS challenge ] )
int Proxy_Authorization();					// credentials
int WWW_Authenticate();					// * ( "," OWS ) challenge * ( OWS "," [ OWS challenge ] )
int auth_param();					// token BWS "=" BWS ( token / quoted_string )
int auth_scheme();					// token
int challenge();					// auth_scheme [ 1* SP ( token68 / [ ( "," / auth_param ) * ( OWS "," [ OWS auth_param ] ) ] ) ]
int credentials();					// auth_scheme [ 1* SP ( token68 / [ ( "," / auth_param ) * ( OWS "," [ OWS auth_param ] ) ] ) ]
int Authorization();					// credentials
int token68();					// 1* ( ALPHA / DIGIT / "-" / "." / "_" / "~" / "+" / "/" ) * "="
int Connection_header();					// "Connection" ":" OWS Connection OWS
int Content_Length_header();					// "Content_Length" ":" OWS Content_Length OWS
int Content_Type_header();					// "Content_Type" ":" OWS Content_Type OWS
int Trailer_header();					// "Trailer" ":" OWS Trailer OWS
int Transfer_Encoding_header();					// "Transfer_Encoding" ":" OWS Transfer_Encoding OWS
int Upgrade_header();					// "Upgrade" ":" OWS Upgrade OWS
int Via_header();					// "Via" ":" OWS Via OWS
int Age_header();					// "Age" ":" OWS Age OWS
int Expires_header();					// "Expires" ":" OWS Expires OWS
int Date_header();					// "Date" ":" OWS Date OWS
int Location_header();					// "Location" ":" OWS Location OWS
int Retry_After_header();					// "Retry_After" ":" OWS Retry_After OWS
int Vary_header();					// "Vary" ":" OWS Vary OWS
int Warning_header();					// "Warning" ":" OWS Warning OWS
int Cache_Control_header();					// "Cache_Control" ":" OWS Cache_Control OWS
int Expect_header();					// "Expect" ":" OWS Expect OWS
int Host_header();					// "Host" ":" OWS Host OWS
int Max_Forwards_header();					// "Max_Forwards" ":" OWS Max_Forwards OWS
int Pragma_header();					// "Pragma" ":" OWS Pragma OWS
int Range_header();					// "Range" ":" OWS Range OWS
int TE_header();					// "TE" ":" OWS TE OWS
int If_Match_header();					// "If_Match" ":" OWS If_Match OWS
int If_None_Match_header();					// "If_None_Match" ":" OWS If_None_Match OWS
int If_Modified_Since_header();					// "If_Modified_Since" ":" OWS If_Modified_Since OWS
int If_Unmodified_Since_header();					// "If_Unmodified_Since" ":" OWS If_Unmodified_Since OWS
int If_Range_header();					// "If_Range" ":" OWS If_Range OWS
int Accept_header();					// "Accept" ":" OWS Accept OWS
int Accept_Charset_header();					// "Accept_Charset" ":" OWS Accept_Charset OWS
int Accept_Encoding_header();					// "Accept_Encoding" ":" OWS Accept_Encoding OWS
int Accept_Language_header();					// "Accept_Language" ":" OWS Accept_Language OWS
int Authorization_header();					// "Authorization" ":" OWS Authorization OWS
int Proxy_Authorization_header();					// "Proxy_Authorization" ":" OWS Proxy_Authorization OWS
int Referer_header();					// "Referer" ":" OWS Referer OWS
int User_Agent_header();					// "User_Agent" ":" OWS User_Agent OWS
int cookie_pair();					// cookie_name "=" cookie_value
int cookie_name();					// token
int cookie_value();					// ( DQUOTE * cookie_octet DQUOTE ) / * cookie_octet
int cookie_octet();					// %x21 / %x23_2B / %x2D_3A / %x3C_5B / %x5D_7E
int Cookie_header();					// "Cookie:" OWS cookie_string OWS
int cookie_string();					// cookie_pair * ( ";" SP cookie_pair )
int header_field();					// Connection_header / Content_Length_header / Content_Type_header / Cookie_header / Transfer_Encoding_header / Expect_header / Host_header / Accept_header / Accept_Charset_header / Accept_Encoding_header / Accept_Language_header / Referer_header / User_Agent_header / ( field_name ":" OWS field_value OWS )
