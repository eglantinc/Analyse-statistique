#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include "listechainee.h"

#define USAGE "NAME\n" \
               "    %s - Trie une liste de mots provenant d’un fichier d’entrée.\n" \
               "    Une fois les mots triés, le programme affichera la liste ordonnée\n" \
               "    sans doublons sur stdout.\n" \
               "\n" \
               "SYNOPSIS\n" \
               "    ./%s entree.txt [-S sortie.txt]\n" \
               "\n" \
               "DESCRIPTION\n" \
               "    entree.txt\n" \
               "        Fichier contenant la liste des mots à trier.\n" \
               "    -S sortie.txt\n" \
               "        (Optionnel) Génère des statistiques et les enregistre\n" \
               "        dans le fichier de sortie spécifié.\n"

void afficher_manuel(void) {
    fprintf(stderr, USAGE, "tri", "tri");
}

void validate_argc(int argc, char **argv) {
    if (argc != 2 && argc != 4) {
        fprintf(stderr, "Ce programme prends soit 2 arguments, soit 4 arguments.\n");
        afficher_manuel();
        exit(EXIT_FAILURE);
    }

} 

void validate_argv(int argc, char **argv) {
    int option = getopt(argc, argv, "S:");
    if (option == 'S') {
        
    } else if (option == -1) {
        // Pour quand pas option S
    } else {
        afficher_manuel();
        exit(EXIT_FAILURE);
    }
}

int main (int argc, char **argv) {
    validate_argc(argc, argv);
    validate_argv(argc, argv);

return 0;
}
