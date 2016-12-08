#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "conversion.h"

int pow2(int a , int b){
	int result = 1;
	int i ;
	for(i =0;i <b;i++){
		result = result * a;
	}
	return result;
}

int tperm(int x, int *chiffres)
{
  int i = 0;
  int cpt = 3;	
  while (cpt != 0)
    {
      chiffres[i++] = x % 10;
      x /= 10;
      cpt--;
    }
  return i;
}
 

int tperm2(int x, int *chiffres)
{
  int i = 0;
  int cpt = 2;	
  while (cpt != 0)
    {	
		
      chiffres[i++] = x % 10;
	
      x /= 10;
      cpt--;
    }
  return i;
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

int OtoD(int Octale){
  int res;
  int chiffres[12] = { 0 };
  RecuperationOctale(chiffres,Octale);
  res = CalculOctale(chiffres);
  return res;
}

long int OctalToDecimal(long int octalNumber){
  long int decimalNumber=0;
  int i=0;
  while(octalNumber!=0){
    decimalNumber += (octalNumber%10)*pow2(8,i);
    ++i;
    octalNumber/=10;
  }

  i=1;

  return decimalNumber;

}
