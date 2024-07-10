#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jeu.h"

#define MAX_ESSAIS 6 // Nombre maximum d'essais

// Dessine le pendu en fonction du nombre d'essais
void dessinerPendu(int essais)
{
    const char *imagesPendu[] = {
        " +---+\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "=========\n",

        " +---+\n"
        " |   |\n"
        " O   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "=========\n",

        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "=========\n",

        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |   |\n"
        " |   |\n"
        "     |\n"
        "=========\n",

        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |\\  |\n"
        " |   |\n"
        "     |\n"
        "=========\n",

        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |\\  |\n"
        " | \\ |\n"
        "     |\n"
        "=========\n",

        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |\\  |\n"
        " | \\ |\n"
        "/    |\n"
        "=========\n",

        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |\\  |\n"
        " | \\ |\n"
        "/ \\  |\n"
        "=========\n"};

    printf("%s", imagesPendu[essais]);
}

// Fonction principale pour jouer au jeu du pendu
void jouerJeu(const char *mot)
{
    int longueurMot = strlen(mot);
    Jeu jeu;
    jeu.mot = strdup(mot); // Allouer et copier le mot
    jeu.motDevine = malloc(longueurMot + 1);
    jeu.motDevine[0] = mot[0]; // Révéler la première lettre
    for (int i = 1; i < longueurMot - 1; i++)
    {
        jeu.motDevine[i] = '_'; // Initialisation du mot deviné sauf la première et la dernière lettre
    }
    jeu.motDevine[longueurMot - 1] = mot[longueurMot - 1]; // Révéler la dernière lettre
    jeu.motDevine[longueurMot] = '\0';                     // Ajout du caractère de fin de chaîne

    jeu.essais = 0;
    jeu.nombreLettresDevinees = 0;

    while (jeu.essais < MAX_ESSAIS)
    {
        dessinerPendu(jeu.essais);
        printf("Mot: %s\n", jeu.motDevine);
        printf("Essais restants: %d\n", MAX_ESSAIS - jeu.essais);
        printf("Lettres devinées: ");
        for (int i = 0; i < jeu.nombreLettresDevinees; i++)
        {
            printf("%c ", jeu.lettresDevinees[i]);
        }
        printf("\nEntrez une lettre: ");

        char lettre;
        scanf(" %c", &lettre);
        lettre = tolower(lettre); // Conversion en minuscule

        if (strchr(jeu.lettresDevinees, lettre))
        {
            printf("Vous avez déjà deviné cette lettre.\n");
            continue;
        }

        jeu.lettresDevinees[jeu.nombreLettresDevinees++] = lettre; // Ajout de la lettre devinée

        int correct = 0;
        for (int i = 1; i < longueurMot - 1; i++)
        {
            if (tolower(jeu.mot[i]) == lettre)
            { // Comparaison de la lettre
                jeu.motDevine[i] = jeu.mot[i];
                correct = 1; // Lettre correcte
            }
        }

        if (!correct)
        {
            jeu.essais++; // Incrémentation des essais si la lettre est incorrecte
        }

        if (strcmp(jeu.mot, jeu.motDevine) == 0)
        {
            dessinerPendu(jeu.essais);
            printf("Félicitations ! Vous avez deviné le mot : %s\n", jeu.mot);
            free(jeu.motDevine); // Libération de la mémoire allouée
            free(jeu.mot);
            return;
        }
    }

    dessinerPendu(jeu.essais);
    printf("Vous avez perdu ! Le mot était : %s\n", jeu.mot);
    free(jeu.motDevine); // Libération de la mémoire allouée
    free(jeu.mot);
}
