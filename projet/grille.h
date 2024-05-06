#ifndef _GRILLE_H
#define _GRILLE_H

struct grille
{
    int n;        // rangées
    int m;        // colonnes
    char ***tab;  //
    int fruit[2]; // coordonnées fruits
};

/* prenant en entrée un deux entiers n et m qui retourne un pointeur sur
une Grille, dont le tableau est également alloué, c’est à dire que chacune de ses cases
contient une chaîne de caractères de taille 8.*/
struct grille *grille_allouer(int n, int m);

/* qui met deux espaces 1 de fond noir dans les cases du tableau*/
void grille_vider(struct grille *a);

/* qui tire au sort une case et stocke la case dans les champs de
Grille*/
void grille_tirage_fruit(struct grille *a);

/*  qui remplit la case du tableau de deux espaces de couleur de fond
rouge.*/

void grille_remplir(struct grille *a, int n, int m);
/* qui désalloue la structure et son contenu.*/

void grille_désallouer(struct grille **a);

void afficher_grille(struct grille *a);

#endif