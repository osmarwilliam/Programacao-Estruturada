/*
Faça um programa que leia a ordem de uma matriz quadrada (até 100),
posteriormente leia os seus valores e finalmente calcule a sua transposta, onde at[i, j] =
a[j, i]
*/

#include <stdio.h>

void let_matriz(int n, int vet[n][n]);
void inicializaTransposta(int n, int transposta[n][n]);
void imprimeMatrizez(int n, int vet[n][n], int transposta[n][n]);
void calculoTransposta(int n, int vet[n][n], int transposta[n][n]);

int main(){
    int n;
    scanf("%d", &n);

    int matriz[n][n];
    int matrizTransposta[n][n];
    let_matriz(n, matriz);
    inicializaTransposta(n, matrizTransposta);
    calculoTransposta(n, matriz, matrizTransposta);
    imprimeMatrizez(n, matriz, matrizTransposta);

    return 0;
}

void calculoTransposta(int n, int vet[n][n], int transposta[n][n]){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            transposta[j][i] = vet[i][j];
        }

    }
}

void let_matriz(int n, int vet[n][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Digite o elemento [%d,%d]: ", i, j);
            scanf("%d", &vet[i][j]);
        }
    }
}

void inicializaTransposta(int n, int transposta[n][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            transposta[i][j] = 0;
        }
    }
}

void imprimeMatrizez(int n, int vet[n][n], int transposta[n][n]){
    printf("Matriz: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", vet[i][j]);
        }
        printf("\n");
    }

    printf("Matriz Transposta: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

}
