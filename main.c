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
    int tamanhoVetor = 10;
    
    for(int i = 0; i < 10; i++){
        
        int* vetor = criaVetor(tamanhoVetor);
        //imprime(v, 10);
        tempo = clock();
        bubblesort(vetor, tamanhoVetor);
        tempo = clock() - tempo;
        aux += tempo;
        tempo = 0;
        free(vetor);
    }
    printf("Tempo de execucao: %lf milissegundos", ((double)aux)/((CLOCKS_PER_SEC/1000)));
}
