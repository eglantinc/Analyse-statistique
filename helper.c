#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
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


bool validate_argc(int argc) {
    if (argc != 2 && argc != 4) {
        fprintf(stderr, "Ce programme prend soit 2 arguments, soit 4 arguments.\n");
        print_usage();
        return false;
    }
    return true;
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

bool validate_argv(int argc, char **argv) {
    if (argc == 4) {
        if (strcmp(argv[2], "-S") != 0) {
            fprintf(stderr, "Option non reconnue : %s\n", argv[2]);
            print_usage();
            return false;
        }
    }
    return true;
}

void validate_inputs(int argc, char **argv) {
       if (!validate_argc(argc) || !validate_argv(argc, argv)) {
        exit(EXIT_FAILURE);
    }

}




