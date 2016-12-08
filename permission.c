
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include "conversion.h"




void  permission(int mode,int flag){
	int chiffresstock[3] = {0};
	int chiffresstock2[2] = {0};
	//char  *res = malloc(10 * sizeof(char));
	int i;
	char res[10] = {'a'};
	tperm(mode,chiffresstock);
	if(flag == 0){
		res[0] = '-';
	}

	if(flag == 5){
		res[0] = 'd';
	}
	




	tperm(mode,chiffresstock);
	for(i =2; i>-1;i--){

		
		if(chiffresstock[i] == 0){
			
			res[6-3*i+1] = '-';
			res[6-3*i+2] = '-';
			res[6-3*i+3] = '-';
		}
		if(chiffresstock[i] == 1){
			res[6-3*i+1] = '-';
			res[6-3*i+2] = '-';
			res[6-3*i+3] = 'x';
		}

		if(chiffresstock[i] == 2){
			res[6-3*i+1] = '-';
			res[6-3*i+2] = 'w';
			res[6-3*i+3] = '-';
		}

		if(chiffresstock[i] == 3){
			res[6-3*i+1] = '-';
			res[6-3*i+2] = 'w';
			res[6-3*i+3] = 'x';
		}

		if(chiffresstock[i] == 4){
			res[6-3*i+1] = 'r';
			res[6-3*i+2] = '-';
			res[6-3*i+3] = '-';
		}

		if(chiffresstock[i] == 5){
			res[6-3*i+1] = 'r';
			res[6-3*i+2] = '-';
			res[6-3*i+3] = 'x';
		}

		if(chiffresstock[i] == 6){
			res[6-3*i+1] = 'r';
			res[6-3*i+2] = 'w';
			res[6-3*i+3] = '-';
		}
		if(chiffresstock[i] == 7){

			res[6-3*i+1] = 'r';
			res[6-3*i+2] = 'w';
			res[6-3*i+3] = 'x';
		}	
		
	
	}
printf("%s",res );
}



/*int main(){
	int x = 074;
	


	
	printf("test : %d\n", x % 10);
	permission(atoi("106"),5);
	
	

	return 0;
}*/
