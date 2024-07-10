#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jeu.h"

int main()
{
    // Liste de mots à deviner
    char *mots[] = {
        "abricot", "brouhaha", "cacahuète", "dingue", "farfelu",
        "goupil", "hippopotame", "igloo", "jaloux", "kangourou",
        "limace", "marmotte", "nincompoop", "ouistiti", "pamplemousse",
        "quinoa", "ratatouille", "sapristi", "trombone", "utopiste"};

    int nombreDeMots = sizeof(mots) / sizeof(mots[0]); // Calcul du nombre de mots dans la liste

    srand(time(NULL));                       // Initialisation du générateur de nombres aléatoires avec le temps actuel
    char *mot = mots[rand() % nombreDeMots]; // Sélection aléatoire d'un mot à deviner

    jouerJeu(mot); // Appel de la fonction principale du jeu avec le mot choisi

    return 0;
}
