#ifndef MAIN_H
#define MAIN_H

/*
 * Module pour: main.c
 *
 * Description: Definie un module pour le main
 * d'un programme de tri et de statistiques.
 *
 *
 * Auteure: Églantine Clervil
 * Date: 11 aout 2024
 */


#include <stdio.h>
#include <stdbool.h>
#define MAX_CHAR 80
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



/**
 * Affiche le manuel d'utilisation du programme
 */
void print_usage(void);


/**
 * Valide le nombre d'arguments en entree
 * et envoie un message d'erreur en cas d'erreur.
 * 
 * @param argc Le nombre d'arguments.
 * @param argv Les arguments de la ligne de commande.
 */
void validate_argc(int argc, char **argv);


/**
 * Affiche un message d'erreur en cas d'erreur d'ouverture
 * d'un fichier.
 *
 * @param file Le fichier a verifier
 */
void print_fopen_error(FILE *file);


/**
 * Ajoute un noeud dans une liste vide
 *
 * @param word_list La liste de mots
 * @param file Le fichier
 */
void validate_letters_in_word(char char_in_word, FILE *file);


/**
 * Verifie qu'une ligne est vide
 * 
 * @param line La ligne à vérifier
 */
bool is_empty_line(const char *line);


/**
 * Valider que le fichier d'entrée est ouvert
 * 
 * @param argv Les arguments de la ligne de commande.
 */
FILE *validate_input_file(char **argv);

/**
 * Valider que le fichier de sortie est ouvert
 * 
 * @param argv Les arguments de la ligne de commande.
 */
FILE *validate_output_file(char **argv);


/**
 * Valider les arguments de la ligne de commande
 *
 * @param argc Le nombre d'arguments.
 * @param argv Les arguments de la ligne de commande.
*/
void validate_argv(int argc, char **argv);


/**
 * Ajouter un mot venant d'un fichier dans 
 * la liste chainee
 * 
 * @param file La liste de mots
 * @param word_list La liste de mots
 */
void insert_word_from_file(FILE *file, LinkedList *word_list);


/**
 * Point d'entrée du programme.
 *
 * @param argc Le nombre d'arguments.
 * @param argv Les arguments de la ligne de commande.
 */
int main (int argc, char **argv);

#endif
