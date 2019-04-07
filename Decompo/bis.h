URI();					// scheme ":" hier_part [ "?" query ] [ "#" fragment ]
hier_part();					// "//" authority path_abempty / path_absolute / path_rootless / path_empty
URI_reference();					// URI / relative_ref
absolute_URI();					// scheme ":" hier_part [ "?" query ]
relative_ref();					// relative_part [ "?" query ] [ "#" fragment ]
relative_part();					// "//" authority path_abempty / path_absolute / path_noscheme / path_empty
scheme();					// ALPHA * ( ALPHA / DIGIT / "+" / "-" / "." )
authority();					// [ userinfo "@" ] host [ ":" port ]
userinfo();					// * ( unreserved / pct_encoded / sub_delims / ":" )
host();					// IP_literal / IPv4address / reg_name
port();					// * DIGIT
IP_literal();					// "[" ( IPv6address / IPvFuture ) "]"
IPvFuture();					// "v" 1* HEXDIG "." 1* ( unreserved / sub_delims / ":" )
IPv6address();					// 6 ( h16 ":" ) ls32 / "::" 5 ( h16 ":" ) ls32 / [ h16 ] "::" 4 ( h16 ":" ) ls32 / [ h16 *1 ( ":" h16 ) ] "::" 3 ( h16 ":" ) ls32 / [ h16 *2 ( ":" h16 ) ] "::" 2 ( h16 ":" ) ls32 / [ h16 *3 ( ":" h16 ) ] "::" h16 ":" ls32 / [ h16 *4 ( ":" h16 ) ] "::" ls32 / [ h16 *5 ( ":" h16 ) ] "::" h16 / [ h16 *6 ( ":" h16 ) ] "::"
h16();					// 1*4 HEXDIG
ls32();					// ( h16 ":" h16 ) / IPv4address
IPv4address();					// dec_octet "." dec_octet "." dec_octet "." dec_octet
dec_octet();					// "25" %x30_35 / "2" %x30_34 DIGIT / "1" 2 DIGIT / %x31_39 DIGIT / DIGIT
reg_name();					// * ( unreserved / pct_encoded / sub_delims )
path();					// path_abempty / path_absolute / path_noscheme / path_rootless / path_empty
path_abempty();					// * ( "/" segment )
path_absolute();					// "/" [ segment_nz * ( "/" segment ) ]
path_noscheme();					// segment_nz_nc * ( "/" segment )
path_rootless();					// segment_nz * ( "/" segment )
path_empty();					// ""
segment();					// * pchar
segment_nz();					// 1* pchar
segment_nz_nc();					// 1* ( unreserved / pct_encoded / sub_delims / "@" )
pchar();					// unreserved / pct_encoded / sub_delims / ":" / "@"
query();					// * ( pchar / "/" / "?" )
fragment();					// * ( pchar / "/" / "?" )
pct_encoded();					// "%" HEXDIG HEXDIG
unreserved();					// ALPHA / DIGIT / "-" / "." / "_" / "~"
reserved();					// gen_delims / sub_delims
gen_delims();					// ":" / "/" / "?" / "#" / "[" / "]" / "@"
sub_delims();					// "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="
language_range();					// ( 1*8 ALPHA * ( "-" 1*8 alphanum ) ) / "*"
alphanum();					// ALPHA / DIGIT
Language_Tag();					// langtag / privateuse / grandfathered
langtag();					// language [ "-" script ] [ "-" region ] * ( "-" variant ) * ( "-" extension ) [ "-" privateuse ]
language();					// 2*3 ALPHA [ "-" extlang ] / 4 ALPHA / 5*8 ALPHA
extlang();					// 3 ALPHA *2 ( "-" 3 ALPHA )
script();					// 4 ALPHA
region();					// 2 ALPHA / 3 DIGIT
variant();					// 5*8 alphanum / ( DIGIT 3 alphanum )
extension();					// singleton 1* ( "-" ( 2*8 alphanum ) )
singleton();					// DIGIT / %x41_57 / %x59_5A / %x61_77 / %x79_7A
privateuse();					// "x" 1* ( "-" ( 1*8 alphanum ) )
grandfathered();					// irregular / regular
irregular();					// "en_GB_oed" / "i_ami" / "i_bnn" / "i_default" / "i_enochian" / "i_hak" / "i_klingon" / "i_lux" / "i_mingo" / "i_navajo" / "i_pwn" / "i_tao" / "i_tay" / "i_tsu" / "sgn_BE_FR" / "sgn_BE_NL" / "sgn_CH_DE"
regular();					// "art_lojban" / "cel_gaulish" / "no_bok" / "no_nyn" / "zh_guoyu" / "zh_hakka" / "zh_min" / "zh_min_nan" / "zh_xiang"
BWS();					// OWS
Connection();					// * ( "," OWS ) connection_option * ( OWS "," [ OWS connection_option ] )
Content_Length();					// 1* DIGIT
HTTP_message();					// start_line * ( header_field CRLF ) CRLF [ message_body ]
HTTP_name();					// %x48.54.54.50
HTTP_version();					// HTTP_name "/" DIGIT "." DIGIT
Host();					// uri_host [ ":" port ]
OWS();					// * ( SP / HTAB )
RWS();					// 1* ( SP / HTAB )
TE();					// [ ( "," / t_codings ) * ( OWS "," [ OWS t_codings ] ) ]
Trailer();					// * ( "," OWS ) field_name * ( OWS "," [ OWS field_name ] )
Transfer_Encoding();					// * ( "," OWS ) transfer_coding * ( OWS "," [ OWS transfer_coding ] )
Upgrade();					// * ( "," OWS ) protocol * ( OWS "," [ OWS protocol ] )
Via();					// * ( "," OWS ) ( received_protocol RWS received_by [ RWS comment ] ) * ( OWS "," [ OWS ( received_protocol RWS received_by [ RWS comment ] ) ] )
absolute_form();					// absolute_URI
absolute_path();					// 1* ( "/" segment )
asterisk_form();					// "*"
authority_form();					// authority
chunk();					// chunk_size [ chunk_ext ] CRLF chunk_data CRLF
chunk_data();					// 1* OCTET
chunk_ext();					// * ( ";" chunk_ext_name [ "=" chunk_ext_val ] )
chunk_ext_name();					// token
chunk_ext_val();					// token / quoted_string
chunk_size();					// 1* HEXDIG
chunked_body();					// * chunk last_chunk trailer_part CRLF
comment();					// "(" * ( ctext / quoted_pair / comment ) ")"
connection_option();					// token
ctext();					// HTAB / SP / %x21_27 / %x2A_5B / %x5D_7E / obs_text
field_content();					// field_vchar [ 1* ( SP / HTAB ) field_vchar ]
field_name();					// token
field_value();					// * ( field_content / obs_fold )
field_vchar();					// VCHAR / obs_text
http_URI();					// "http://" authority path_abempty [ "?" query ] [ "#" fragment ]
https_URI();					// "https://" authority path_abempty [ "?" query ] [ "#" fragment ]
last_chunk();					// 1* "0" [ chunk_ext ] CRLF
message_body();					// * OCTET
method();					// token
obs_fold();					// CRLF 1* ( SP / HTAB )
obs_text();					// %x80_FF
origin_form();					// absolute_path [ "?" query ]
partial_URI();					// relative_part [ "?" query ]
protocol();					// protocol_name [ "/" protocol_version ]
protocol_name();					// token
protocol_version();					// token
pseudonym();					// token
qdtext();					// HTAB / SP / "!" / %x23_5B / %x5D_7E / obs_text
quoted_pair();					// "\" ( HTAB / SP / VCHAR / obs_text )
quoted_string();					// DQUOTE * ( qdtext / quoted_pair ) DQUOTE
rank();					// ( "0" [ "." *3 DIGIT ] ) / ( "1" [ "." *3 "0" ] )
reason_phrase();					// * ( HTAB / SP / VCHAR / obs_text )
received_by();					// ( uri_host [ ":" port ] ) / pseudonym
received_protocol();					// [ protocol_name "/" ] protocol_version
request_line();					// method SP request_target SP HTTP_version CRLF
request_target();					// origin_form
start_line();					// request_line / status_line
status_code();					// 3 DIGIT
status_line();					// HTTP_version SP status_code SP reason_phrase CRLF
t_codings();					// "trailers" / ( transfer_coding [ t_ranking ] )
t_ranking();					// OWS ";" OWS "q=" rank
tchar();					// "!" / "#" / "$" / "%" / "&" / "'" / "*" / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~" / DIGIT / ALPHA
token();					// 1* tchar
trailer_part();					// * ( header_field CRLF )
transfer_coding();					// "chunked" / "compress" / "deflate" / "gzip" / transfer_extension
transfer_extension();					// token * ( OWS ";" OWS transfer_parameter )
transfer_parameter();					// token BWS "=" BWS ( token / quoted_string )
uri_host();					// host
Accept();					// [ ( "," / ( media_range [ accept_params ] ) ) * ( OWS "," [ OWS ( media_range [ accept_params ] ) ] ) ]
Accept_Charset();					// * ( "," OWS ) ( ( charset / "*" ) [ weight ] ) * ( OWS "," [ OWS ( ( charset / "*" ) [ weight ] ) ] )
Accept_Encoding();					// [ ( "," / ( codings [ weight ] ) ) * ( OWS "," [ OWS ( codings [ weight ] ) ] ) ]
Accept_Language();					// * ( "," OWS ) ( language_range [ weight ] ) * ( OWS "," [ OWS ( language_range [ weight ] ) ] )
Allow();					// [ ( "," / method ) * ( OWS "," [ OWS method ] ) ]
Content_Encoding();					// * ( "," OWS ) content_coding * ( OWS "," [ OWS content_coding ] )
Content_Language();					// * ( "," OWS ) Language_Tag * ( OWS "," [ OWS Language_Tag ] )
Content_Location();					// absolute_URI / partial_URI
Content_Type();					// media_type
Date();					// HTTP_date
Expect();					// "100_continue"
GMT();					// %x47.4D.54
HTTP_date();					// IMF_fixdate / obs_date
IMF_fixdate();					// day_name "," SP date1 SP time_of_day SP GMT
Location();					// URI_reference
Max_Forwards();					// 1* DIGIT
Referer();					// absolute_URI / partial_URI
Retry_After();					// HTTP_date / delay_seconds
Server();					// product * ( RWS ( product / comment ) )
User_Agent();					// product * ( RWS ( product / comment ) )
Vary();					// "*" / ( * ( "," OWS ) field_name * ( OWS "," [ OWS field_name ] ) )
accept_ext();					// OWS ";" OWS token [ "=" ( token / quoted_string ) ]
accept_params();					// weight * accept_ext
asctime_date();					// day_name SP date3 SP time_of_day SP year
charset();					// token
codings();					// content_coding / "identity" / "*"
content_coding();					// token
date1();					// day SP month SP year
date2();					// day "-" month "-" 2 DIGIT
date3();					// month SP ( 2 DIGIT / ( SP DIGIT ) )
day();					// 2 DIGIT
day_name();					// %x4D.6F.6E / %x54.75.65 / %x57.65.64 / %x54.68.75 / %x46.72.69 / %x53.61.74 / %x53.75.6E
day_name_l();					// %x4D.6F.6E.64.61.79 / %x54.75.65.73.64.61.79 / %x57.65.64.6E.65.73.64.61.79 / %x54.68.75.72.73.64.61.79 / %x46.72.69.64.61.79 / %x53.61.74.75.72.64.61.79 / %x53.75.6E.64.61.79
delay_seconds();					// 1* DIGIT
hour();					// 2 DIGIT
media_range();					// ( "*/*" / ( type "/" subtype ) / ( type "/*" ) ) * ( OWS ";" OWS parameter )
media_type();					// type "/" subtype * ( OWS ";" OWS parameter )
minute();					// 2 DIGIT
month();					// %x4A.61.6E / %x46.65.62 / %x4D.61.72 / %x41.70.72 / %x4D.61.79 / %x4A.75.6E / %x4A.75.6C / %x41.75.67 / %x53.65.70 / %x4F.63.74 / %x4E.6F.76 / %x44.65.63
obs_date();					// rfc850_date / asctime_date
parameter();					// token "=" ( token / quoted_string )
product();					// token [ "/" product_version ]
product_version();					// token
qvalue();					// ( "0" [ "." *3 DIGIT ] ) / ( "1" [ "." *3 "0" ] )
rfc850_date();					// day_name_l "," SP date2 SP time_of_day SP GMT
second();					// 2 DIGIT
subtype();					// token
time_of_day();					// hour ":" minute ":" second
type();					// token
weight();					// OWS ";" OWS "q=" qvalue
year();					// 4 DIGIT
ETag();					// entity_tag
If_Match();					// "*" / ( * ( "," OWS ) entity_tag * ( OWS "," [ OWS entity_tag ] ) )
If_Modified_Since();					// HTTP_date
If_None_Match();					// "*" / ( * ( "," OWS ) entity_tag * ( OWS "," [ OWS entity_tag ] ) )
If_Unmodified_Since();					// HTTP_date
Last_Modified();					// HTTP_date
entity_tag();					// [ weak ] opaque_tag
etagc();					// "!" / %x23_7E
opaque_tag();					// DQUOTE * etagc DQUOTE
weak();					// %x57.2F
Accept_Ranges();					// acceptable_ranges
Content_Range();					// byte_content_range / other_content_range
If_Range();					// entity_tag / HTTP_date
Range();					// byte_ranges_specifier / other_ranges_specifier
acceptable_ranges();					// ( * ( "," OWS ) range_unit * ( OWS "," [ OWS range_unit ] ) ) / "none"
byte_content_range();					// bytes_unit SP ( byte_range_resp / unsatisfied_range )
byte_range();					// first_byte_pos "-" last_byte_pos
byte_range_resp();					// byte_range "/" ( complete_length / "*" )
byte_range_set();					// * ( "," OWS ) ( byte_range_spec / suffix_byte_range_spec ) * ( OWS "," [ OWS ( byte_range_spec / suffix_byte_range_spec ) ] )
byte_range_spec();					// first_byte_pos "-" [ last_byte_pos ]
byte_ranges_specifier();					// bytes_unit "=" byte_range_set
bytes_unit();					// "bytes"
complete_length();					// 1* DIGIT
first_byte_pos();					// 1* DIGIT
last_byte_pos();					// 1* DIGIT
other_content_range();					// other_range_unit SP other_range_resp
other_range_resp();					// * CHAR
other_range_set();					// 1* VCHAR
other_range_unit();					// token
other_ranges_specifier();					// other_range_unit "=" other_range_set
range_unit();					// bytes_unit / other_range_unit
suffix_byte_range_spec();					// "-" suffix_length
suffix_length();					// 1* DIGIT
unsatisfied_range();					// "*/" complete_length
Age();					// delta_seconds
Cache_Control();					// * ( "," OWS ) cache_directive * ( OWS "," [ OWS cache_directive ] )
Expires();					// HTTP_date
Pragma();					// * ( "," OWS ) pragma_directive * ( OWS "," [ OWS pragma_directive ] )
Warning();					// * ( "," OWS ) warning_value * ( OWS "," [ OWS warning_value ] )
cache_directive();					// token [ "=" ( token / quoted_string ) ]
delta_seconds();					// 1* DIGIT
extension_pragma();					// token [ "=" ( token / quoted_string ) ]
pragma_directive();					// "no_cache" / extension_pragma
warn_agent();					// ( uri_host [ ":" port ] ) / pseudonym
warn_code();					// 3 DIGIT
warn_date();					// DQUOTE HTTP_date DQUOTE
warn_text();					// quoted_string
warning_value();					// warn_code SP warn_agent SP warn_text [ SP warn_date ]
Proxy_Authenticate();					// * ( "," OWS ) challenge * ( OWS "," [ OWS challenge ] )
Proxy_Authorization();					// credentials
WWW_Authenticate();					// * ( "," OWS ) challenge * ( OWS "," [ OWS challenge ] )
auth_param();					// token BWS "=" BWS ( token / quoted_string )
auth_scheme();					// token
challenge();					// auth_scheme [ 1* SP ( token68 / [ ( "," / auth_param ) * ( OWS "," [ OWS auth_param ] ) ] ) ]
credentials();					// auth_scheme [ 1* SP ( token68 / [ ( "," / auth_param ) * ( OWS "," [ OWS auth_param ] ) ] ) ]
Authorization();					// credentials
token68();					// 1* ( ALPHA / DIGIT / "-" / "." / "_" / "~" / "+" / "/" ) * "="
Connection_header();					// "Connection" ":" OWS Connection OWS
Content_Length_header();					// "Content_Length" ":" OWS Content_Length OWS
Content_Type_header();					// "Content_Type" ":" OWS Content_Type OWS
Trailer_header();					// "Trailer" ":" OWS Trailer OWS
Transfer_Encoding_header();					// "Transfer_Encoding" ":" OWS Transfer_Encoding OWS
Upgrade_header();					// "Upgrade" ":" OWS Upgrade OWS
Via_header();					// "Via" ":" OWS Via OWS
Age_header();					// "Age" ":" OWS Age OWS
Expires_header();					// "Expires" ":" OWS Expires OWS
Date_header();					// "Date" ":" OWS Date OWS
Location_header();					// "Location" ":" OWS Location OWS
Retry_After_header();					// "Retry_After" ":" OWS Retry_After OWS
Vary_header();					// "Vary" ":" OWS Vary OWS
Warning_header();					// "Warning" ":" OWS Warning OWS
Cache_Control_header();					// "Cache_Control" ":" OWS Cache_Control OWS
Expect_header();					// "Expect" ":" OWS Expect OWS
Host_header();					// "Host" ":" OWS Host OWS
Max_Forwards_header();					// "Max_Forwards" ":" OWS Max_Forwards OWS
Pragma_header();					// "Pragma" ":" OWS Pragma OWS
Range_header();					// "Range" ":" OWS Range OWS
TE_header();					// "TE" ":" OWS TE OWS
If_Match_header();					// "If_Match" ":" OWS If_Match OWS
If_None_Match_header();					// "If_None_Match" ":" OWS If_None_Match OWS
If_Modified_Since_header();					// "If_Modified_Since" ":" OWS If_Modified_Since OWS
If_Unmodified_Since_header();					// "If_Unmodified_Since" ":" OWS If_Unmodified_Since OWS
If_Range_header();					// "If_Range" ":" OWS If_Range OWS
Accept_header();					// "Accept" ":" OWS Accept OWS
Accept_Charset_header();					// "Accept_Charset" ":" OWS Accept_Charset OWS
Accept_Encoding_header();					// "Accept_Encoding" ":" OWS Accept_Encoding OWS
Accept_Language_header();					// "Accept_Language" ":" OWS Accept_Language OWS
Authorization_header();					// "Authorization" ":" OWS Authorization OWS
Proxy_Authorization_header();					// "Proxy_Authorization" ":" OWS Proxy_Authorization OWS
Referer_header();					// "Referer" ":" OWS Referer OWS
User_Agent_header();					// "User_Agent" ":" OWS User_Agent OWS
cookie_pair();					// cookie_name "=" cookie_value
cookie_name();					// token
cookie_value();					// ( DQUOTE * cookie_octet DQUOTE ) / * cookie_octet
cookie_octet();					// %x21 / %x23_2B / %x2D_3A / %x3C_5B / %x5D_7E
Cookie_header();					// "Cookie:" OWS cookie_string OWS
cookie_string();					// cookie_pair * ( ";" SP cookie_pair )
header_field();					// Connection_header / Content_Length_header / Content_Type_header / Cookie_header / Transfer_Encoding_header / Expect_header / Host_header / Accept_header / Accept_Charset_header / Accept_Encoding_header / Accept_Language_header / Referer_header / User_Agent_header / ( field_name ":" OWS field_value OWS )
