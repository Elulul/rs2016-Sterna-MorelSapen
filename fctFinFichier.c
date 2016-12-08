#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


int finDeFichier2(int fd){
	//printf("debut finDeFichier\n");
	int p ;
	int bool = 1;
	int i;
	char  tampon[512];
		p =read(fd, &tampon,512);
		if(p < 0) {
			perror("read");
			exit(1);
		}

	for (i =0; i<512 ; i++){
		if (tampon[i] != (char) 0){
			bool =0;
		}
	}
	//printf("%d\n",bool);
	


	return bool;

}



int aread(int size){
	if((size % 512) == 0){
		return (size / 512);
	}
	else{
		return((size /= 512) +1);
	}

}