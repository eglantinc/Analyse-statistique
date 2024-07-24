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

void insert_in_order(LinkedList *word_list, char *new_word) {
    Node *newNodePtr = create_node(new_word);

    if (word_list->word_count == 0) {
        word_list->head = newNodePtr;
        word_list->tail = newNodePtr;
        word_list->word_count++;
        return;  
    }

    Node *current = word_list->head;
    Node *previous = NULL;

    while (current != NULL && strcmp(current->word, newNodePtr->word) <= 0) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        newNodePtr->next = word_list->head;
        word_list->head = newNodePtr;
    } else {
        previous->next = newNodePtr;
        newNodePtr->next = current;

        if (current == NULL) {
            word_list->tail = newNodePtr;
        }
    }

    word_list->word_count++;
}


