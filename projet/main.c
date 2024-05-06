#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "grille.h"

int main(int argc, char *argv[])
{
    int n, m;
    srand(time(NULL));
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    struct grille *a = grille_allouer(n, m);
    grille_vider(a);
    grille_tirage_fruit(a);
    grille_remplir(a, a->fruit[0], a->fruit[1]);
    afficher_grille(a);
    struct grille **p = &a;
    grille_désallouer(p);
    printf("%d\n", a == NULL);

    /* start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);// case fond noire
    init_pair(2, COLOR_BLACK, COLOR_RED);// case fond noire*/
    return EXIT_SUCCESS;
}