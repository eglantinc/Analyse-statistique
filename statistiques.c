#include <stdio.h>
#include <ctype.h>
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

int distinct_letter_count(LinkedList *lstPtr) {
    bool seen[26] = {false};
    int count = 0;

    Node *current = lstPtr->head;

    while (current != NULL) {
        for (int i = 0; current->word[i]!= '\0'; i++) {
            char c = current->word[i];
            int index = c - 'A';
            if (!seen[index]) {
                seen[index] = true;
                count++;
            } 
        }
        current = current->next;   
   }
   return count;
}

char find_most_repeated_letter(LinkedList *lstPtr) {
    Node *current = lstPtr->head;
    int current_letter_count = 0;
    int max_letter_count = 0;
    char max_letter = current->word[0];
    char *currentLetter;

    while (current != NULL) {
        currentLetter = current->word;
        while (*currentLetter != '\0') {
            for (int i = 0; current->word[i] != '\0'; i++) {
                if (current->word[i] == *currentLetter) {
                    current_letter_count++;
                }
            }
            if (current_letter_count > max_letter_count) {
                max_letter_count = current_letter_count;
                max_letter = *currentLetter;
            }
            current_letter_count = 0;
            currentLetter++;
        }
        current = current->next;
    }
    return max_letter;
}


