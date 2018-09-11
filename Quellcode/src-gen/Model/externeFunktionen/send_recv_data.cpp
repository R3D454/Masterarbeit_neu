#include"send_recv_data.h"


#define BUFSIZE 500


void send_data(char buf[BUFSIZE], int size, char DST1[15],  int  PORT ) {

  struct sockaddr_in local, remote;		// Adress-Struktur
  int len_remote = sizeof(remote);
  int s = 0;                          // Socket


  // Initialisierung der Adress Strukturen mit "0"
  memset((char *) &remote, 0, sizeof(remote));
  memset((char *) &local, 0, sizeof(remote));


  // socket zur Benutzung mit UDP anfordern
  if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
    fprintf(stderr, "Error getting socket ! \n");
    exit(-1);
  }

  // lokale Addressstruktur für Bindung an den Dienst erzeugen
  remote.sin_family = AF_INET;
  remote.sin_port = htons(PORT);
  if(inet_aton(DST1,&remote.sin_addr)==0)
  {
    std::cout << "inet_aton() failed\n" <<std::endl;
  }

  if(sendto(s,buf,size,0,(struct sockaddr *)&remote,len_remote)==-1)
  {
    std::cout <<"fehler beim Senden" << std::endl;
    exit(-1);
  }

  close(s);

}



void recv_data (int PORT,char * buf) {

  //int len = 0;
  memset(buf, 0, BUFSIZE);

  struct sockaddr_in local, remote;		// Adress-Struktur
  int len_remote = sizeof(remote);
  int s = 0;                          // Socket

  // Initialisierung der Adress Strukturen mit "0"
	memset((char *) &remote, 0, sizeof(remote));
	memset((char *) &local, 0, sizeof(remote));

  // socket zur Benutzung mit UDP anfordern
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
		fprintf(stderr, "Error getting socket ! \n");
		exit(-1);
	}

  // lokale Addressstruktur für Bindung an den Dienst erzeugen
	local.sin_family = AF_INET;
	local.sin_port = htons(PORT);
  local.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(s,(struct sockaddr *)&local,sizeof(local))==-1)
  {
    fprintf(stderr, "konnte nicht mit dem Dienst verbinden\n" );
    exit(-1);
  }

  if(recvfrom(s,buf,BUFSIZE,0,(struct sockaddr *)&remote,(socklen_t *)&len_remote)==-1)
  {
    fprintf(stderr, "Fehler beim Lesen\n");
    exit(-1);
  }

  close(s);

}


int init_socket_recv(int port){

  struct sockaddr_in local, remote;		// Adress-Struktur
  //int len_remote = sizeof(remote);
  int s = 0;                          // Socket

  // Initialisierung der Adress Strukturen mit "0"
 memset((char *) &remote, 0, sizeof(remote));
 memset((char *) &local, 0, sizeof(remote));

  // socket zur Benutzung mit UDP anfordern
 if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
   fprintf(stderr, "Error getting socket ! \n");
   exit(-1);
 }

  // lokale Addressstruktur für Bindung an den Dienst erzeugen
 local.sin_family = AF_INET;
 local.sin_port = htons(port);
 local.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(s,(struct sockaddr *)&local,sizeof(local))==-1)
  {
    fprintf(stderr, "konnte nicht mit dem Dienst verbinden\n" );
    exit(-1);
  }



return s;
}
