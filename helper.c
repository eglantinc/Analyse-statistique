#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "main.h"
#include "helper.h"


void print_usage(void) {
    fprintf(stderr, USAGE, "tri", "tri");
}


void validate_letters_in_word(char char_in_word) {
    if (!isalpha(char_in_word) || !isupper(char_in_word)) {
        fprintf(stderr, "Erreur, tous les mots du fichiers doivent "
                "être des lettres majuscules sans caractères accentués\n");
        exit(EXIT_FAILURE);
    }
}

void print_fopen_error(FILE *file) {
    if (file == NULL) {
         perror("Erreur lors de l'ouverture du fichier.\n");
         fprintf(stderr, "Erreur: %s\n", strerror(errno));
         exit(EXIT_FAILURE);
     }
}


void validate_argc(int argc) {
    if (argc != 2 && argc != 4) {
        fprintf(stderr, "Ce programme prends soit 2 arguments, soit 4 arguments.\n");
        print_usage();
        exit(EXIT_FAILURE);
    }
}

FILE *validate_input_file(char **argv) {
    FILE *file = fopen(argv[1], "r");
    print_fopen_error(file);
    return file;
}

FILE *validate_output_file(char **argv) {
    FILE *file = fopen(argv[3], "w");
    print_fopen_error(file);
    return file;
}

void validate_argv(int argc, char **argv) {
    if (argc == 4) {
        if (strcmp(argv[2], "-S") != 0) {
            fprintf(stderr, "Option non reconnue : %s\n", argv[2]);
            print_usage();
            exit(EXIT_FAILURE);
        }
    } 
}

