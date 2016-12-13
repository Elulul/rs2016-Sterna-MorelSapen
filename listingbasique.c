
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "fctFinFichier.h"
#include "listing.h"
#include "conversion.h"
#include "date.h"
#include "permission.h"





void listingbasique(char * doc){

struct mastruct test;
int size;
int sizetoread;
int cpttest = 0;

int fd = open(doc,O_RDONLY,0);
int p ;

while(finDeFichier2(fd)!=1){
	lseek(fd,-512,SEEK_CUR);
	int chiffres[12] = { 0 };

	p =read(fd,&test, 512);

	printf("%s\n",test.name );
	RecuperationOctale(chiffres,atoi(test.size));
	size = CalculOctale(chiffres); 
	sizetoread = aread(size);
	cpttest ++;
	lecture(fd,sizetoread);
	

	}




	close (fd);

}



