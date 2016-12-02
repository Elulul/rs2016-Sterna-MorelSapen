
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "listing.h"



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


int finDeFichier2(int fd){
	//printf("debut finDeFichier\n");
	int cpt = 0;
	int p ;
	int bool = 1;
	char test[10] = "";
	int entier = 0;
	char zeros = (char)entier;
	int i;
	char  tampon[512];
		p =read(fd, &tampon,512);
		if(p < 0) {
			perror("read");
			exit(1);
		}

	for (i =0; i<512 ; i++){
		if (tampon[i] != zeros){
			bool =0;
		}
	}
	//printf("%d\n",bool);
	


	return bool;

}

int pow2(int a , int b){
	int result = 1;
	for(int i =0;i <b;i++){
		result = result * a;
	}
	return result;
}



int faux(int x, int *chiffres)
{
  int i = 0;
 
  while (x != 0)
    {
      chiffres[i++] = x % 10;
      x /= 10;
    }
  return i;
}
 
void * RecuperationOctale(int * chiffres,int x)
{

  int i, n = faux(x, chiffres);
  if (n == 0)
    {/*printf("0");*/}
  else{
  	  for (i = 0; i < n; i++){
  	  	//printf("%d ", chiffres[n - i - 1]);
  	  }
      
 
 // printf("\n");
  }
  
 
}

int CalculOctale(int * chiffres){
	int i = 0;
	int pui = 0;
	int result = 0;
	for (i=0;i<12;i++){
		
		result = result + (pow2(8,pui) * chiffres[i]);
		pui = pui +1;
	}
	return result;

}

int aread(int size){
	if((size % 512) == 0){
		return (size / 512);
	}
	else{
		return((size /= 512) +1);
	}

}

void lecture(int fd ,int sizealire){
	char  tampon[512];
	int p;
	for(int i =0; i<sizealire;i++){
		p =read(fd, &tampon,512);

		}
	}
	



void listing(char * doc){

struct mastruct test;
int size;
int sizetoread;
int cpttest = 0;

int fd = open(doc,O_RDONLY,0);
//printf("chameau1\n");
int p ;
//printf("chameau2\n");
//while(finDeFichier2(fd) != 1){
while(finDeFichier2(fd)!=1){
	lseek(fd,-512,SEEK_CUR);
	int chiffres[12] = { 0 };/* int sur 32 bits */

	//printf("on lit\n" );
	p =read(fd,&test, 512);
//printf("chameau3\n");
	printf("%s\n",test.name );

	//printf("chameau4\n");
	//char nom[sizeof(test.name)];
	//memcpy ( &nom, &test.name, sizeof(test.name) );
	//printf("%d\n",atoi(test.size) );
	
	RecuperationOctale(chiffres,atoi(test.size));
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







void ecrire(int fd1, int fd2,int size,int p){
	char buf;
	int cpt = size;
	int rc;
	while (cpt > 0){
		//printf("buf : %s",buf);
		p = read(fd1, &buf, 1);
		p = write(fd2, &buf, 1);
		cpt = cpt-1;
	}
}

void optionx (char * doc){
struct mastruct test;
char typed[8] ;

int size;
int sizetoread;
int cpttest = 0;

int fd = open(doc,O_RDWR|O_CREAT,0666);
//printf("chameau1\n");

int p ;
//printf("chameau2\n");
//while(finDeFichier2(fd) != 1){
while(finDeFichier2(fd)!=1){
	lseek(fd,-512,SEEK_CUR);
	int chiffres[12] = { 0 };/* int sur 32 bits */
	
	
	//printf("on lit\n" );
	p =read(fd,&test, 512);
	strcpy(typed,test.typeflag);
//printf("chameau3\n");
	//printf("%s\n",test.name );
	//printf("%s\n",typed);

	RecuperationOctale(chiffres,atoi(test.size));
	size = CalculOctale(chiffres); 
	//printf("ceci est ma size en décimal :%d\n",size);
	sizetoread = aread(size);

	if(atoi(typed) == 5 ){
		int g = mkdir(test.name , 0700);
	//	printf("testreussite : %d\n",g);
		lecture(fd,sizetoread);
	}

	if(atoi(typed) == 0 ){
		
		int fd2 = open(test.name,O_WRONLY|O_CREAT,0666);
		ecrire(fd,fd2,size,p);
		lseek(fd,-size,SEEK_CUR);
		close(fd2);
	}
	int diff = sizetoread - size;

	//lecture(fd,diff);
	lecture(fd,sizetoread);


	//printf("chameau4\n");
	//char nom[sizeof(test.name)];
	//memcpy ( &nom, &test.name, sizeof(test.name) );
	//printf("%d\n",atoi(test.size) );
	
	
	//printf("ceci est ma size a lire :%d\n",sizetoread);
	cpttest ++;
	
	

	}

//}


	close (fd);
	printf("extraction terminée\n");
}
int main(int argc, char *argv[]){
    struct mastruct test;
    int c;
    int tfnd;
    char optstring[]="lxpz";
    int cpt = -1;
    int cpt2 = 0;
    char enr[6];
    for (int i =0; i < 6 ; i++){
        enr[i] = 'a';
    }

    tfnd = 0;
        while ((c = getopt(argc, argv, optstring)) != -1) {
        cpt = cpt + 1;
            switch(c){
                case 'l':
                 //printf("-%c\n",(char) c);
                 enr[cpt] =  (char) c;
                break;

                case 'x':
                //printf("x\n");
                enr[cpt] =  (char) c;
                break;

                case 'p':
                //printf("p\n");
                enr[cpt] =  (char) c;
                break;

                case 'z':
                //printf("z\n");
                enr[cpt] =  (char) c;
                break;




            }
        }    
    /*for (int i = 0; i <4 ; i++){
        printf("%c\n",enr[i]);
    } */   

        while(enr[cpt2] != 'a' ){
            if (enr[cpt2] == 'l')    {
            	//printf("%s\n",argv[argc-1]);
                listing(argv[argc-1]); 
            }

             if (enr[cpt2] == 'x'){
                optionx(argv[argc-1]); 
            }
            cpt2 ++;
        }
            

    return 0;
}