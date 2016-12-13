
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






void lecture(int fd ,int sizealire){
	char  tampon[512];
	int p;
	int i;
	for(i =0; i<sizealire;i++){
		p =read(fd, &tampon,512);

		}
	}

void listing(char * doc){



int sizetoread;
int cpttest = 0;
struct mastruct s;
int fd = open(doc,O_RDONLY,0);

int p ;

while(finDeFichier2(fd)!=1){
	lseek(fd,-512,SEEK_CUR);
	p =read(fd,&s, 512);
	int mode = atoi (s.mode);
	int flag = atoi(s.typeflag);
	int uid = OtoD(atoi(s.uid));
	int gid = OtoD(atoi(s.gid));
	int size = OtoD(atoi(s.size)); 	
	permission(mode,flag);
	printf(" %d/%d ",uid,gid);
	printf("%d ",size);
	long int date = atol(s.mtime);
	long int dated = OctalToDecimal(date);
	conversiondate(dated);
	printf(" %s\n",s.name );
	sizetoread = aread(size);
	cpttest ++;
	lecture(fd,sizetoread);
	}
	close (fd);

}
