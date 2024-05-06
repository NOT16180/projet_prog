#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>

#define MAX 256

// struct grille{
//     int n; // rangées
//     int m; // colonnes
//     char tab[MAX][MAX]; //
//     int fruit[2]; //coordonnées fruits
// };


// void grille_remplir(struct grille a, int n, int m);

int main() {

    //char a[MAX] = "\33[41mtext\33[00m";
    char tab[3][3][MAX] = {
        {"Alice", "Bob", "Charlie"},
        {"David", "\33[41m  \33[00m", "Frank"},
        {"Grace", "Hannah", "Isaac"}
    };


    printf("%s", tab[1][1]);



    return EXIT_SUCCESS;
}
