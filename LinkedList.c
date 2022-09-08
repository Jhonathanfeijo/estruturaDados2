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
    log_debug("size: %p",list->size);
    log_trace("init<-");
}

bool isEmpty(LinkedList *list){
    if(list->size==0) return 1;
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

int add(LinkedList *listDest, int pos, void* data){
    if(isEmpty(listDest)){
        return -1;
    }
    Node* aux = getNodeByPos(listDest,pos-1);
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL)return -1;
    newNode->data=data;
    newNode->next=aux->next;
    aux->next=newNode;
    listDest->size++;
    return 1;

}


int addAll(LinkedList *listDest, int pos, LinkedList *listSource){
    //Se a lista, que deseja acrescentar na lista fonte, estiver vazia, retorna -1
    if(isEmpty(listDest)) return -1;

    if(isEmpty(listSource)){
        listSource=listDest;
        return listDest->size;
    }
    //auxBegin recebe um nó antes da posição solicitada
    Node *auxBegin = getNodeByPos(listSource,pos-1);
    //auxEnd recebe o ultimo nó da lista que será adicionada
    Node *auxEnd=getNodeByPos(listDest,listDest->size-1);
    auxEnd->next=auxBegin->next;
    auxBegin->next = listDest->first;
    listSource->size+=listDest->size;
    return listSource->size;
}

int indexOf(LinkedList *list, void *data, compare equal){
    //Verifica se a lista está vazia
    if(isEmpty(list)) return -1;
    //Se não está vazia, vai comparando data de cada nó até encontrar a posição, 
    //se não tiver na lista retorna -1;
    int i=0;
    Node *aux=list->first;
    while(aux!=NULL && !equal(aux->data,data)){
        aux=aux->next;
        i++;
    }
    return (aux==NULL)?-1:i;
}
Node* getNodeByPos(LinkedList *list, int pos){
    //Verificando se a lista não está vazia e se posição não é >= tamanho da lista
    if(isEmpty(list) || pos>=list->size ) return NULL;

    //Retorna primeiro item da lista
    if(pos<=0) return list->first;

    //Se não for o primeiro item da lista, vai comparando os demais
    Node * aux=list->first;
    for(int count = 0; (aux!=NULL && count<pos); count++,aux=aux->next);
    return aux;
}

void* getPos(LinkedList *list, int pos){
    
    if(isEmpty(list)) return NULL;

    //Chama getNodeByPos para conseguir o nó daquela posição e, então, o endereço data armazenado naquele nó
    Node *aux=getNodeByPos(list,pos);
    void *data = aux->data;
    return aux->data;
}

void* removePos(LinkedList *list, int pos){
    //Chama a função dequeue para remover a primeira posição
    if(pos<=0){
        return dequeue(list);
    }

    // Chama nó que está a uma posição anterior da solicitada
    Node *aux = getNodeByPos(list,pos-1);

    // Coloca o nó posterior de pos como o next do nó posterior de pos
    Node *removed = aux->next;
    aux->next=removed->next;
    void *data= removed->data;
    free(removed);
    list->size--;
    return data;
}

bool removeData(LinkedList *list, void *data, compare equal){
    if(isEmpty) return -1;
    
    // Conseguindo index do Nó
    int pos=indexOf(list,data,equal);

    if(pos==-1) return false;


    // Caso seja a primeira posição, (pos==0), tornaremos o segundo nó em primeiro no LinkedList e posteriormente faremos o free no antigo first->data e no antigo first
    if(pos==0){
        Node *removed=list->first;
        list->first=removed->next;
        removed->data=0;
        free(removed->data);
        free(removed);
        list->size--;
        return true;
    }
    // Caso não atenda as condições anteriores, chamaremos a função removePos que realiza o free no nó e devolve data que estava naquele Nó,
    // então realizaremos o free no data retornado
    Node* aux=getNodeByPos(list,pos-1);
    Node *removed=aux->next;
    aux->next=removed->next;
    removed->data=0;
    free(removed->data);
    free(removed);
    return true;
}