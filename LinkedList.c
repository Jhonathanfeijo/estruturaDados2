#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void init (LinkedList *list){
    List->first=NULL;
    List->size=0;
}

bool isEmpty(LinkedList *list){
    if(list->first==NULL) return 1;
    return 0; 
}

int enquaue(LinkedList *list, void *data ){
    Node *newNode =(Node*)malloc(sizeof(Node));
    if(newNode==NULL) return -1;
    newNode->data=data;
    newNode->next=NULL;

    if(isEmpty(list))
        list->first=newNode;
    else{
        Node *aux = list->first;
        while(aux ->next!=NULL) 
            aux=aux->next;
        aux->next=newNode;
        
    }
    list->size++;
    return 1;
}

void* dequeue(LinkedList *list){
    if(isEmpty(list)) return NULL;
    Node *aux = list->first;
    list->first=aux->next;
    void *data = aux->data;
    free(aux);
    list->size--;
    return data;
}

void* first(LinkedList *list){
    if(isEmpty(list))return NULL;
    Node *aux = list->first;
    void *data=aux->data;
    free(aux);
    return data;
}
void* last(LinkedList *list){
    if(isEmpty(list)) return NULL;
    Node *aux =list->first;
    while(aux->next!=NULL)
        aux=aux->next;
    void *data=aux->data;
    return data;
}
int push(LinkedList *list, void *data){
    Node *newNode =(Node*)malloc(sizeof(Node));
    if(newNode==NULL) return -1;
    newNode->data=data;
    newNode->next=NULL;
    List->first=newNode;
    return 1;
}