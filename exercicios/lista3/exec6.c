/*
Escreva uma função para multiplicar os elementos da diagonal principal de
uma matriz por um valor k.
*/

#include <stdio.h>

void ler_valores(int dimensao, float m[dimensao][dimensao]);
void multiplicar(int dim, float m[dim][dim],int k );
void imprimirDiagonal(int dim, float m[dim][dim]);

int main(){
    int n, k;
    printf("Digite a dimensão: ");
    scanf("%d", &n);

    float matriz[n][n];
    ler_valores(n, matriz);
    
    printf("Digite o valor que deseja multiplicar a diagonal: ");
    scanf("%d", &k);

    multiplicar(n, matriz, k);

    imprimirDiagonal(n, matriz);

    return 0;
}

void ler_valores(int dimensao, float m[dimensao][dimensao]){
    for (int i = 0; i < dimensao; i++){
        for (int j = 0 ; j < dimensao; j++){
            printf("Digite o número da posição [%d,%d]: ", i, j);
            scanf("%f", &m[i][j]);
        }
    }
}

void multiplicar(int dim, float m[dim][dim],int k ){
    for (int i = 0; i < dim; i++){
            m[i][i] = k * m[i][i];
    }
}

void imprimirDiagonal(int dim, float m[dim][dim]){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            printf("%.2f ", m[i][j]);
        }
        printf("\n");
    }
}
