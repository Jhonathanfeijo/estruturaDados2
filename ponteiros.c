#include <stdlib.h>
#include <stdio.h>

int main() {
    int number=10;
    int* numberp=&number;
    int **numberpp=&numberp;
    printf("Valor da variavel number:%d\n",number);
    printf("Endereco da variavel number:%p\n",&number);
    printf("Valor da variavel numberP: %p\n",numberp);
    printf("Valor apontado por numberP:%d\n",*numberp);
    printf("Endereco de memoria numberP:%p\n",&numberp);
    printf("endereco de memoria de numberPP: %p\n",&numberpp);
    printf("Conteudo de numberPP: %p\n",numberpp);
    printf("Valor apontado no primeiro nivel por numberPP: %p\n",*numberpp);
    printf("Valor apontado no ultimo nivel por numberPP: %d\n", **numberpp);
    //numberp++;
    //printf("numberp++ %p\n",numberp++);
    float *pi =(float *) malloc(sizeof(float));
    printf("Endereco de p: %p\n",pi);
    *pi=3.1415;
    printf("Valor em pi %f\n",*pi);
    *pi=0;
    free(pi);
    printf("Endereco apos free: %p\n",pi);
    pi=NULL;
    printf("endereco apos null: %p\n",pi);

    return EXIT_SUCCESS;
}