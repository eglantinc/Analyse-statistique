#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H
#include <stdio.h>
/*
 * Module pour: listechainee.c
 *
 * Description: Definie une liste chainee avec des fonctions
 * qui permetteront de trier une liste de mots et faire
 * des statistiques. 
 *      
 *
 * Auteure: Églantine Clervil
 * Date: 11 aout 2024
 */

// Noeud 
typedef struct Node {
    char *word; // Mot
    struct Node* next; // Pointeur vers le prochain mot
} Node;

typedef struct LinkedList {
    struct Node *head; // Tete de la liste chainee
    struct Node *tail; // Queue de la liste chainee
    int word_count; // Nombre de mot dans la liste chainee
} LinkedList;


/**
 * Initialise la liste de mots 
 * @param *word_liste La liste de mots
 */
void initialize_list(LinkedList *word_list);

/**
 * Affiche un message si la liste est vide
 * @param *word_list La liste de mots
 */
void print_empty_list_message(const LinkedList *word_list);

/**
 * Libere allocation de memoire de chaque noeud
 * de la liste de mots
 *
 * @params *head Un pointeur sur la tete de la liste
 */
void free_word_list(LinkedList *word_list);

/**
 * Supprime les mots en double et ne garde qu'un seul 
 * exemplaire de chaque mot dans la liste
 *
 * @param *word_list La liste de mots
 */
void delete_duplicate(LinkedList *word_list);

/**
 * Affiche la liste de mots
 *
 * @param *word_list La liste de mots
 */
void print_list(const LinkedList *word_list);

/**
 * Cree un noeud
 *
 * @param *new_word Le nouveau mot qui sera dans le noeud
 */
Node* create_node(const char *new_word);

/**
 * Ajoute un noeud dans une liste vide
 *
 * @param *word_list La liste de mots
 * @param *new_node noeud a ajouter
 */
void insert_into_empty_list(LinkedList *word_list, Node *new_node);

/**
 * Ajoute un nouveau mot dans une liste
 *
 * @param *word_list La liste de mots
 * @param *new_node La nouveau mot a ajouter
 */
void insert_in_order(LinkedList *word_list, const char *new_word);

/**
 * Ajouter un mot venant d'un fichier dans
 * la liste chainee
 *
 * @param file La liste de mots
 * @param word_list La liste de mots
 */
void insert_word_from_file(FILE *file, LinkedList *word_list);



#endif 

