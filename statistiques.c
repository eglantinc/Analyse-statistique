#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "statistiques.h"
#include "main.h"

bool is_empty_line(const char *line) {
    for (unsigned int i = 0; line[i] != '\0'; i++) {
        if (!isspace(line[i])) {
            return false;
        }
    }
    return true;
}

int count_lines(FILE *file) {
    int number_of_lines = 0;
    char line[MAX_CHAR + 1];
    while (fgets(line, sizeof(line),file)) {
        if (!is_empty_line(line)) {
            number_of_lines++;
        }
    }
    return number_of_lines;
}

int distinct_letter_count(LinkedList *word_list) {
    bool is_seen[26] = {false};
    int letter_count = 0;

    Node *current = word_list->head;

    while (current != NULL) {
        for (int i = 0; current->word[i]!= '\0'; i++) {
            char letter = current->word[i];
            // Trouver l'indice de la lettre qu'on cherche
            int letter_index = letter - 'A';
            if (!is_seen[letter_index]) {
                is_seen[letter_index] = true;
                letter_count++;
            } 
        }
        current = current->next;   
   }
   return letter_count;
}


char find_most_repeated_letter(LinkedList *word_list) {
    int max_letter = 0;   
    char max = '\0';      

    if (word_list->word_count == 0) {  
        return max;
    }
    
    Node *current = word_list->head;  
    int count[26] = {0};           

    while (current != NULL) {      
        for (int i = 0; current->word[i] != '\0'; i++) {  
            char c = current->word[i];
            int index = c - 'A'; 
            count[index]++;  

            if (count[index] > max_letter) { 
                max_letter = count[index];
                max = c;
            }
        }
        current = current->next; 
    }
    return max; 
}


