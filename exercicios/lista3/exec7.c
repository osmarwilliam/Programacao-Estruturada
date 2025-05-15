/*
Faça uma função para calcular o produto de duas matrizes. A função deve
verificar se as matrizes são de tamanhos compatíveis para multiplicação.
Lembre que c[i, j] = Somatório de a[i,k] * b[k,j] para todo k
*/

#include <stdio.h>

void imprimirMatriz(int c1, int l1, int v[c1][l1]);
void multiplicarMatriz(int l1, int c1, int v1[l1][c1], int l2, int c2, int v2[l2][c2], int v3[l1][c2]);

int main(){

    int matrizA[2][3] = {1,2,3,4, 5,6};
    int matrizB[3][2] = {1,2,3,4,5,6};
    int matrizC[2][2];

    multiplicarMatriz(2,3,matrizA,3,2,matrizB,matrizC);

    imprimirMatriz(2, 2, matrizC);

    return 0;
}

void imprimirMatriz(int c1, int l1, int v[c1][l1]){
    for (int i = 0; i < c1; i++){
        for (int j = 0; j < l1; j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatriz(int l1, int c1, int v1[l1][c1], int l2, int c2, int v2[l2][c2], int v3[l1][c2]){
    if (c1 == l2){
        for (int i = 0; i < l1; i++){
            for (int j = 0; j < c2; j++){
                v3[i][j] = 0;
                for (int k = 0; k < c1; k++){
                    v3[i][j] += v1[i][k] * v2[k][j];
                }
            }
        }   
    }
    // c[i, j] = Somatório de a[i,k] * b[k,j] para todo k
}