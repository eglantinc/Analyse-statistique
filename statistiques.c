#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
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


