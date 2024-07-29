#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include "main.h"
#include "listechainee.h"
#include "statistiques.h"

void print_usage(void) {
    fprintf(stderr, USAGE, "tri", "tri");
}

void validate_argc(int argc) {
    if (argc != 2 && argc != 4) {
        fprintf(stderr, "Ce programme prends soit 2 arguments, soit 4 arguments.\n");
        print_usage();
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

void validate_letters_in_word(char char_in_word) {

    if (!isalpha(char_in_word) || !isupper(char_in_word)) {
        fprintf(stderr, "Erreur, tous les mots du fichiers doivent " 
                "être des lettres majuscules sans caractères accentués\n");
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

void insert_word_from_file(FILE *file, LinkedList *word_list) {
    char line[MAX_CHAR + 1];
    char line_copy[MAX_CHAR + 1];
    while (fgets(line, sizeof(line),file)) {
        strcpy(line_copy, line);  
        char *word = strtok(line_copy, " \n"); 
        while (word != NULL) {
            for (int i = 0; word[i] != '\0'; i++) {
                validate_letters_in_word(word[i]);
            } 
            insert_in_order(word_list, word);
            word = strtok(NULL, " \n"); 
        }
    }
}

int main (int argc, char **argv) { 
    LinkedList word_list = {NULL, NULL, 0};
    
    validate_argc(argc);
    validate_argv(argc, argv);
    
    FILE *input_file = validate_input_file(argv);
    FILE *output_file = validate_output_file(argv);
    
    insert_word_from_file(input_file, &word_list);

    fprintf(output_file, "Nombre de mots avec dupplication: %d\n", word_list.word_count);
    delete_duplicate(&word_list);
    fseek(input_file, 0, SEEK_SET);
    fprintf(output_file, "Nombre de mots sans dupplication: %d\n", word_list.word_count);
    fprintf(output_file, "Nombre de lignes dans le fichier: %d\n", count_lines(input_file));
    fprintf(output_file, "Nombre de lettres distinctes dans la liste: %d\n", distinct_letter_count(&word_list));
    fprintf(output_file, "La lettre la plus fréquente: %c\n", find_most_repeated_letter(&word_list));
    fclose(output_file);
    fclose(input_file);
    
    print_list(&word_list);
     
    return 0;
}
