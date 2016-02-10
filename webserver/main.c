#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include "socket.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void){
	int socket_serveur = creer_serveur(8080);
	initialiser_signaux();
	//if(fork()==0){
while(1){
		int socket_client ;
		socket_client = accept ( socket_serveur , NULL , NULL );
		if ( socket_client == -1){
			perror ( " accept " );
			/* traitement d ’ erreur */
		}
		/* On peut maintenant dialoguer avec le client */

		const char * message_bienvenue = " Bonjour , bienvenue sur mon serveur \n\n\n\n\n\n\n\n\n\n !\n" ; // les 10 lignes du serveur 
		//différent que d'envoyer  10 fois le même message
		//int i = 0;
		//for(i = 0;i<10;i++){
			//sleep(1);
			
			

			
			
			write ( socket_client , message_bienvenue , strlen ( message_bienvenue ));
			while(1){
				char buf[1024];
				int j=read(socket_client,buf,1024);
				if ( j == -1){
					perror ("read");
				/* traitement d ’ erreur */
				}
				buf[j]='\0';
				write ( socket_client , buf, strlen (buf));
			
			}
		//}
			
		
		
	//}
}
	return 0;
} 


