#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Ajout pour la fonction strcpy
#include <time.h>
#include "grille.h"

/* Alloue dynamiquement une grille de dimensions n x m */
struct grille *grille_allouer(int n, int m)
{
    // Allocation de mémoire pour la structure grille
    struct grille *p = malloc(sizeof(struct grille));

    // Vérification de l'allocation
    if (p == NULL)
    {
        perror("Erreur d'allocation de la grille\n");

        exit(EXIT_FAILURE);
    }

    // Initialisation des dimensions de la grille
    p->n = n;
    p->m = m;

    // Allocation de mémoire pour le tableau à deux dimensions
    p->tab = malloc(n * sizeof(char **)); // Allocation de n lignes

    // Vérification de l'allocation
    if (p->tab == NULL)
    {
        perror("Erreur d'allocation pour le tableau\n");
        exit(EXIT_FAILURE);
    }

    // Allocation de mémoire pour chaque élément du tableau à deux dimensions
    for (int i = 0; i < n; i++)
    {
        p->tab[i] = malloc(m * sizeof(char *)); // Allocation de m colonnes pour chaque ligne

        // Vérification de l'allocation
        if (p->tab[i] == NULL)
        {
            perror("Erreur d'allocation pour le tableau 2\n");
            exit(EXIT_FAILURE);
        }

        // Allocation de mémoire pour chaque case du tableau
        for (int e = 0; e < m; e++)
        {
            p->tab[i][e] = malloc(8 * sizeof(char)); // Allocation de 8 caractères par case

            // Vérification de l'allocation
            if (p->tab[i][e] == NULL)
            {
                perror("Erreur d'allocation pour le tableau 3\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return p;
}

/* Vide la grille en mettant deux espaces dans chaque case */
void grille_vider(struct grille *a)
{
    printf("\033[2J"); // Efface le contenu de la console

    for (int i = 0; i < a->n; i++)
    {
        for (int e = 0; e < a->m; e++)
        {
            strcpy(a->tab[i][e], "  "); // Copie deux espaces dans chaque case
        }
    }
}

/* Tire au sort une position pour le fruit et la stocke dans la grille */
void grille_tirage_fruit(struct grille *a)
{
    // Génère aléatoirement des coordonnées pour le fruit
    a->fruit[0] = (rand() % a->n);
    a->fruit[1] = (rand() % a->m);
}

/* Remplit une case de la grille avec une couleur de fond rouge */
void grille_remplir(struct grille *a, int n, int m)
{
    strcpy(a->tab[n][m], "\033[41m  \033[00m"); // Copie la couleur de fond rouge dans la case
}

/* Désalloue la mémoire occupée par la grille */
void grille_désallouer(struct grille **a)
{
    if (a != NULL)
    {
        // Libération de la mémoire pour chaque case du tableau
        for (int i = 0; i < (*a)->n; i++)
        {
            for (int j = 0; j < (*a)->m; j++)
            {
                free((*a)->tab[i][j]);
            }
            free((*a)->tab[i]); // Libération de la mémoire pour chaque ligne
        }
        free((*a)->tab); // Libération de la mémoire pour le tableau à deux dimensions
        free(*a);        // Libération de la mémoire pour la structure grille
        *a = NULL;       // Définition du pointeur à NULL
    }
}

/* Affiche le contenu de la grille */
void afficher_grille(struct grille *a)
{
    for (int i = 0; i < a->n; i++)
    {
        for (int e = 0; e < a->m; e++)
        {
            printf("%s", a->tab[i][e]); // Affichage de chaque case
        }
        printf("\n"); // Nouvelle ligne à la fin de chaque ligne
    }
}
