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


