#ifndef HELPER_H
#define HELPER_H

/*
 * Module pour: helper.c
 *
 * Description: Module de support pour le main composé
 * des fonctions extraites de la fonction main.
 *
 * Auteure: Églantine Clervil
 * Date: 11 aout 2024
 */

#include <stdio.h>

/**
 * Affiche le manuel d'utilisation du programme
 */
void print_usage(void);

/**
 * Valide le nombre d'arguments en entree
 * et envoie un message d'erreur en cas d'erreur.
 * 
 * @param argv Les arguments de la ligne de commande.
 */
void validate_argc(int argc);

/**
 * Ajoute un noeud dans une liste vide
 *
 * @param word_list La liste de mots
 */
void validate_letters_in_word(char char_in_word);


/**
 * Affiche un message d'erreur en cas d'erreur d'ouverture
 * d'un fichier.
 *
 * @param file Le fichier a verifier
 */
void print_fopen_error(FILE *file);



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
#endif // VALIDATE_H
