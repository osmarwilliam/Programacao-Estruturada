/*
Faça uma função MAX que recebe como entrada um inteiro n, uma matriz inteira nxn e devolve
três inteiros: k, l e c. k é o maior elemento de A e é igual a A[l][c]. Se o elemento máximo ocorrer mais
de uma vez, indique em l e c qualquer uma das possíveis posições. Use ponteiros para os
argumentos.
*/

#include <stdio.h>
#include <stdlib.h>

int **alocar_matriz(int linha, int coluna);
void liberar_matriz(int **matriz, int linha);
void max(int **matriz, int linha, int coluna, int *maior, int *l1, int *c1);
void ler_matriz(int **matriz, int linha, int coluna);

int main(){
    int l, c; 
    printf("Digite o valor da linha e da coluna: ");
    scanf("%d %d", &l, &c);
    int **A = alocar_matriz(l,c);
    int maior, l1, c1;

    ler_matriz(A, l, c);
    max(A, l, c, &maior, &l1, &c1);
    liberar_matriz(A, l);
    
    printf(" O maior é %d e está na linha %d e na coluna %d\n", maior, l1, c1);
    
    return 0;
}

void ler_matriz(int **matriz, int linha, int coluna){
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("Digite o elemento da posição [%d,%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
} 

void max(int **matriz, int linha, int coluna, int *maior, int *l1, int *c1){
    *l1 = 0;
    *c1 = 0;
    *maior = 0;

    for(int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if (matriz[i][j] > * maior){
                *maior = matriz[i][j];
                *l1 = i;
                *c1 = j;
            }
        }
    }
}

void liberar_matriz(int **matriz, int linha){
    for (int i = 0; i < linha; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int **alocar_matriz(int linha, int coluna){
    int **matriz = (int**) malloc(linha * sizeof(int));
    for (int i = 0; i < linha; i++){
        matriz[i] = (int*) malloc(coluna * sizeof(int));
    }
    return matriz;
}
