#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

void init(DoublyLinkedList *list){
    Node *newNode =(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memoria insuficiente");
        
    }else{
    newNode->data=NULL;
    newNode->next=newNode;
    newNode->previous=newNode;
    list->first=newNode;
    list->size=0;
    }
}

int enqueue(DoublyLinkedList *list, void *data){
    Node *newNode =(Node*)malloc(sizeof(Node));
        if(newNode==NULL){
        return -1;
    }
    newNode->data=data;

    newNode->next=list->first;
    newNode->previous=list->first->previous;
    list->first->previous->next=newNode;
    list->first->previous=newNode;
    list->size++;
    return 1;
}


void* dequeue(DoublyLinkedList *list){
    if(list->size==0){
        return NULL;
    }
    Node *removido = list->first->next;
    void *data = removido->data;
    list->first->next=removido->next;
    list->first->next->previous=list->first;
    free(removido);
    list->size--;
    return data;
}

void* first(DoublyLinkedList *list){
    Node *sentinela = list->first;
    void *data = sentinela->next->data;
    return data;   
}

void* last(DoublyLinkedList *list){
    Node *sentinela = list->first;
    void *data = sentinela->previous->data;
    return data; 
}
int push(DoublyLinkedList *list, void *data){
    Node *sentinela = list->first;
    Node *newNode =(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        return -1;
    }
    newNode->data=data;
    newNode->next=sentinela->next;
    newNode->next->previous=newNode;
    newNode->previous=sentinela;
    sentinela->next=newNode;
    list->size++;
    return list->size;
}

void* pop(DoublyLinkedList *list){
    if(list->size==0){
        return NULL;
    }
    void*data=dequeue(list);
    return data;
}

void* top(DoublyLinkedList *list){
    void*data=last(list);
    return data;
}

bool isEmpty(DoublyLinkedList *list){
    if(list->size==0) return true;
    return false;
}

int indexOf(DoublyLinkedList *list,void *data, compare equal){
    if(isEmpty(list)) return -1;
    Node * sentinela = list->first;
    Node *aux= sentinela->next;
    int contador=0;
    while(!equal(data,aux->data) && aux!=sentinela){
        aux=aux->next;
        contador++;
    }
     return aux==sentinela?-1:contador;
}

Node* getNodeByPos(DoublyLinkedList *list,int pos){
    if(isEmpty(list)) return NULL;
    if(pos>=list->size) return NULL;
    Node * aux = list->first->next;
    for(int i=0;i<pos;i++){
    aux=aux->next;
    }
    return aux;
}

void* getPos(DoublyLinkedList *list,int pos){
    Node *aux=getNodeByPos(list,pos);
    void *data = aux->data;
    return data;
}

int add(DoublyLinkedList *list, int pos, void *data){
    if(isEmpty(list)==1)return -1;
    Node *newNode =(Node*)malloc(sizeof(Node));
    if(newNode==NULL) return -1;
    newNode->data=data;
    Node * oldNodeByPos = getNodeByPos(list,pos);
    newNode->next=oldNodeByPos;
    newNode->previous=oldNodeByPos->previous;
    oldNodeByPos->previous->next=newNode;
    oldNodeByPos->previous=newNode;
    list->size++;
    return list->size;
}

void* removePos(DoublyLinkedList *list, int pos){
    
    Node *removido= getNodeByPos(list,pos);
    if(removido==NULL) return NULL;
    removido->next->previous=removido->previous;
    removido->previous->next=removido->next;
    void* data = removido->data;
    free(removido);
    list->size--;
    return data;
}

bool removeData(DoublyLinkedList *list, void *data, compare equal){
    if(isEmpty(list)) return 0;
    Node* aux =list->first->next;
    while(!equal(aux->data,data) && aux!=list->first){
        aux=aux->next;
    }
    if(aux==list->first) return -1;
    aux->next->previous=aux->previous;
    aux->previous->next=aux->next;
    aux->data=0;
    free(aux->data);
    free(aux);
    return 1;

}
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource){
    Node *aux =getNodeByPos(listDest,pos);
    if(aux==NULL || isEmpty(listSource)) return -1;
    listSource->first->previous->next=aux;
    listSource->first->next->previous=aux->previous;
    aux->previous->next=listSource->first->next;
    aux->previous=listSource->first->previous;
    listDest->size+=listSource->size;
    return listDest->size;
}
void show(DoublyLinkedList *list, printNode print){
    if(!isEmpty(list)){
        Node* aux = list->first->next;
        while(aux!=list->first){
            print(aux->data);
            aux=aux->next;
        }
    }
}

void showMem(DoublyLinkedList *list){
    if(!isEmpty(list)){
        Node* aux = list->first;
        int contador = 0;
        printf("\n\n Memoria do No  -  Memoria do Dado  -  Memoria  do Previous  -  Memoria do Next  -  \n\n");
        printf(" %p  -   %px  -  %p  -  %p  - \n\n",aux,aux->data,aux->previous,aux->next);
        aux=aux->next;
        while(aux!=list->first){
            printf(" %p  -   %p  -  %p  -  %p  - \n\n",aux,aux->data,aux->previous,aux->next);
            aux=aux->next;
        }
    }
}
