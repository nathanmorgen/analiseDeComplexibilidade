#include <math.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int *vet, int n){
    int i, mudou, fim;
    fim = n-1;
    do{
        mudou = 0;
        for(i = 0; i < fim; i++){
            if(vet[i] > vet[i+1]){
                swap(&vet[i], &vet[i+1]);
                mudou = 1;
            }
        }
        fim--;
    }while(mudou);
}

void selectionSort(int *vet, int n){
    int i, j, menor;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i; j < n; j++){
            if(vet[j] < vet[menor]){
                menor = j;
            }
        }
        if(i != menor){
            swap(&vet[i], &vet[menor]);
        }
    }
}

void insertionSort(int *vet, int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = vet[i];
        j = i;
        while(j > 0 && aux < vet[j-1]){
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = aux;
    }
}

void merge(int* vet, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio +1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc(tamanho * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(vet[p1]< vet[p2]){
                    temp[i] = vet[p1];
                    p1++;
                }else{
                    temp[i] = vet[p2];
                    p2++;
                }
                if(p1>meio){
                    fim1 = 1;
                }
                if(p2>fim){
                    fim2 = 1;
                }
            }else{
                if(!fim1){
                    temp[i] = vet[p1];
                    p1++;
                }else{
                    temp[i] = vet[p2];
                    p2++;
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){
            vet[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *vet, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio+1, fim);
        merge(vet, inicio, meio, fim);
    }
}

int particiona(int *vet, int inicio, int fim){
    int esq, dir, pivo;
    esq = inicio;
    dir = fim;
    pivo = vet[inicio];
    while(esq < dir){
        while(esq <= fim && vet[esq] <= pivo){
            esq++;
        }
        while(dir >= inicio && vet[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            swap(&vet[esq], &vet[dir]);
        }
    }
    swap(&vet[inicio], &vet[dir]);
    return dir;
}

void quickSort(int *vet, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(vet, inicio, fim);
        quickSort(vet, inicio, pivo-1);
        quickSort(vet, pivo+1, fim);
    }
}

