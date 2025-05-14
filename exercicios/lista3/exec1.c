/*
Tentando descobrir se um dado era viciado, um dono de cassino honesto o lançou n
vezes. Leia os n resultados dos lançamentos, guarde-os em um vetor e determine o
número de ocorrências de cada face.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nDado 6

void iniciaVetor(int v[]);
void geraVetorAleatorio(int v[], int n);
void escreve_vetor(int v[]);

int main(){
    int n;
    srand(time(0));
    printf("Quantas vezes irá jogar o dado: ");
    scanf("%d", &n);
    int vet[6];

    iniciaVetor(vet);
    geraVetorAleatorio(vet, n);
    escreve_vetor(vet);

    return 0;
}

void iniciaVetor(int v[]){
    for (int i = 0; i < 6; i++){
        v[i] = 0;
    }
}

void geraVetorAleatorio(int v[], int n){
    for(int i = 0; i < n; i++){
        int pos = (rand() % nDado) + 1;
        printf("%d \n", pos);
        v[pos-1]++;
    }
}

void escreve_vetor(int v[]){
    for (int i = 0; i < 6; i++){
        printf("%d,",v[i]);
    }
    printf("\n");
}