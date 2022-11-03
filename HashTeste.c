#include <stdio.h>
#include <stdlib.h>
#include "HashTrab.c"


bool compara(void *data1, void *data2) {
    char[250] *d1 = (char*)data1;
    char[250] *d2 = (char*)data2;
    
    return strcmp(d1,d2)==0?true:false;
}
int main(){

    HashStruct *hash = (HashStruct*)malloc(sizeof(HashStruct)); 
    hashInit(hash);
    char palavra[250]

    File *dicionario = fopen("ListaDePalavrasPT.txt","r");
     while(fscanf(dicionario,"%{^\n}%*c\n",palavra)!=EOF){
        put(hash,palavra,palavra,compara);
     }
     fclose(dicionario);

    
    
    const int dimx = 50, dimy = 50;//Dimensão da matriz
    int i, j;
    
    FILE *grafico = fopen("graficoEspalhamento.ppm", "w");
    
    //Descrição do arquivo
    fprintf(grafico, "P6\n%d %d\n255\n", dimx, dimy);
    //Varre a matriz em coloca uma cor na posição
    int count=0;
    for (j = 0; j < dimy; ++j)
    {
        for (i = 0; i < dimx; ++i)
        {
            
            if(hash->hashes[count].size<250){
                //tente trocar o unsigned char por outros tipos
                //Verifique o que significa unsigned char
                static unsigned char color[3];
                color[0] = 0;  /* red */
                color[1] = 250-hash->hashes[count].size;  /* green */
                color[2] = 0;  /* blue */
                fwrite(color, 1, 3, grafico);//Escreve no arquivo a cor
            }else{
                //tente trocar o unsigned char por outros tipos
                //Verifique o que significa unsigned char
                static unsigned char color[3];
                color[0] = 0;  /* red */
                color[1] = 0  /* green */
                color[2] = 0;  /* blue */
                fwrite(color, 1, 3, grafico);//Escreve no arquivo a cor
                count++;
            }

        }
    }
    fclose(grafico);//Salva o arquivo
}