
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "fctFinFichier.h"
#include "listing.h"
#include "conversion.h"




/*	printf("debut finDeFichier\n");
	int cpt = 0;
	int p ;
	char  tampon[1];
	while (cpt != 512){
		printf("%d\n",cpt);
		printf("%c\n",*tampon);
		p =read(fd, &tampon,1);
		if(p < 0) {
			perror("read");
			exit(1);
		}
		if(p == 0){
			break;
		}	
		if(p < 0) {
				perror("write");
			exit(1);
		}
		if(p!= 1) {
			fprintf(stderr, "Écriture interrompue");
			exit(1);
				
		}
		if( * tampon == '0'){
			
			cpt ++;
		}
		
		else{
			printf("fin 0\n\n");
			return 0;

		}
		
	}
	printf("fin 1\n\n");
	return 1;

}*/




void lecture(int fd ,int sizealire){
	char  tampon[512];
	int p;
	for(int i =0; i<sizealire;i++){
		p =read(fd, &tampon,512);

		}
	}
	



void listing(char * doc){


int size;
int sizetoread;
int cpttest = 0;
struct mastruct s;
int fd = open(doc,O_RDONLY,0);
//printf("chameau1\n");
int p ;
//printf("chameau2\n");
//while(finDeFichier2(fd) != 1){
while(finDeFichier2(fd)!=1){
	lseek(fd,-512,SEEK_CUR);
	int chiffres[12] = { 0 };/* int sur 32 bits */

	//printf("on lit\n" );
	p =read(fd,&s, 512);
//printf("chameau3\n");
	printf("%s\n",s.name );

	//printf("chameau4\n");
	//char nom[sizeof(test.name)];
	//memcpy ( &nom, &test.name, sizeof(test.name) );
	//printf("%d\n",atoi(test.size) );
	
	RecuperationOctale(chiffres,atoi(s.size));
	size = CalculOctale(chiffres); 
	//printf("ceci est ma size en décimal :%d\n",size);
	sizetoread = aread(size);
	//printf("ceci est ma size a lire :%d\n",sizetoread);
	cpttest ++;
	lecture(fd,sizetoread);
	

	}
	
//}



	close (fd);

}