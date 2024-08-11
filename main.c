#include <stdio.h>
#include "helper.h"
#include "listechainee.h"
#include "statistiques.h"


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
