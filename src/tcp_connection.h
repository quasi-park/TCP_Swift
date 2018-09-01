/*** INCLUDE ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

/*** DEFINE ***/
#define DEFAULT_DATA_SIZE 256

/*** PROTOTYPE ***/
int tcp_connect(char * ip_addr, char * prt);
int tcp_send(void * buf, size_t len);
char * tcp_recv();
int tcp_close();
void tcp_set_data_size(int d_size);
