#ifndef PLAKY_H_INCLUDED
#define PLAKY_H_INCLUDED
typedef struct {
    char ime[100];
    char prezime[100];
    char mejl[100];
    char nadimak[100];
    char lozinka[100];
}nalog;
typedef struct{
    char ime_videa[100];
    char link[5];
    char vlasnik[100];
    int pregledi;
    int lajkovi;
    int dislajkovi;
    int  komentari;
}video;
typedef struct{
    char taj_video[100];
    char korisnik[100];
    char komentar[100];
}komentarisanje;
int provera_mejla(char* string);
int ispis(int i);
void registracija();
int logovanje();
int izlogovanje(int l);
void menjanje_naloga(int l);
int brisanje_naloga(int i);
int bolji_ispis(int i);
int dodavanje_videa(int k, int t);
void izmena_videa(int k,int t );
int brisanje_videa(int k,int t);
void home_page(int t, int l, int e);
void pretraga(int t, int l,int e);
void gledanje_videa(int q, int l,int e);
#endif // PLAKY_H_INCLUDED
