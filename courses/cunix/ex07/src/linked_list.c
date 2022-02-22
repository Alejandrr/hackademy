#include "../include/linked_list.h"
#include <stddef.h>
#include <malloc.h>


void    list_print(node_t* head) {
    if (head == NULL)
        return ;
    printf("DEBUG: %s\n", (char*)head->data);
    list_print(head->next);
}
node_t* list_create(void* data) {
   
    node_t* head = (node_t*)malloc(sizeof(node_t));
    if (head==NULL) {
        return NULL;
    }

    head->data = data;
    head->next = NULL;
    return head;
}

void list_destroy(node_t** head, void (*fp)(void* data)) {
    if(*head==NULL){
        return;
    }
    
    fp((*head)->data);
    list_destroy(&((*head)->next), fp);
    free(*head);
    *head = NULL;
}
void    list_push(node_t* head, void* data) {
    if (head == NULL) {
        return;
    }

    node_t* end=head; 
    while (end->next != NULL)
        end = end->next;

    end->next = (node_t*)malloc(sizeof(node_t));
    if (end->next == 0x0) {
        return;
    }

    end->next->data = data;
    end->next->next = NULL;
}
void    list_unshift(node_t** head, void* data) {
    if (*head == NULL) {
        return;
    }

    node_t* newHead = (node_t*)malloc(sizeof(node_t));
    if (newHead == NULL) {
        return;
    }
    
    newHead->data = data;
    newHead->next = *head;
    *head = newHead;
}

void* list_pop(node_t** head) {
    if (*head == NULL) {
        return NULL;
    }

    void* result ;
    if ((*head)->next == NULL) {
        result = (*head)->data;
        free(*head);
        *head = NULL;
        return result;
    }

    node_t*tmp = *head;
    while (tmp->next->next != NULL)
        tmp = tmp->next;

    result = tmp->next->data;
    free(tmp->next);

    tmp->next = NULL;
    return result;
}
void* list_shift(node_t** head) {

    if (*head == NULL) {
        return NULL; 
    }
    void* result ;
    if ((*head)->next == NULL) {
        result = (*head)->data;
        free(*head);
        *head = NULL;
        return result;
    }

    node_t* HeadNew = (*head)->next;
    result = (*head)->data;
   
    free(*head);
    *head = HeadNew;
    return result;
}
void* list_remove(node_t** head, int pos) {
    if (*head == NULL) {
        return NULL; 
    }
    if (pos < 1) {
        return NULL;// Out of range 
    }
    if (pos == 1) {
        list_shift(head);
    }

    int currentPos = 1; 
    node_t* prev=NULL, *tmp=*head;
    while (tmp->next != NULL) {
        prev = tmp;
        tmp  = tmp->next;
        currentPos++;
        if (currentPos == pos){
            break;
        }
    }
    if (currentPos != pos) {
        return NULL;             //pos is out of range  
    }
    void *result  = tmp->data;
    prev->next = tmp->next;
    free(tmp);
    return result;
}

void    list_visitor(node_t* head, void (*fp)(void* data)) {
    if (head == NULL)
        return;
    fp(head->data);
    list_visitor(head->next,fp);
}
