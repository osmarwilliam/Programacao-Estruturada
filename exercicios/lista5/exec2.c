/*
Escreva uma função que recebe um vetor de inteiros e retorna o maior elemento e o
menor elemento.
*/

#include <stdio.h>
#include <stdlib.h>

void achar_maior_menor(int *v, int *maior, int *menor, int tamanho);
void achar_maior_menor_2(int *vetor, int *maior, int *menor, int length);

int main(){

    int v[] = {1,2,3,4,5,6,10,15,13, 19};

    int tam = sizeof(v) / sizeof(v[0]);
    int maior;
    int menor;

    achar_maior_menor(v, &maior, &menor, tam);

    printf("O maior número nesse vetor é: %d, e o menor é: %d \n", maior, menor);

    int *maior_2 = (int*)(malloc(sizeof(int)));
    int *menor_2 = (int*)(malloc(sizeof(int)));
    
    achar_maior_menor_2(v, maior_2, menor_2, sizeof(v)/sizeof(v[0]));

    printf("O maior número nesse vetor é: %d, e o menor é: %d", *maior_2, *menor_2);

    free(maior_2);
    free(menor_2);

    return 0;
}

void achar_maior_menor(int *v, int *maior, int *menor, int tamanho){
    *maior = v[0];
    *menor = v[0];

    for (int i = 1; i < tamanho; i++){
        if (v[i] > *maior){
            *maior = v[i]; 
        }
        if (v[i] < *menor){
            *menor = v[i];
        }
    }
}

void achar_maior_menor_2(int *vetor, int *maior, int *menor, int length){
    *maior = vetor[0];
    *menor = vetor[0];

    for (int i = 0; i < length; i++){
        if (vetor[i] > *maior ){
            *maior = vetor[i];
        }
        if (vetor[i] < *menor){
            *menor = vetor[i];
        }
    }
}