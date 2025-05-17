/*
Escreva uma função que descobre se uma matriz representa um quadrado mágico,
usando ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>

int **alocar_matriz(int dimensao);
void liberar_matriz(int **matriz, int dimensao);
void ler_matriz(int **matriz, int dimensao);
void imprimir_matriz(int **matriz, int dimensao);

int soma_diagonal(int **matriz, int dimensao);
int soma_linhas(int **matriz, int dimensao);
int soma_colunas(int **matriz, int dimensao);

int main(int argc, char * argv[]){
    int m;
    printf("Digite o tamanho da dimensão da matriz: ");
    scanf("%d", &m);

    int **matriz = alocar_matriz(m);

    ler_matriz(matriz, m);

    imprimir_matriz(matriz, m);


    if ((soma_linhas(matriz, m)) && (soma_colunas(matriz, m)) && (soma_diagonal(matriz, m)))
        printf("É quadrado mágico\n");
    else
        printf("Não é quadrado mágico\n");

    liberar_matriz(matriz, m);

    return 0;
}

void imprimir_matriz(int **matriz, int dimensao){
    for (int i = 0; i < dimensao; i++){
        for (int j = 0; j < dimensao; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void ler_matriz(int **matriz, int dimensao){
    for (int i = 0; i < dimensao; i++){
        for (int j = 0; j < dimensao; j++){
            printf("Digite o elemento da posição [%d,%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int **alocar_matriz(int dimensao){
    int **matriz = (int**)(malloc(dimensao * sizeof(int*)));
    for (int i = 0; i < dimensao; i++){
        matriz[i] = (int*)(malloc(dimensao * sizeof(int)));
    }
    return matriz;
}

void liberar_matriz(int **matriz, int dimensao){
    for (int i = 0; i < dimensao; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int soma_linhas(int **matriz, int dimensao){
    int soma_linha_1 = 0;
    for (int i = 0; i < dimensao; i++){
        soma_linha_1 += matriz[0][i]; 
        
    }
    int soma_linha_2 = 0;
    for (int i = 1; i < dimensao; i++){
        
        soma_linha_2 = 0;
        for (int j = 0; j < dimensao; j ++){
            soma_linha_2 += matriz[i][j];
            
        }
        if (soma_linha_2 != soma_linha_1)
            return 0;
    }
    return 1;
}

int soma_colunas(int **matriz, int dimensao){
    int soma_coluna_1 = 0;

    for (int i = 0; i < dimensao; i++){
        soma_coluna_1 += matriz[i][0];
    }
    int soma_coluna_2 = 0;

    for (int i = 1; i < dimensao; i ++){
        soma_coluna_2 = 0;
        for (int j = 0; j < dimensao; j++){
            soma_coluna_2 += matriz[j][i];
        }
        if (soma_coluna_1 != soma_coluna_2)
            return 0;
    }
    return 1;
}

int soma_diagonal(int **matriz, int dimensao){
    int soma_diagonal_1 = 0;

    for (int i = 0; i < dimensao; i++){
        soma_diagonal_1 += matriz[i][i];
    }
    int soma_diagonal_2 = 0;
    int j = dimensao - 1;
    for (int i = 0; i < dimensao; i++){        
        soma_diagonal_2 += matriz[i][j];
        j--;
    }

    if (soma_diagonal_1 != soma_diagonal_2){
        return 0;
    }
    return 1;
}