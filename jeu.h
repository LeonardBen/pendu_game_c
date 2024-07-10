#ifndef JEU_H
#define JEU_H

typedef struct
{
    char *mot;
    char *motDevine;
    char lettresDevinees[26];
    int essais;
    int nombreLettresDevinees;
} Jeu;

void jouerJeu(const char *mot);

#endif
