#include <stdio.h>
#include <stdlib.h>
#include "plaky.h"
#include <string.h>
#include <time.h>

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
    printf("*6. Udjite u meni ulogovanih      *\n");
    printf("*7. Izadjite iz programa          *\n");
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

do{
    printf("Koja je Vasa mejl adresa: ");
    gets(korisnik.mejl);
    d=provera_mejla(korisnik.mejl);
    if(d==1){
        printf("Niste dobro uneli mejl!! Probajte opet!\n");
    }else if(d==0){
    printf("Uspesno unesen mejl!");
    }
}while(d!=0);


    printf("Koji je Vas nadimak: ");
    gets(korisnik.nadimak);

do{
    printf("Koja je vasa lozinka: ");
    gets(korisnik.lozinka);
    printf("Ponovo unesite lozinku: ");
    gets(loyinka);
    if(strcmp(loyinka,korisnik.lozinka)!=0){
        printf("Niste dobro uneli lozinku! Probajte opet. \n");
    }
}while(strcmp(loyinka,korisnik.lozinka)!=0);

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
    fputc(' ',n);
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
do{
    printf("Unesite nadimak ili mejl: ");
    char niz[100],loyinka[100];
    gets(niz);
    gets(niz);

    for(i=0;i<100;i++){
        if(strcmp(niz,registrovan[i].mejl)==0 || strcmp(niz,registrovan[i].nadimak)==0){
            p++;
            printf("Unesite lozinku tog naloga: ");
            gets(loyinka);
            if(strcmp(loyinka,registrovan[i].lozinka)==0){
                p++;
                break;
            }}
    }

do{
    if(p==0){
        printf("Niste dobro uneli mejl,nadimak ili lozinku! Da li zelite da probate ponovo(y/n): ");
        scanf("%c",&y);
        scanf("%c",&y);
        if(y=='y' || y=='Y'){
                continue;
        }else if(y=='n' || y=='N'){
            return 0;
        }else if((y!='y' || y!='Y' || y!='n' || y!='N')){
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
        }
    }
}while(y!='y' || y!='Y' || y!='n' || y!='N');
}while(y=='y' || y=='Y');
if(p!=0){
    printf("Uspesno ste ulogovani!!!\n");
}
    fclose(n);
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
do{
    printf("Da li zelite da obrisete fajl(y/n): ");
    scanf("%c",&d);
    scanf("%c",&d);
    if(d=='y' || d=='Y'){
            return 1;
        }else if(d=='n' || d=='N'){
            return 0;
        }else
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
}while(d!='y' || d!='Y' || d!='n' || d!='N');
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
            fprintf(m,"\n");
            fputs(registrovan[p].prezime,m);
            fprintf(m,"\n");
            fputs(registrovan[p].mejl,m);
            fprintf(m,"\n");
            fputs(registrovan[p].nadimak,m);
            fprintf(m,"\n");
            fputs(registrovan[p].lozinka,m);
            fprintf(m,"\n");
        }
    }
    remove("nalozi.txt");
    rename("laznifajl.txt","nalozi.txt");
    fclose(m);
    printf("Uspesno obrisan nalog! \n");
    return 0;
}
int bolji_ispis(int i){
    printf("***********************************\n");
    printf("*Uzaberite uslugu:                *\n");
    printf("*1. Dodaj video                   *\n");
    printf("*2. Izmenite video                *\n");
    printf("*3. Obrisite video                *\n");
    printf("*4. Udjite na Home Page           *\n");
    printf("*5. Pretrazite video              *\n");
    printf("*6. Pogledajte video              *\n");
    printf("***********************************\n");
    printf(">");
    scanf("%d",&i);
    return i;
}
int dodavanje_videa(int k,int t){
    int i=0;
    nalog momak[100];
    video bioskop[100];
    char videic[100],c,linkic[5];
    printf("Dodajte ime videu(maksimalno 100 karaktera): ");
    gets(videic);
    FILE* n=fopen("videi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return 0;
    }
    strcpy(bioskop[t].ime_videa,videic);
    strcpy(bioskop[t].vlasnik,momak[k].nadimak);
    bioskop[t].lajkovi=0;
    bioskop[t].dislajkovi=0;
    bioskop[t].pregledi=0;
    bioskop[t].komentari=0;
    for(i=0;i<5;i++){
        srand(time(0));
        c=(rand()%(122-48+1))+ 48;
        if((c<65 && c>57) || (c<97 && c>90)){
            continue;
        }else
        linkic[i]=c;
    }
    strcpy(bioskop[i].link,linkic);

    fseek(n,0,SEEK_END);
    fprintf(n,"%s",bioskop[t].ime_videa);
    fputc(' ',n);
    fprintf(n,"%s",bioskop[t].link);
    fputc(' ',n);
    fprintf(n,"%s",bioskop[t].vlasnik);
    fputc(' ',n);
    fprintf(n,"%d",bioskop[t].pregledi);
    fputc(' ',n);
    fprintf(n,"%d",bioskop[t].lajkovi);
    fputc(' ',n);
    fprintf(n,"%d",bioskop[t].dislajkovi);
    fputc(' ',n);
    fprintf(n,"%d",bioskop[t].komentari);
    fprintf(n,"\n");
    fclose(n);
    t++;
    return t;
}
void izmena_videa(int k,int t ){
    nalog momak[100];
    video bioskop[100];
    FILE* n= fopen("videi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return;
    }
    char ovaj[100],v,ovako[100];
    int p,o=0,q=0;
    video promena[100];
     for (p=0;; p++){
        if(feof(n)){
            break;
        }
        fscanf(n,"%s",promena[p].ime_videa);
        fgetc(n);
        fscanf(n,"%s",promena[p].link);
        fgetc(n);
        fscanf(n,"%s",promena[p].vlasnik);
        fgetc(n);
        promena[p].pregledi=fgetc(n);
        fgetc(n);
        promena[p].lajkovi=fgetc(n);
        fgetc(n);
        promena[p].dislajkovi=fgetc(n);
        fgetc(n);
        promena[p].komentari=fgetc(n);
        fgetc(n);
     }
    int i;
    for(i=0;i<t;i++){
        if(strcmp(bioskop[i].vlasnik,momak[k].nadimak)==0){
            o++;
        }
    }
    if(o==0){
            printf("Ulogovani nalog nema ni jedan video!!");
            return;
        }
do{
    printf("Kom videu zelite da promenite ime? \n");
    gets(ovaj);
    for(i=0;i<o;i++){
        if(strcmp(bioskop[i].ime_videa,ovaj)==0){
            q++;
            break;
        }
    }
do{
    if(q==0){
        printf("Niste dobro uneli ime videa! Da li zelite da probate ponovo(y/n): ");
        scanf("%c",&v);
        if(v=='y' || v=='Y'){
        }else if(v=='n' || v=='N'){
            return;
        }else if(v!='y' || v!='Y' || v!='n' || v!='N')
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
    }
}while(v!='y' || v!='Y' || v!='n' || v!='N');
}while(v=='y' || v=='Y');
    printf("Kako zelite da nazovete video? \n");
    gets(ovako);

    strcpy(promena[p].ime_videa,ovako);
    fputs(promena[p].ime_videa,n);
    fclose(n);
    printf("Uspesno ste promenili ime videa!");
}
int brisanje_videa(int k,int t){
    nalog momak[100];
    video bioskop[100];
    char d;
    do{
    printf("Da li zelite da obrisete fajl(y/n): ");
    scanf("%c",&d);
    scanf("%c",&d);
    if(d=='y' || d=='Y'){
            return 1;
        }else if(d=='n' || d=='N'){
            return 0;
        }else
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
}while(d!='y' || d!='Y' || d!='n' || d!='N');
    FILE* n= fopen("videi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return 1;
    }
    int p,z,o=0,q=0,i;
    char v,ovaj[100];
    for (p=0;; p++){
        if(feof(n)){
            break;
        }
        fscanf(n,"%s",bioskop[p].ime_videa);
        fgetc(n);
        fscanf(n,"%s",bioskop[p].link);
        fgetc(n);
        fscanf(n,"%s",bioskop[p].vlasnik);
        fgetc(n);
        bioskop[p].pregledi=fgetc(n);
        fgetc(n);
        bioskop[p].lajkovi=fgetc(n);
        fgetc(n);
        bioskop[p].dislajkovi=fgetc(n);
        fgetc(n);
        bioskop[p].komentari=fgetc(n);
        fgetc(n);
        if(feof(n)){
            fseek(n,0,SEEK_SET);
            break;
        }else
            z++;
    }
    for(i=0;i<t;i++){
        if(strcmp(bioskop[i].vlasnik,momak[k].nadimak)==0){
            o++;
        }
    }
    if(o==0){
            printf("Ulogovani nalog nema ni jedan video!!");
            return t;
        }
do{
    printf("Koji video zelite da izbrisete? \n");
    gets(ovaj);
    for(i=0;i<o;i++){
        if(strcmp(bioskop[i].ime_videa,ovaj)==0){
            q++;
            break;
        }
    }
do{
    if(q==0){
        printf("Niste dobro uneli ime videa! Da li zelite da probate ponovo(y/n): ");
        scanf("%c",&v);
        if(v=='y' || v=='Y'){
        }else if(v=='n' || v=='N'){
            return t;
        }else
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
    }
}while(v!='y' || v!='Y' || v!='n' || v!='N');
}while(v=='y' || v=='Y');
    fclose(n);
    FILE* m=fopen("laznivideo.txt","w");
    if(m==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return 0;
    }
    for(p=0;p<z;p++){
        if(p==i){
            printf("%i",p);
            fputs(bioskop[p].ime_videa,m);
            fprintf(m,"\n");
            fputs(bioskop[p].link,m);
            fprintf(m,"\n");
            fputs(bioskop[p].vlasnik,m);
            fprintf(m,"\n");
            putw(bioskop[p].pregledi,m);
            fprintf(m,"\n");
            putw(bioskop[p].lajkovi,m);
            fprintf(m,"\n");
            putw(bioskop[p].dislajkovi,m);
            fprintf(m,"\n");
            putw(bioskop[p].komentari,m);
            fprintf(m,"\n");
        }
    }
    remove("videi.txt");
    rename("laznivideo.txt","videi.txt");
    fclose(m);
    printf("Uspesno obrisan video! \n");
t--;
fclose(n);
 return t;
}
void home_page(int t, int l,int e){
printf( " #    #  ####  #    # ######    #####    ##    ####  ###### \n");
printf( " #    # #    # ##  ## #         #    #  #  #  #    # #      \n");
printf( " ###### #    # # ## # #####     #    # #    # #      #####  \n");
printf( " #    # #    # #    # #         #####  ###### #  ### #      \n");
printf( " #    # #    # #    # #         #      #    # #    # #      \n");
printf( " #    #  ####  #    # ######    #      #    #  ####  ###### \n");
int i,c,j,z,w;
char v;
video bioskop[t];
video rikomended[t];
if(t<1){
    printf("Nemamo ni jedan video u bazi!");
    return;
}

    for(i=0;i<10;i++){
        srand(time(0));
        c=(rand()%(t-1+1))+ 1;
        z=0;
        for(j=0;j<i;j++){
            if(t<10 && t<i){
                break;
            }else if(strcmp(rikomended[j].link,bioskop[c].link)==0){
                z++;
            }
        }
        if(t<10 && t<i){
            printf("%d. Nema vise videa za Home Page!\n",i+1);
            continue;
        }
        if(z==0){
            printf("%d.",i+1);
            puts(bioskop[c].ime_videa);
        }
    }

        do{
        printf("Koji video zelite da pogledate(unesite redni broj videa): ");
        scanf("%i",&w);
        do{
        if((w<1 || w>10)||(w>t)){

        printf("Niste dobro uneli broj videa! Da li zelite da probate ponovo(y/n): ");
        scanf("%c",&v);
        if(v=='y' || v=='Y'){
        }else if(v=='n' || v=='N'){
            return;
        }else if(v!='y' || v!='Y' || v!='n' || v!='N')
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
    }
    }while(v!='y' || v!='Y' || v!='n' || v!='N');
}while(v=='y' || v=='Y');
        gledanje_videa(w,l,e);
}
void pretraga(int t,int l, int e){
    video bioskop[100];
    FILE* n= fopen("videi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return;
    }
    char ovaj[100],v;
    int p,o=0,q=0,z,i,j,w;
    video promena[100];
     for (p=0;; p++){
        if(feof(n)){
            break;
        }
        fscanf(n,"%s",promena[p].ime_videa);
        fgetc(n);
        fscanf(n,"%s",promena[p].link);
        fgetc(n);
        fscanf(n,"%s",promena[p].vlasnik);
        fgetc(n);
        promena[p].pregledi=fgetc(n);
        fgetc(n);
        promena[p].lajkovi=fgetc(n);
        fgetc(n);
        promena[p].dislajkovi=fgetc(n);
        fgetc(n);
        promena[p].komentari=fgetc(n);
        fgetc(n);
     }
do{
    printf("Pretrazite video: ");
    gets(ovaj);
    for(q=0;q<t;q++){
        if(strcmp(promena[q].ime_videa,ovaj)==0){
            o++;
        }
    }
    do{
    if(o==0){
        printf("Niste dobro uneli ime videa! Da li zelite da probate ponovo(y/n): ");
        scanf("%c",&v);
        if(v=='y' || v=='Y'){
        }else if(v=='n' || v=='N'){
            return;
        }else if(v!='y' || v!='Y' || v!='n' || v!='N')
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
    }
}while(v!='y' || v!='Y' || v!='n' || v!='N');
}while(v=='y' || v=='Y');
    if(o==1){
        for(q=0;q<t;q++){
            if(strcmp(promena[q].ime_videa,ovaj)==0){
            printf("Rezultat pretrage: \n");
            puts(promena[q].ime_videa);
            printf("Link videa: ");
            puts(promena[q].link);
            printf("Autor videa: ");
            puts(promena[q].vlasnik);
            printf("Broj pregleda: ");
            printf("%d",promena[q].pregledi);
            printf("Broj lajkovi: ");
            printf("%d",promena[q].lajkovi);
            printf("Broj dislajkovi: ");
            printf("%d",promena[q].dislajkovi);
            printf("Broj komentara: ");
            printf("%d",promena[q].komentari);
        }
        do{
        if(o==0){
            printf("Da li zelite da pogledate video(y/n): ");
            scanf("%c",&v);
            if(v=='y' || v=='Y'){
                    gledanje_videa(q,l,e);
            }else if(v=='n' || v=='N'){
            return ;
        }else if(v!='y' || v!='Y' || v!='n' || v!='N')
            printf("Niste adekvatno odgovorili! Probajte opet!\n");
    }
        }while(v!='y' || v!='Y' || v!='n' || v!='N');
    }
    }
    if(o>0){
        for(q=0;q<t;q++){
            if(strcmp(promena[q].ime_videa,ovaj)==0){
                strcpy(bioskop[z].ime_videa,promena[q].ime_videa);
                strcpy(bioskop[z].link,promena[q].link);
                strcpy(bioskop[z].vlasnik,promena[q].vlasnik);
                bioskop[z].pregledi=promena[q].pregledi;
                bioskop[z].lajkovi=promena[q].lajkovi;
                bioskop[z].dislajkovi=promena[q].dislajkovi;
                bioskop[z].komentari=promena[q].komentari;
                z++;
            }
        }
        video plejsholder;
        for (i = 0; i < z-1; i++){
            for (j = 0; j < z-i-1; j++){
                if (bioskop[j].pregledi < bioskop[j+1].pregledi){
                    plejsholder = bioskop[j];
                    bioskop[j] = bioskop[j+1];
                    bioskop[j+1] = plejsholder;
                }
            }
        }

        for(q=0;q<z;q++){
            printf("Rezultat pretrage: \n");
            printf("%d.",q+1);
            puts(promena[q].ime_videa);
            printf("Link videa: ");
            puts(promena[q].link);
            printf("Autor videa: ");
            puts(promena[q].vlasnik);
            printf("Broj pregleda: ");
            printf("%d",promena[q].pregledi);
            printf("Broj lajkovi: ");
            printf("%d",promena[q].lajkovi);
            printf("Broj dislajkovi: ");
            printf("%d",promena[q].dislajkovi);
            printf("Broj komentara: ");
            printf("%d",promena[q].komentari);
        }
        do{
        printf("Koji video zelite da pogledate(unesite redni broj videa): ");
        scanf("%i",&w);
        do{
        if(w<1 || w>z){

        printf("Niste dobro uneli broj videa! Da li zelite da probate ponovo(y/n): ");
        scanf("%c",&v);
        if(v=='y' || v=='Y'){
        }else if(v=='n' || v=='N'){
            return;
        }else if(v!='y' || v!='Y' || v!='n' || v!='N')
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
    }
    }while(v!='y' || v!='Y' || v!='n' || v!='N');
}while(v=='y' || v=='Y');
        gledanje_videa(w,l,e);
        }
        fclose(n);
}
void gledanje_videa(int q, int l, int e){
    FILE* n= fopen("videi.txt","r+");
    if(n==NULL){
        printf("Nije moguce otvoriti fajl, molimo Vas pokusajte ponovo.\n");
        return;
    }
    int i=0;
    komentarisanje nmp[100];
    char v, sastav[140];
    video promena[100];
        fscanf(n,"%s",promena[q].ime_videa);
        fgetc(n);
        fscanf(n,"%s",promena[q].link);
        fgetc(n);
        fscanf(n,"%s",promena[q].vlasnik);
        fgetc(n);
        promena[q].pregledi=fgetc(n);
        fgetc(n);
        promena[q].lajkovi=fgetc(n);
        fgetc(n);
        promena[q].dislajkovi=fgetc(n);
        fgetc(n);
        promena[q].komentari=fgetc(n);
        fgetc(n);
    promena[q].pregledi++;
printf("**************************************************\n");
printf("         #   ######        #                #   # \n");
printf(" #       #     #      ########## ########## #   # \n");
printf("  #     #  ##########      #             #  #   # \n");
printf("       #       #        #  # #          #   #   # \n");
printf("     ##        #       #   #  #      # #       #  \n");
printf("   ##          #      #   ##   #      #       #   \n");
printf(" ##             ####       #           #    ##    \n");
printf("**************************************************\n");
printf("Broj pregleda: ");
printf("%d",promena[q].pregledi);
printf("\n");
printf("Broj lajkova/dislajkova: ");
printf("%d",promena[q].lajkovi);
printf("/");
printf("%d",promena[q].dislajkovi);
printf("\n");
printf("Broj komentara: ");
printf("%d",promena[q].komentari);
printf("\n");
for(i=0;i<e;i++){
    if(strcmp(nmp[i].taj_video,promena[q].ime_videa)==0){
        puts(nmp[i].korisnik);
        printf(":");
        puts(nmp[i].komentar);
    }
}
do{
    printf("Da li zelite da lajkujete video(y/n)?\n");
    printf(">");
    scanf("%c",&v);
        if(v=='y' || v=='Y'){
            promena[q].lajkovi++;
        }else if(v=='n' || v=='N'){
            return;
        }else if(v!='y' || v!='Y' || v!='n' || v!='N'){
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
    }
}while(v!='y' || v!='Y' || v!='n' || v!='N');
    if(v=='n' || v=='N'){
    do{
        printf("Da li zelite da dislajkujete video(y/n)?\n");
    printf(">");
    scanf("%c",&v);
        if(v=='y' || v=='Y'){
            promena[q].dislajkovi++;
        }else if(v=='n' || v=='N'){
            return;
        }else if(v!='y' || v!='Y' || v!='n' || v!='N'){
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
    }
}while(v!='y' || v!='Y' || v!='n' || v!='N');
    }
    fclose(n);
FILE* m=fopen("comment.txt","r+");
do{
    printf("Da li zelite da komentarisete video video(y/n)?\n");
    printf(">");
    scanf("%c",&v);
        if(v=='y' || v=='Y'){
            promena[q].komentari++;
        }else if(v=='n' || v=='N'){
            return;
        }else if(v!='y' || v!='Y' || v!='n' || v!='N'){
        printf("Niste adekvatno odgovorili! Probajte opet!\n");
    }
}while(v!='y' || v!='Y' || v!='n' || v!='N');
    if(v=='y' || v=='Y'){
        printf("Napisite komentar: ");
        gets(sastav);
        strcpy(nmp[e].komentar,sastav);
        strcpy(nmp[e].taj_video,promena[q].ime_videa);
        strcpy(nmp[e].korisnik,promena[q].vlasnik);
        fputs(nmp[e].taj_video,m);
        fprintf(m,"\n");
        fputs(nmp[e].korisnik,m);
        fprintf(m,"\n");
        fputs(nmp[e].komentar,m);
        fprintf(m,"\n");
        e++;
    }
    fclose(m);
}
