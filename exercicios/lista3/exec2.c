/*
Dados dois vetores x e y, ambos com n elementos, determinar a soma dos produtos dos
elementos desses vetores.
*/

void ler_valores(int vet[], int tamanho);
int somaProduto(int v1[],int v2[], int tamanho);

#include <stdio.h>

int main(){
    int n;
    printf("Digite o tamanho de cada vetor: ");
    scanf("%d", &n);
    int v1[n], v2[n];

    ler_valores(v1,n);
    ler_valores(v2,n);
    printf("A soma do produto do elementos dos vetores é: %d", somaProduto(v1,v2, n));

    return 0;
}

void ler_valores(int vet[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("Digite o elemento nº %d:", i +1);
        scanf("%d", &vet[i]);
    }
    printf("\n");
}

int somaProduto(int v1[],int v2[], int tamanho){
    int soma = 0;
    for (int i = 0; i < tamanho; i++){
        soma += v1[i] * v2[i];
    }
    return soma;
}
