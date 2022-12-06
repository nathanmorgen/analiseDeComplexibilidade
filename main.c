#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.c"
#include "ordenacao.h"

int* criaVetor(int tamanho) {
    int *v = malloc(tamanho * sizeof(int));

    //srand(time(NULL));
    srand((unsigned)time(NULL));
    for(int i = 0; i < tamanho; i++){
        v[i] = rand();
    }
    return v;
}

void imprimeVetor(int* v, int tamanho){
    for (int j = 0; j < tamanho; j++) printf("(%d, %d)\n", j, v[j]);
    free(v);
}

int main(void){

    clock_t tempo;
    clock_t aux = 0;
    printf("Teste para o bubblesort\n\n");
    for(int i = 10; i <= 10000; i=i*10){
        printf("Vetor tamanho %d:\n",i);
        for(int j = 0; j < 10; j++){
            //printf("i = %d\n",j);
            int* vetor = criaVetor(i);
            //imprime(v, 10);
            tempo = clock();
            bubblesort(vetor, i);
            tempo = clock() - tempo;
            aux += tempo;
            tempo = 0;
            free(vetor);
        }
        printf("Tempo de execucao: %lf milissegundos\n", ((double)aux)/((CLOCKS_PER_SEC/1000)));
        aux = 0;
    }
}
