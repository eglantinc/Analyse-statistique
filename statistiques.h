#ifndef STATISTIQUES_H
#define STATISTIQUES_H
#include "listechainee.h"
#include <stdio.h>

/**
 *  Vérifie si une ligne de est vide ou non
 *
 *  @param ligne La ligne qui est potentiellement vide
 *  @return true si la lignes est vide, false sinon
 */
bool is_empty_line(const char *line);

/**
 *  Compte le nombre de lignes dans un fichier
 *
 *  @param file Le fichier
 *  @return Le nombre de lignes dans le fichier
 */
int count_lines(FILE *file);

/**
 *  Cherche le nombre de lettres distinctes
 *  dans une liste de mots
 *
 *  @param word_list La liste de mots
 *  @return Le nombre de lettres distinctes dans la liste
 */
int distinct_letter_count(LinkedList *word_list);

/**
 * Trouve la lettre ayant le plus d'occurences dans 
 * une liste de mots
 *
 * @param word_list La liste de mits
 * @return La lettre ayant le plus d'occurences dans la liste
 */
char find_most_repeated_letter(LinkedList *word_list);

#endif
