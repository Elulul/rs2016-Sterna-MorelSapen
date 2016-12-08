#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "conversion.h"
#include "fctFinFichier.h"
#include "listing.h"
#include "optionx.h"



	
	int main(int argc, char *argv[]){
    struct mastruct test;
    int c;
    int tfnd;
    char optstring[]="lxpz";
    int cpt = -1;
    int cpt2 = 0;
    char enr[6];
    int i ;

    for (i =0; i < 6 ; i++){
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
