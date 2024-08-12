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

#define MAX_CHAR 80

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



#include <stdio.h>
#include <stdbool.h>

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
bool validate_argc(int argc);

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
bool validate_argv(int argc, char **argv);

/**
 * Valider le argc et le argv de la ligne de commande
 * et quitter si invalides
 *
 * @param argc Le nombre d'arguments.
 * @param argv Les arguments de la ligne de commande.
*/
void validate_inputs(int argc, char **argv);
#endif // VALIDATE_H
