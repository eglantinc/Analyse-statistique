#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
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

#define MAX_CHAR 80

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

void validate_letters_in_word(char char_in_word, FILE *file) {

    if (!isalpha(char_in_word) || !isupper(char_in_word)) {
        fprintf(stderr, "Erreur, tous les mots du fichiers doivent " 
                "être des lettres majuscules sans caractères accentués\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
}

bool is_empty_line(const char *line) {
    for (unsigned int i = 0; line[i] != '\0'; i++) {
        if (!isspace(line[i])) {
            return false;
        }
    }
    return true;
}

void remove_space(char *line) {
    int i = 0, j = 0;
    while (line[i]) {
        if (!isspace((line[i]))) {
            line[j++] = line[i];
        }
        i++;
    }
    line[j] = '\0'; 
}

FILE *validate_input_file(char **argv) {
    FILE *file = fopen(argv[1], "r");
    print_fopen_error(file);
    return file;
}

void validate_output_file(char **argv) {
    FILE *file = fopen(argv[3], "w");
    print_fopen_error(file);

}

void validate_argv(int argc, char **argv) {
    if (argc == 4) {
        if (strcmp(argv[2], "-S") == 0) {
            validate_output_file(argv);
        } else {
            fprintf(stderr, "Option non reconnue : %s\n", argv[2]);
            afficher_manuel();
            exit(EXIT_FAILURE);
        }
    } 
}

int main (int argc, char **argv) { 
    char line[MAX_CHAR + 1];
    validate_argc(argc, argv);
    validate_argv(argc, argv);
    FILE *file = validate_input_file(argv);
     while (fgets(line, sizeof(line),file)) {
       for (int i = 0; line[i] != '\0'; i++) {
          validate_letters_in_word(line[i], file); 
          if (!is_empty_line(line)) {
              remove_space(line);
              if (line[strlen(line) - 1] == '\n') {
                  line[strlen(line) - 1] = '\0';
              }
          }
        }
     }
     return 0;
}
