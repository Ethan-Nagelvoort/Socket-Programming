#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SIZE 1
int main(int count, char *ServMsg[])
{
int soccet;
soccet = socket(AF_INET,SOCK_STREAM,0);
if (soccet == -1) {
 printf("Socket has not been created yet \n");
 exit(0);
 }
if(count < 2){
exit(-1);
}
struct sockaddr_in serverAddr;
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(atoi(ServMsg[2]));
serverAddr.sin_addr.s_addr = inet_addr(ServMsg[1]);
int connecting_status = connect(soccet,(struct sockaddr *)
&serverAddr,sizeof(serverAddr));
 if(connecting_status == -1)
 {
 exit(-1);
 }
FILE *fp;
fp=fdopen(soccet,"w");
if (fp == NULL)
{
exit(-1);
}
char client_message[4096]="";
printf("Please enter a message - ");
int i = 0;
while ((client_message[i++] = getchar()) != '\n');
printf( "The entered message is: ");
puts( client_message );
fwrite(client_message, SIZE, sizeof(client_message), fp);
char serverMessage[4096]="";
fp=fdopen(soccet,"r+");
if (fp == NULL){
 exit(-1);
}
fread(serverMessage, SIZE, sizeof(serverMessage), fp);
printf("Message from server: %s\n",serverMessage);
strcpy(serverMessage, "");
strcpy(client_message, "");
close(soccet);
return 0;
}
