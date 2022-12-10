#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.c"
#include "ordenacao.h"

int* criaVetor(int tamanho) {
    int *v = malloc(tamanho * sizeof(int));

    srand((unsigned)time(NULL));
    for(int i = 0; i < tamanho; i++){
        v[i] = rand();
    }
    return v;
}
/*
//funcao criada apenas para motivos de teste
void imprimeVetor(int* v, int tamanho){
    for (int j = 0; j < tamanho; j++) printf("(%d, %d)\n", j, v[j]);
    free(v);
}
*/
int main(void){

    clock_t tempo;
    clock_t aux = 0;
    printf("Teste para o Bubble Sort\n\n");
    for(int i = 10; i <= 10000; i=i*10){
        printf("Vetor tamanho %d:\n",i);
        for(int j = 0; j < 10; j++){
            int* vetor = criaVetor(i);
            tempo = clock();
            //aqui eu simplesmente troquei a funcao para cada teste e compilei, para evitar aumentar a complexidade do codigo.
            bubblesort(vetor, i);
            //mergeSort(vetor, 0, i-1);
            tempo = clock() - tempo;
            aux += tempo;
            tempo = 0;
            free(vetor);
        }
        printf("Tempo de medio de execucao: %lf milissegundos\n", ((double)aux/10)/((CLOCKS_PER_SEC/1000)));
        aux = 0;
    }
}
