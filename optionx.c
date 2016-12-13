#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>
#include "fctFinFichier.h"
#include "listing.h"
#include "conversion.h"
#include "date.h"








void ecrire(int fd1, int fd2,int size,int p){
	char buf;
	int cpt = size;
	int rc;
	while (cpt > 0){
		p = read(fd1, &buf, 1);
		p = write(fd2, &buf, 1);
		cpt = cpt-1;
	}
}

void optionx (char * doc){

char typed[8] ;

int size;
int sizetoread;
int cpttest = 0;

int fd = open(doc,O_RDWR|O_CREAT,0666);
struct mastruct s;
int p ;
while(finDeFichier2(fd)!=1){
	lseek(fd,-512,SEEK_CUR);
	p =read(fd,&s, 512);

	int chiffres[12] = { 0 };
	mode_t mode = OtoD(atoi (s.mode));
	int flag = atoi(s.typeflag);
	uid_t uid = OtoD(atoi(s.uid));
	gid_t gid = OtoD(atoi(s.gid));
	int size = OtoD(atoi(s.size)); 
	long int date = atol(s.mtime);
	long int dated = OctalToDecimal(date);
	

	

	strcpy(typed,s.typeflag);

	RecuperationOctale(chiffres,atoi(s.size));
	size = CalculOctale(chiffres); 
	sizetoread = aread(size);

	if(atoi(typed) == 5 ){
		int g = mkdir(s.name , 0777);
		
		lecture(fd,sizetoread);
	}

	if(atoi(typed) == 0 ){
		
		int fd2 = open(s.name,O_WRONLY|O_CREAT,0666);
		
		ecrire(fd,fd2,size,p);
		lseek(fd,-size,SEEK_CUR);
		close(fd2);
	}

	if(atoi(typed) == 2){
	
	symlink(s.linkname,s.name); 
	
	}

	int diff = sizetoread - size;

	lecture(fd,sizetoread);

	cpttest ++;
	
	

	}

//}


	close (fd);

int fd2 = open(doc,O_RDWR|O_CREAT,0666);
struct utimbuf time;

while(finDeFichier2(fd2)!=1){
	lseek(fd2,-512,SEEK_CUR);
	p =read(fd2,&s, 512);
	int chiffres[12] = { 0 };
	mode_t mode = OtoD(atoi (s.mode));
	int flag = atoi(s.typeflag);
	uid_t uid = OtoD(atoi(s.uid));
	gid_t gid = OtoD(atoi(s.gid));
	int size = OtoD(atoi(s.size)); 
	long int date = atol(s.mtime);
	long int dated = OctalToDecimal(date);
	time.actime = (time_t) dated;
	time.modtime = (time_t) dated;	

	utime(s.name,&time);
	chmod(s.name,mode);
	chown(s.name,uid,gid);
	
	
	
	int diff = sizetoread - size;

	lecture(fd2,sizetoread);
}


close (fd2);





}
