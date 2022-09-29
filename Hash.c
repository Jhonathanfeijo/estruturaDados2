#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Hash.h"

void initHash(HashStruct *hashStruct){
    for(int i=0;i<MAX;i++){
        init(&hashStruct->hashes[i]);
    }
    hashStruct->size=0;
}
bool isHashEmpty(HashStruct *hashStruct){
    if(hashStruct->size==0) return 1;
    
    return 0;
}

int hash(char *key){
    int sumAscii=0;
    for(int i=0; key[i]!=0;i++){
        sumAscii+=key[i]*(i+1);
    }
    return sum%MAX;
}
int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    int res=enqueue(hashStruct->hashes[hash(key)],data);
    hashStruct->size+=res;
    return res;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal){

    int hashValor = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValor],key,equal); 
    return (pos!=-1)?true:false;
}

void* get(HashStruct *hashStruct, char *key, compare equal){
    int hashValor = hash(key);
    Node * aux = hashStruct->hashes[hashValor].first->next;
    while(aux!=hashStruct->hashes[hashValor].first && !equal(aux->data,key)){
        aux=aux->next;
        }
        return aux->data;
}
void* removeKey(HashStruct *hashStruct, char *key, compare equal) {
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    void* result = removePos(&hashStruct->hashes[hashValue], pos);
    if (result!=NULL) hashStruct->size--;
    return result;
}