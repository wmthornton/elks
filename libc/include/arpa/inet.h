#include <netinet/in.h>
#include <sys/socket.h>

ipaddr_t in_aton(const char *str);
int	     in_connect(int socket, const struct sockaddr *address, socklen_t address_len,
			int secs);
ipaddr_t in_gethostbyname(char *str);
char *   in_ntoa(ipaddr_t in);
ipaddr_t in_resolv(char *hostname, char *server);
