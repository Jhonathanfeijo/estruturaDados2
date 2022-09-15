#include<stdio.h>
#include<stdlib.h>
#include"GeneralizedList.h"


int addAtom(Node **list, int atom){
    Node* newNode = (Node*)malloc(sizeof(Node))
    if(newNode==NULL) return -1;
    newNode->type=0
    newNode->atomList.atom=atom;
    newNode->next=NULL;
    if(*list==NULL){
        *list=newNode;
    }
    for(Node* aux=*list;aux->next!=NULL;aux=aux->next)
    aux->next=newNode;
}

int addList(Node **list, Node **subList){
        Node* newNode = (Node*)malloc(sizeof(Node))
    if(newNode==NULL) return -1;
    newNode->type=1
    newNode->atomList.list=list;
    newNode->next=NULL;
    if(*list==NULL){
        *list=newNode;
    }
    for(Node* aux=*list;aux->next!=NULL;aux=aux->next)
    aux->next=newNode;
}


Node* head(Node *list){
    Node* headAux = NULL;
    if(headAux->type==0){
        headAux=(Node*)malloc(sizeof(Node));
        headAux->type=0;
        headAux->atomList.atom=list->atomList.atom;
        headAux->next=NULL;
    }
    if(headAux->type==1){
        headAux=(Node*)malloc(sizeof(Node));
        headAux->type==1;
        headAux->atomList.list=list->atomList.list;
        headAux->next=NULL;
    }
    return headAux;
}

Node* tail(Node *list){
    return Node* tailAux=list->next;

}

void show(Node *list){
    printf("(")
    for(Node* aux=list; aux->next!=NULL;aux=aux->next){
        if(aux->type==0){
            printf("%d",aux->atomList.atom);
        }else{
            show(aux->atomList.list);
        }
    }
    printf(")");
}
bool search(Node *list, int atom){
    bool found = false;
    for(Node* aux=list; aux->next!=NULL && found!=true ; aux=aux->aux){
        if(aux->type==0){
            if(aux->atomList.atom==atom) found=true;
        }
    }
}