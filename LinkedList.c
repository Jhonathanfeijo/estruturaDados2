#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"


void init (LinkedList *list){
    log_info("Inicializando a lista");
    log_trace("init->");
    list->first=NULL;
    list->size=0;
    log_debug("first: %p",list->first);
    log_debug("size: %p",list-size);
    log_trace("init<-");
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

    if(isEmpty(list)){
       newNode->data=data;
       list->first=newNode;
       list->size++;
        return 1;
     }
     newNode->next=list->first;
     list->first=newNode;
     list->size++;

    return 1;
}

void* getPos(LinkedList *list, int pos){
    if(isEmpty(list)){
        return -1;
    }
    int i=0;
    Node* aux = list->first;
    while(i!=list->size && aux->next!=NULL){
        aux=aux->next;
    }
    void *data = aux->data;
    return data;
}

void* pop(LinkedList *list){
    void* data = dequeue(&list);
    return data;
}

void* top(LinkedList *list){
    Node* aux = list->first;
    void* data = aux->data;
    return data;
}

void * add(LinkedList *listDest, int pos, void* data){
    if(isEmpty(listDest)){
        return -1;
    }
    Node* aux = listDest->first;
    int i=0;
    while(i<pos){
        aux=aux->next;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next->aux->next;
    aux-next->newNode;


}


int addAll(LinkedList *listDest, int pos, LinkedList *listSource){
    if(isEmpty(listSource) || isEmpty(listDest)){
        return -1;
    }
    int=0
    Node *auxBegin = listSource->first;
    Node *auxEnd=NULL;
    while(i<pos){
        auxBegin=auxBegin->next;
        i++;
    }
    auxEnd=auxBegin->next;
    auxBegin->next = listDest->first;
    auxBegin=listSource->first;
    while(auxBegin->next!=NULL){
        auxBegin=auxBegin->next;
    }
    auxBegin->next=auxEnd;
    listSource->size+=listDest->size;
    return listSource->size;
}