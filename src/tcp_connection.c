#include "tcp_connection.h"

int sock;
int data_size = DEFAULT_DATA_SIZE;

int tcp_connect(char * ip_addr, char * prt){
    int count, datalen;
    in_port_t destport;
    struct sockaddr_in mysocket, destsocket;
    struct in_addr dest_ip;
    socklen_t sktlen;
    int i, err;

    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof hints);
    hints.ai_socktype = SOCK_STREAM;
    if ((err = getaddrinfo(ip_addr, prt, &hints, &res)) < 0) {
           fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
           return -1;
    }
    //set all vars
    destport = atoi(prt);

    //set source(this) socket
    memset(&mysocket, 0, sizeof mysocket);
    mysocket.sin_family = AF_INET;
    mysocket.sin_port = htons(0);
    mysocket.sin_addr.s_addr = htonl(INADDR_ANY);

    //open socket
    if ((sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0){
        perror("socket");
        return -1;
    }
    //Receive from server
    if (connect(sock, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        return -1;
    }
    freeaddrinfo(res);

    return 0;
}

int tcp_send(void * buf, size_t len){
    if(send(sock, buf, len, 0) < 0){
        perror("send");
        return -1;
    }
    return 0;
}

char * tcp_recv(){
    return NULL;
}

int tcp_close(){
    close(sock);
    return 0;
}

void tcp_set_data_size(int d_size){
    data_size = d_size;
}
