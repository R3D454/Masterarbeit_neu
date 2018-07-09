#ifndef SEND_RECV_DATA_H
#define SEND_RECV_DATA_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>


#define BUFSIZE 500


void send_data(char buf[BUFSIZE], int size, char DST1[15],  int  PORT );
void recv_data (int PORT,char* buf);
int init_socket_recv(int port);




#endif
