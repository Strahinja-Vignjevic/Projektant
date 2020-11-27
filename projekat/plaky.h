#ifndef PLAKY_H_INCLUDED
#define PLAKY_H_INCLUDED
typedef struct {
    char ime[100];
    char prezime[100];
    char mejl[100];
    char nadimak[100];
    char lozinka[100];
}nalog;

int provera_mejla(char* string);
int ispis(int i);
void registracija();
int logovanje();
int izlogovanje(int l);
void menjanje_naloga(int l);
int brisanje_naloga(int i);


#endif // PLAKY_H_INCLUDED
