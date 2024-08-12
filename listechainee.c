#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "helper.h"
#include "listechainee.h"

void initialize_list(LinkedList *word_list) {
    word_list->head = NULL;
    word_list->tail = NULL;
    word_list->word_count = 0;
}


void print_empty_list_message(const LinkedList *word_list) {
    if (word_list->word_count == 0) {
        printf("La liste de mots est vide\n");
        return;
    }
}

void delete_duplicate(LinkedList *word_list) {
    Node *current = word_list->head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->word, current->next->word) == 0) {
            
            Node *duplicate = current->next;
            current->next = duplicate->next;
            word_list->word_count--;
            
            free(duplicate->word);
            free(duplicate);

            if (current->next == NULL) {
                word_list->tail = current;
            }
        } else {
            current = current->next;
        }
    }
}

void free_word_list(LinkedList *word_list) {
    Node *current = word_list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current->word); 
        free(current);
        current = next;
        word_list->word_count--;
    }
    word_list->head = NULL;
}

void print_list(const LinkedList *word_list) {
    print_empty_list_message(word_list);
    Node *current = word_list->head;;

    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

struct Node* create_node(const char *new_word) {
    struct Node* new_node = (struct Node*)malloc(sizeof(Node));
    
    if (new_node == NULL) {
        perror("Erreur d'allocation de mémoire pour le nœud");
        exit(EXIT_FAILURE);
    }

    new_node->word = (char*)malloc(strlen(new_word) + 1);
    
    if (new_node->word == NULL) {
        perror("Erreur d'allocation de mémoire pour le mot");
        free(new_node);
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->word, new_word);
    new_node->next = NULL;

    return new_node;
}


void insert_into_empty_list(LinkedList *word_list, Node *new_node) {
    word_list->head = new_node;
    word_list->tail = new_node;
    word_list->word_count++;
}

void insert_in_order(LinkedList *word_list, const char *new_word) {
    Node *new_node = create_node(new_word);

    if (word_list->word_count == 0) {
        insert_into_empty_list(word_list, new_node);
        return;
    }
    Node *current = word_list->head;
    Node *previous = NULL;

    while (current != NULL && strcmp(current->word, new_node->word) <= 0) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        new_node->next = word_list->head;
        word_list->head = new_node;
    } else {
        previous->next = new_node;
        new_node->next = current;

        if (current == NULL) {
            word_list->tail = new_node;
        }
    }

    word_list->word_count++;
}


void insert_word_from_file(FILE *file, LinkedList *word_list) {
    char line[MAX_CHAR + 1];
    char line_copy[MAX_CHAR + 1];
    while (fgets(line, sizeof(line),file)) {
        strcpy(line_copy, line);
        char *word = strtok(line_copy, " \n");
        while (word != NULL) {
            for (int i = 0; word[i] != '\0'; i++) {
                validate_letters_in_word(word[i]);
            }
            insert_in_order(word_list, word);
            word = strtok(NULL, " \n");
        }
    }
}


