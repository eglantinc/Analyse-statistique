#ifndef STATISTIQUES_H
#define STATISTIQUES_H
#include "listechainee.h"
#include <stdio.h>

bool is_empty_line(const char *line);
int count_lines(FILE *file);
int distinct_letter_count(LinkedList *lstPtr);
char find_most_repeated_letter(LinkedList *lstPtr);

#endif
