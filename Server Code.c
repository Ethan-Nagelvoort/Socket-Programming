#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#define SIZE 1
int main(int count, char *cmsg[])
{
printf("SERVER");
struct sockaddr_in serverAddr, clientAddr;
socklen_t client_length=sizeof(clientAddr);
int server_socket;
server_socket = socket(AF_INET, SOCK_STREAM, 0);
if(count < 2){
exit(-1);
}
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(atoi(cmsg[1]));
serverAddr.sin_addr.s_addr = inet_addr("130.191.166.3");
 if (bind(server_socket, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) !=0)
 {
 exit(0);
 }
for(;;)
{
if ((listen(server_socket, 5)) != 0)
{
 exit(0);
 }
char clientMsg[4096] ="";
int clientSocket;
clientSocket = accept(server_socket,(struct sockaddr *) &clientAddr, &client_length);
if (clientSocket < 0)
{
exit(0);
}
FILE *fn;
fn=fdopen(clientSocket,"r");
if (fn == NULL){
 exit(-1);
}
fread(clientMsg, SIZE, sizeof(clientMsg), fn);
printf("Client message: %s",clientMsg);
if (strncmp("exit",clientMsg,4)==0)
{
break;
}
char reverse_string[4096]= "";
int x=0;
int i;
for (i = strlen(clientMsg)-1;i>=0;i--)
{
reverse_string[x]=clientMsg[i];
x ++;
}
fn=fdopen(clientSocket,"w");
if (fn == NULL){
exit(-1);
}
fwrite(reverse_string, SIZE, sizeof(reverse_string), fn);
send(clientSocket, reverse_string, sizeof(reverse_string), 0);
printf("The server sent the reverse string: %s ",reverse_string);
strcpy(reverse_string, "");
strcpy(clientMsg, "");
}
close(server_socket);
return 0;
}
