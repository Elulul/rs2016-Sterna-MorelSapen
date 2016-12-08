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





void conversiondate(long int date){




	char *p_conv;
	//printf("%ld\n",itime);
	char buf[80];
	time_t tt = (time_t) date;
	strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S",localtime(&tt));
	printf("%s",buf);
}

/*void updatedate(long int date, char * nomFichier){
	char buf[80];
	time_t tt = (time_t) date;
	strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S",localtime(&tt));
	
	utime(nomFichier, buf);
}
*/
/*int main(){
	time_t t = time(NULL);
	time_t t2 = 295602087;
	printf("ceci est ma date : %ld\n",t );
	printf("ceci est ma date : %ld\n",t2 );
	conversiondate(t2);
}*/
