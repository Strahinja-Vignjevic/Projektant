#include <stdio.h>
#include <stdlib.h>
#include "plaky.h"
#include <string.h>
int main()
{
    FILE* n= fopen("nalozi.txt","r+");
    int i=0,j=0,k=0,l=0,m=0;
ispisivanje:
    j=ispis(i);
    if (j < 1){
        printf("Nema te opcije!!!\n");
        goto ispisivanje;
    }else if(j > 6){
        printf("Nema te opcije!!!\n");
        goto ispisivanje;
    }
    switch(i){
case 1:
    registracija(k);
    k++;
    goto ispisivanje;
    break;
case 2:
    if(l==1){
        printf("Vec ste ulogovani!!\n");
        goto ispisivanje;
    }
    l=logovanje();
    goto ispisivanje;
    break;
case 3:
    if(l==0){
        printf("Niste ulogovani uopste!!!");
        goto ispisivanje;
    }
    izlogovanje(l,m);
    goto ispisivanje;
    break;
case 4:
    if(l==0){
        printf("Niste ulogovani uopste!!!");
        goto ispisivanje;
    }
    menjanje_naloga(m);
    goto ispisivanje;
    break;
case 5:
    if(l==0){
        printf("Niste ulogovani uopste!!!");
        goto ispisivanje;
    }
    brisanje_naloga(m);
    goto ispisivanje;
    break;
case 6:
    break;
    }
    return 0;
}
