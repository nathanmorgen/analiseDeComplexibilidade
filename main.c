#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.c"
#include "ordenacao.h"

//aloca e cria um vetor de tamanho n, com elementos aleatorios
int* criaVetor(int tamanho) {
    int *v = malloc(tamanho * sizeof(int));

    srand((unsigned)time(NULL));
    for(int i = 0; i < tamanho; i++){
        v[i] = rand();
    }
    return v;
}
//funcao criada apenas para motivos de teste, ela imprime :).
void imprimeVetor(clock_t* v, int tamanho){
    for (int j = 0; j < tamanho; j++) printf("(%d, %lf)\n", j, (double)v[j]);
    free(v);
}
//funcao responsavel por checar qual o maior e o menor elemento de um vetor
void maiorMenor(clock_t *vet, int tam, clock_t *menor, clock_t *maior){
    *menor = *vet;
    *maior = *vet;
    for(int i = 1; i < tam; i++){
        if(*menor > *(vet + i))
            *menor = *(vet + i);
        if(*maior < *(vet + i))
            *maior = *(vet + i);
    }
}

int main(void){

    clock_t tempo;
    clock_t aux = 0;
    //estes vetores serao usados para armazenar o tempo de cada rodada para cada tamanho de vetor.
    clock_t* v10 = malloc(10*sizeof(clock_t));
    clock_t* v100 = malloc(10*sizeof(clock_t));
    clock_t* v1000 = malloc(10*sizeof(clock_t));
    clock_t* v10000 = malloc(10*sizeof(clock_t));
    clock_t* v100000 = malloc(10*sizeof(clock_t));
    clock_t* v1000000 = malloc(10*sizeof(clock_t));
    //estas irao receber os tempos pico das rodadas
    clock_t maior, menor;
    printf("Teste para o Bubble Sort\n\n");
    for(int i = 10; i <= 10000; i=i*10){
        for(int j = 0; j < 10; j++){
            
            int* vetor = criaVetor(i);
            tempo = clock();//tempo inicial
            //aqui eu simplesmente troquei a funcao para cada teste e compilei, para evitar aumentar a complexidade do codigo.
            bubblesort(vetor, i);
            //mergeSort(vetor, 0, i-1);
            tempo = clock() - tempo;//tempo inicial menos o tempo final nos da o tempo que o processo levou para ser concluido.
            //para cada tamanho de vetor o tempo sera armazenado em outro vetor
            if(i == 10){
                v10[j] = tempo;
            }else if (i==100)
            {
                v100[j] = tempo;
            }else if (i == 1000)
            {
                v1000[j] = tempo;
            }else if (i == 10000)
            {
                v10000[j] = tempo;
            }else if (i == 100000)
            {
                v100000[j] = tempo;
            }else{
                v1000000[j] = tempo;
            }
            //a variavel aux vai servir o para calculo da media.
            aux += tempo;
            //reinicio a variavel e libero o meu vetor
            tempo = 0;
            free(vetor);
        }
        aux = aux/10;
        printf("O tempo de medio de execucao para vetores de tamanho %d foi de %lf ms.\n", i,(double)aux*10);
        aux = 0;
    }
    printf("\n");
    maiorMenor(v10, 10, &menor, &maior);
    printf("Diferenca entre o maior e o menor tempo de execucao das 10 rodadas: %lf ms.\n", (double)(maior-menor));
    maiorMenor(v100, 10, &menor, &maior);
    printf("Diferenca entre o maior e o menor tempo de execucao das 10 rodadas: %lf ms.\n", (double)(maior-menor));
    maiorMenor(v1000, 10, &menor, &maior);
    printf("Diferenca entre o maior e o menor tempo de execucao das 10 rodadas: %lf ms.\n", (double)(maior-menor));
    maiorMenor(v10000, 10, &menor, &maior);
    printf("Diferenca entre o maior e o menor tempo de execucao das 10 rodadas: %lf ms.\n", (double)(maior-menor));
    maiorMenor(v100000, 10, &menor, &maior);
    printf("Diferenca entre o maior e o menor tempo de execucao das 10 rodadas: %lf ms.\n", (double)(maior-menor));
    maiorMenor(v1000000, 10, &menor, &maior);
    printf("Diferenca entre o maior e o menor tempo de execucao das 10 rodadas: %lf ms.\n", (double)(maior-menor));
}
