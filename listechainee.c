#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
    char *word;
    struct Node* next;
} Node;

typedef struct LinkedList{
    struct Node *head;
    struct Node *tail;
    int word_count;
} LinkedList;

void initialize_list(LinkedList *word_list) {
    word_list->head = NULL;
    word_list->tail = NULL;
    word_list->word_count = 0;
}

void insert_into_empty_list(LinkedList *word_list, Node *new_node) {
    if (word_list->word_count == 0) {
        word_list->head = new_node;
        word_list->tail = new_node;
        word_list->word_count++;
    }
}

void print_list(LinkedList *word_list) {
    if (word_list->word_count == 0) {
        printf("La liste de mot est vide");
        return;
    }

    Node *current = word_list->head;;

    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

struct Node* create_node(char *new_word) {
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



