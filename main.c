#include <stdio.h>
#include <stdlib.h>
#include "plaky.h"
#include <string.h>
#include <time.h>

int main()
{
    FILE* n= fopen("nalozi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.");
        return 1;
    }
    int i=0,j=0,k=0,l=0,r=0,t=0,e=0;
do{

do{
    j=ispis(i);
    if (j < 1){
        printf("Nema te opcije!!!\n");
    }else if(j > 7){
        printf("Nema te opcije!!!\n");
    }
}while(j>7 || j<1);
    switch(j){
case 1:
    registracija();
    break;
case 2:
    if(l==1){
        printf("Vec ste ulogovani!!\n");
    }
    k=logovanje();
    if(k>0){
        l++;
    }
    break;
case 3:
    if(l==0){
        printf("Niste ulogovani uopste!!!");
        break;
    }
    l=izlogovanje(l);
    break;
case 4:
    if(l==0){
        printf("Niste ulogovani uopste!!!");
        break;
    }
    menjanje_naloga(k);
    break;
case 5:
    if(l==0){
        printf("Niste ulogovani uopste!!!");
        break;
    }
    brisanje_naloga(k);
    break;
case 6:
    r=bolji_ispis(i);
    do{
    r=ispis(i);
    if (r < 1){
        printf("Nema te opcije!!!\n");
    }else if(r > 6){
        printf("Nema te opcije!!!\n");
    }
}while(r>7 || r<1);
do{
    switch(r){
case 1:
    if(l==0){
        printf("Niste ulogovani uopste!!!");
        break;
    }
    dodavanje_videa(k,t);
    break;
case 2:
    if(l==0){
        printf("Niste ulogovani uopste!!!");
        break;
    }
    izmena_videa(k,t);
    break;
case 3:
    if(l==0){
        printf("Niste ulogovani uopste!!!");
        break;
    }
    brisanje_videa(k,t);
    break;
case 4:
    home_page(t,l,e);
    break;
case 5:
    pretraga(t,l,e);
    break;
case 6:
    printf("Vracate se na glavni meni");
    break;
    }
}while(r!=6);
    break;
case 7:
    printf("Aj cao");
    }
}while(j!=7);
    return 0;
}
