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
    int nombre_noeud;
} LinkedList;

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












