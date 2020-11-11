#include <stdio.h>
#include <stdlib.h>
#include "plaky.h"
#include <string.h>
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
void registracija(int i){
    nalog korisnik[100];
    int j[100],k[100],l[100],lj[100],m[100];
    upis_imena(j);
    upis_prezimena(k);
    upis_mejla(*l);
    upis_nadimka(lj);
    upis_lozinke(*m);
    strcpy(korisnik[i].ime,j);
    strcpy(korisnik[i].prezime,k);
    strcpy(korisnik[i].mejl,l);
    strcpy(korisnik[i].nadimak,lj);
    strcpy(korisnik[i].lozinka,m);
    FILE* n= fopen("nalozi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.");
    }
    fputs(korisnik[i].ime,n);
    fputs(korisnik[i].prezime,n);
    fputs(korisnik[i].mejl,n);
    fputs(korisnik[i].nadimak,n);
    fputs(korisnik[i].lozinka,n);
    fclose(n);
}
void provera_mejla(char* string){
    int i=0,j=0,k;
    for(i=0;i<100;i++){
        if(string[i]=='64')
            j++;
        if(j==1)
            break;
    }
    if(j!=1){
        printf("Mejl nije unesen kako treba!!! Pokusaj opet\n");
        upis_mejla(string);
    }
    if(j==1){
        for(k=0;i<100 || k==1;i++){
            if(string[i]=='46')
                k++;
        }
    }
    if(k!=1){
        printf("Mejl nije unesen kako treba!!! Pokusaj opet\n");
        upis_mejla(string);
    }
}
void upis_mejla(char string){
    printf("Koja je Vasa mejl adresa: ");
    gets(string);
    provera_mejla(string);
}
void provera_lozinke(char* string){
    FILE* n= fopen("nalozi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.");
    }
    int niz[100];
    printf("Ponovo unesite lozinku: ");
    gets(niz);
    if(strcmp(string,niz)== 1){
        printf("Lozinke se razlikuju, pokusajte ponovo!!!\n");
        fclose(n);
        upis_lozinke(string);
    }else
    printf("Uspesno upisana lozinka!\n");
    fputs(niz,n);
}
void upis_lozinke(char string){
    printf("Koja je vasa lozinka: ");
    gets(string);
    provera_lozinke(string);
}
void upis_imena(char ime){
    printf("Koje je Vase ime: ");
    gets(ime);
}
void upis_prezimena(char prezime){
    printf("Koje je Vase prezime: ");
    gets(prezime);
}
void upis_nadimka(char nadimak){
    printf("Koji je Vas nadimak: ");
    gets(nadimak);
}
void logovanje(int l,int i){
    l++;
pocetak:
    printf("Unesite nadimak ili mejl: ");
    char niz[100],loyinka[100];
    gets(niz);
    nalog registrovan[100];
    for(i=0;i<100;i++){
        if(strcmp(niz,registrovan[i].mejl)==0 && strcmp(niz,registrovan[i].nadimak)==0)
            break;
    }
    if(i==100){
        printf("Nema tog mejla ili lozinke u bazi podataka!!Probaj opet!\n");
        goto pocetak;
    }
sredina:
    printf("Unesite lozinku tog naloga: ");
    gets(loyinka);
    if(strcmp(loyinka,registrovan[i].lozinka)==1){
        printf("Pogresna lozinka!!Probaj opet!\n");
        goto sredina;
    }
    printf("Uspesno ste ulogovani!!!");
    l++;
}
int izlogovanje(int k){
    k--;
    return k;
}
void menjanje_naloga(int i){
    FILE* n= fopen("nalozi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.");
    }
    fseek(n,500*(i-1),SEEK_SET);
    char niz[100],j[100],k[100],l[100],m[100];
    nalog promena[100];
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
    fputs(niz,n);
    fclose(n);
    break;
case 2:
    printf("Napisite novo prezime: ");
    gets(j);
    strcpy(promena[i].prezime,j);
    fputs(j,n);
    fclose(n);
    break;
case 3:
    printf("Napisite novu mejl adresu: ");
    gets(k);
    provera_mejla(*k);
    strcpy(promena[i].mejl,k);
    fputs(k,n);
    fclose(n);
    break;
case 4:
    printf("Napisite nov nadimak: ");
    gets(l);
    strcpy(promena[i].nadimak,l);
    fputs(l,n);
    fclose(n);
    break;
case 5:
    printf("Napisite novu lozinku: ");
    gets(m);
    provera_lozinke(*m);
    strcpy(promena[i].lozinka,m);
    fputs(m,n);
    fclose(n);
    break;
case 6:
    fclose(n);
    break;
    }
}
void brisanje_naloga(int i){
    FILE* n=fopen("nalozi.txt","r+");
    FILE* m=fopen("laznifajl.txt","w");
    char niz[1000];
    int j = 1;
    while ((fgets(niz, 1000, n)) != NULL){
        if (i != j){
            fputs(niz, m);
        }
        j++;
    }
    zamena_fajla(n,m);
}

void zamena_fajla(FILE*n,FILE*m){
    remove("nalozi.txt");
    rename("laznifajl.txt","nalozi.txt");
    fclose(m);
}
