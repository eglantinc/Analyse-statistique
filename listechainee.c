#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    char *word;
    struct Node* next;
} Node;

typedef struct {
    struct Node *head;
    struct Node *tail;
    int nombre_noeud;
} LinkedList;
