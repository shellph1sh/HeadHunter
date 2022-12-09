// Client side C/C++ program to demonstrate Socket
// programming
#include <stdio.h>
#include <sys/socket.h> 
#include <stdlib.h>
#include <netinet/in.h> 
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>

//Note the comments for variables in server code
int main(){

  char message[100];
  struct sockaddr_in serv; 
  int fd; 
  int conn; 
  int valread;

  fd = socket(AF_INET, SOCK_STREAM, 0);

  serv.sin_family = AF_INET;
  serv.sin_port = htons(4444);

  inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr); //Binds client to localhost

  connect(fd, (struct sockaddr *)&serv, sizeof(serv)); //connects client to server
  
  conn = accept(fd, (struct sockaddr *)NULL, NULL);
 
  while(1){
    fflush(stdout);

    valread = read(fd, message, 100);
    
    if(valread > 0){

      printf("Message Received: %s\n", message);
    
    }  
  
}

  return 0;
}
