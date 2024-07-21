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
void insert_into_empty_list(LinkedList *listPtr, Node *new_node) {
    if (listPtr->word_count == 0) {
        listPtr->head = new_node;
        listPtr->tail = new_node;
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




