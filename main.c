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
            afficher_manuel();
            exit(EXIT_FAILURE);
        }
    } 
}

void insert_word_from_file(FILE *file, LinkedList *word_list) {
    char line[MAX_CHAR + 1];
    char line_copy[MAX_CHAR + 1];
    while (fgets(line, sizeof(line),file)) {
        strcpy(line_copy, line);  
        char *word = strtok(line_copy, " \n"); 
        while (word != NULL) {
            for (int i = 0; word[i] != '\0'; i++) {
                validate_letters_in_word(word[i], file);
            } 
            insert_in_order(word_list, word);
            word = strtok(NULL, " \n"); 
        }
    }
}

int main (int argc, char **argv) { 
    LinkedList word_list = {NULL};
    validate_argc(argc, argv);
    validate_argv(argc, argv);
    FILE *input_file = validate_input_file(argv);
    FILE *output_file = validate_output_file(argv);
    insert_word_from_file(input_file, &word_list);
    fprintf(output_file, "Nombre de mots avec dupplication: %d\n", word_list.word_count);
    delete_duplicate(&word_list);
    fprintf(output_file, "Nombre de mots sans dupplication: %d\n", word_list.word_count);
    fclose(output_file);
    print_list(&word_list);

     
    return 0;
}
