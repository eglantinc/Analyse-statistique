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

void print_fopen_error(FILE *file) {
    if (file == NULL) {
         perror("Erreur lors de l'ouverture du fichier");
         fprintf(stderr, "Erreur: %s\n", strerror(errno));
         exit(EXIT_FAILURE);
     }
}

void validate_input_file(char **argv) {
     FILE *file = fopen(argv[1], "r");
     print_fopen_error(file);
}

void validate_argv(int argc, char **argv) {
    validate_input_file(argv);
    if (argc == 4) {
        if (strcmp(argv[2], "-S") == 0) {

        } else {
            fprintf(stderr, "Option non reconnue : %s\n", argv[2]);
            afficher_manuel();
            exit(EXIT_FAILURE);
        }
    } 
}
int main (int argc, char **argv) {
    validate_argc(argc, argv);
    validate_argv(argc, argv);

return 0;
}
