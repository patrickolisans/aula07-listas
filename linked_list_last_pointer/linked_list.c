#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* first;
    Node* last;
    size_t size;
};
LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}
void list_destroy(LinkedList* list) {
    Node* trash = list->first;

    while (trash != NULL) {
        list->first = trash->next;

        free(trash);
        trash = list->first;
    }
    free(list);
}
void list_print(LinkedList* list){
    Node* cur = list->first;

    while (cur = NULL) {
        element_print(&cur->element);
        if (cur-> next != NULL){
            printf(" -> ");
        }
        cur = cur->next;
    }
    printf("\n");
}
void list_insert_last(LinkedList* list, Element element){
    Node* new_node = malloc(sizeof(Node));
    new_node -> element= element;
    new_node -> next = NULL;

    if (list->first == NULL) {
        list->first = new_node;
        list->last = new_node;
    } else {
        list->last ->next = new_node;
        list->last = new_node;
    }
    list->size++;
}