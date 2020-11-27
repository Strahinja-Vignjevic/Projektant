#include <stdio.h>
#include <stdlib.h>
#include "plaky.h"
#include <string.h>
int provera_mejla(char* string){
    int i=0,j=0,k=0;
    for(i=0;i<100;i++){
        if(string[i]=='@'){
            j++;
        }
        if(j==1){
            break;
        }
    }
    if(j!=1){
        return k;
    }
    if(j==1){
        for(k=1;i<100 || k==1;i++){
            if(string[i]=='.'){
                k--;
                break;
            }
        }
    }
    if(k==1){
        return k;
    }
    if(k==0){
        return k;
    }
    return 0;
}
int ispis(int i){
    printf("***********************************\n");
    printf("*Uzaberite uslugu:                *\n");
    printf("*1. Registracija                  *\n");
    printf("*2. Ulogujte se                   *\n");
    printf("*3. Izlogujte se                  *\n");
    printf("*4. Izmenite nalog                *\n");
    printf("*5. Obrisite nalog                *\n");
    printf("*6. Izadjite iz programa          *\n");
    printf("***********************************\n");
    printf(">");
    scanf("%d",&i);
    return i;
}
void registracija(){
    nalog korisnik;

    int d;

    char loyinka[100];

    printf("Koje je Vase ime: ");
    gets(korisnik.ime);
    gets(korisnik.ime);

    printf("Koje je Vase prezime: ");
    gets(korisnik.prezime);

mejl:
    printf("Koja je Vasa mejl adresa: ");
    gets(korisnik.mejl);
    d=provera_mejla(korisnik.mejl);
    if(d==1){
        printf("Niste dobro uneli mejl!! Probajte opet!\n");
        goto mejl;
    }else if(d==0){
    printf("Uspesno unesen mejl!");
}
    printf("Koji je Vas nadimak: ");
    gets(korisnik.nadimak);

lozinka:
    printf("Koja je vasa lozinka: ");
    gets(korisnik.lozinka);
    printf("Ponovo unesite lozinku: ");
    gets(loyinka);
    if(strcmp(loyinka,korisnik.lozinka)!=0){
        printf("Niste dobro uneli lozinku! Probajte opet. \n");
        goto lozinka;
    }

    FILE* n= fopen("nalozi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return;
    }
    fseek(n,0,SEEK_END);
    fprintf(n,"%s",korisnik.ime);
    fputc(' ',n);
    fprintf(n,"%s",korisnik.prezime);
    fputc(' ',n);
    fprintf(n,"%s",korisnik.mejl);
    fputc(' ',n);
    fprintf(n,"%s",korisnik.nadimak);
    fputc(' ',n);
    fprintf(n,"%s",korisnik.lozinka);
    fprintf(n,"\n");
    fclose(n);
}
int logovanje(){
    int i,p=0;
    char y;
    nalog registrovan[100];
    FILE* n= fopen("nalozi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return 0;
    }
     for (i=0;; i++){
        if(feof(n)){
            break;
        }
        fscanf(n,"%s",registrovan[i].ime);
        fgetc(n);
        fscanf(n,"%s",registrovan[i].prezime);
        fgetc(n);
        fscanf(n,"%s",registrovan[i].mejl);
        fgetc(n);
        fscanf(n,"%s",registrovan[i].nadimak);
        fgetc(n);
        fscanf(n,"%s",registrovan[i].lozinka);
        fgetc(n);
    }
pocetak:
    printf("Unesite nadimak ili mejl: ");
    char niz[100],loyinka[100];
    gets(niz);
    gets(niz);

    for(i=0;i<100;i++){
        if(strcmp(niz,registrovan[i].mejl)==0 || strcmp(niz,registrovan[i].nadimak)==0){
            p++;
            printf("puko si");
            printf("Unesite lozinku tog naloga: ");
            gets(loyinka);
            if(strcmp(loyinka,registrovan[i].lozinka)==0){
                p++;
                printf("tek sada");
            }
        }
    }

greska:
    if(p==0){
        printf("Niste dobro uneli mejl,nadimak ili lozinku! Da li zelite da probate ponovo(y/n): ");
        scanf("%c",&y);
        if(y=='y' || y=='Y'){
            goto pocetak;
        }else if(y=='n' || y=='N'){
            return 0;
        }else
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
        goto greska;
    }
    printf("Uspesno ste ulogovani!!!\n");

    return i;
}
int izlogovanje(int l){
    l--;
    printf("Uspesno ste izlogovani! \n");
    return l;
}
void menjanje_naloga(int i){
    FILE* n= fopen("nalozi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return;
    }
    int p;
    nalog promena[100];
     for (p=0;; p++){
        if(feof(n)){
            break;
        }
        fscanf(n,"%s",promena[p].ime);
        fgetc(n);
        fscanf(n,"%s",promena[p].prezime);
        fgetc(n);
        fscanf(n,"%s",promena[p].mejl);
        fgetc(n);
        fscanf(n,"%s",promena[p].nadimak);
        fgetc(n);
        fscanf(n,"%s",promena[p].lozinka);
        fgetc(n);
    }
    char niz[100],m[100];
gore:
    printf("*********************************************\n");
    printf("*Uzaberite sta zelite da izmenite kod fajla *\n");
    printf("*1. Ime                                     *\n");
    printf("*2. Prezime                                 *\n");
    printf("*3. Mejl adresa                             *\n");
    printf("*4. Nadimak                                 *\n");
    printf("*5. Lozinka                                 *\n");
    printf("*6. Izlaz na glavni meni                    *\n");
    printf("*********************************************\n");
    printf(">");
    int t;
    scanf("%i",&t);
    if (t < 1){
        printf("Nema te opcije!!!\n");
        goto gore;
    }else if(t > 6){
        printf("Nema te opcije!!!\n");
        goto gore;
    }
    switch(t){
case 1:
    printf("Napisite novo ime: ");
    gets(niz);
    strcpy(promena[i].ime,niz);
    fputs(promena[i].ime,n);
    fclose(n);
    break;
case 2:
    printf("Napisite novo prezime: ");
    gets(niz);
    strcpy(promena[i].prezime,niz);
    fputs(promena[i].prezime,n);
    fclose(n);
    break;
case 3:
    printf("Napisite novu mejl adresu: ");
    gets(niz);
    provera_mejla(niz);
    strcpy(promena[i].mejl,niz);
    fputs(promena[i].mejl,n);
    fclose(n);
    break;
case 4:
    printf("Napisite nov nadimak: ");
    gets(niz);
    strcpy(promena[i].nadimak,niz);
    fputs(promena[i].nadimak,n);
    fclose(n);
    break;
case 5:
lozinka:
    printf("Koja je vasa nova lozinka: ");
    gets(m);
    printf("Ponovo unesite lozinku: ");
    gets(niz);
    if(strcmp(m,niz)!=0){
        printf("Niste dobro uneli lozinku! Probajte opet.");
        goto lozinka;
    }
    strcpy(promena[i].lozinka,m);
    fputs(promena[i].lozinka,n);
    fclose(n);
    break;
case 6:
    fclose(n);
    break;
    }
}
int brisanje_naloga(int i){
    char d;
    nalog registrovan[100];
    int p,t=0;
opet:
    printf("Da li zelite da obrisete fajl(y/n): ");
    scanf("%c",&d);
    scanf("%c",&d);
    if(d=='y' || d=='Y'){
            return 1;
        }else if(d=='n' || d=='N'){
            return 0;
        }else
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
        goto opet;
    FILE* n=fopen("nalozi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return 0;
    }

     for (p=0;; p++){
        if(feof(n)){
            break;
        }
        fscanf(n,"%s",registrovan[p].ime);
        fgetc(n);
        fscanf(n,"%s",registrovan[p].prezime);
        fgetc(n);
        fscanf(n,"%s",registrovan[p].mejl);
        fgetc(n);
        fscanf(n,"%s",registrovan[p].nadimak);
        fgetc(n);
        fscanf(n,"%s",registrovan[p].lozinka);
        fgetc(n);
        if(feof(n)){
            fseek(n,0,SEEK_SET);
            break;
        }else
            t++;
    }
    fclose(n);
    FILE* m=fopen("laznifajl.txt","w");
    if(m==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return 0;
    }
    for(p=0;p<t;p++){
        if(p==i){
            printf("%i",p);
            fputs(registrovan[p].ime,m);
            fprintf(n,"\n");
            fputs(registrovan[p].prezime,m);
            fprintf(n,"\n");
            fputs(registrovan[p].mejl,m);
            fprintf(n,"\n");
            fputs(registrovan[p].nadimak,m);
            fprintf(n,"\n");
            fputs(registrovan[p].lozinka,m);
            fprintf(n,"\n");
        }
    }
    remove("nalozi.txt");
    rename("laznifajl.txt","nalozi.txt");
    fclose(m);
    printf("Uspesno obrisan fajl! \n");
    return 0;
}
