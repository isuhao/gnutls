#ifndef AUTH_SRP_H
# define AUTH_SRP_H

#include <gnutls_auth.h>

typedef struct {
	char* username;
	char* password;
} SRP_CLIENT_CREDENTIALS_INT;

#define gnutls_srp_client_credentials SRP_CLIENT_CREDENTIALS_INT*

typedef struct {
	char** password_file;
	char** password_conf_file;
	int password_files;
} SRP_SERVER_CREDENTIALS_INT;

#define gnutls_srp_server_credentials SRP_SERVER_CREDENTIALS_INT*

/* these structures should not use allocated data */
typedef struct SRP_SERVER_AUTH_INFO_INT {
	char username[MAX_SRP_USERNAME];
} *SRP_SERVER_AUTH_INFO;

#ifdef ENABLE_SRP

int _gnutls_proc_srp_server_hello(gnutls_session state, const opaque * data, size_t data_size);
int _gnutls_gen_srp_server_hello(gnutls_session state, opaque * data, size_t data_size);

int _gnutls_gen_srp_server_kx2(gnutls_session, opaque **);
int _gnutls_gen_srp_client_kx0(gnutls_session, opaque **);

int _gnutls_proc_srp_server_kx2(gnutls_session, opaque *, size_t);
int _gnutls_proc_srp_client_kx0(gnutls_session, opaque *, size_t);

typedef struct  SRP_SERVER_AUTH_INFO_INT  SRP_SERVER_AUTH_INFO_INT;

#endif /* ENABLE_SRP */

#endif
