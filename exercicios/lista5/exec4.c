/*
Os elementos aij de uma matriz inteira A(nxn)
representam os custos de transporte da
cidade i para a cidade j. Dados n itinerários, cada um com k cidades, calcular o
custo total para cada itinerário. Exemplo:
O custo do itinerário 0 3 1 3 3 2 1 0 é a03 + a31 + a13 + a33 + a32 + a21 + a10 = 3 + 1 +
400 + 5 + 2 + 1 + 5 = 417
*/

#include <stdio.h>
#include <stdlib.h>

int **alocar_matriz(int dimensao);
void liberar_matriz(int **matriz, int dimensao);
void custo_matriz(int **mat, int dimensao);
void calcular_itinerarios(int **matriz, int dimensao, int itinerario);
int itinerarios(int ** matriz, int dimensao, int cidades);

int main(){
    int n;

    printf("Digite o número de cidades: ");
    scanf("%d", &n);

    int **mat = alocar_matriz(n);

    custo_matriz(mat, n);

    int k;
    printf("Quantos itinerários: ");
    scanf("%d", &k);

    calcular_itinerarios(mat, n, k);
    liberar_matriz(mat,n);
    return 0;
}

int itinerarios(int ** matriz, int dimensao, int cidades){
    int cidade, next, custo = 0;
    printf("Primeira cidade: ");
    scanf("%d", &cidade);
    for (int i = 0; i < cidades; i++){
        printf("Proxima cidade: ");
        scanf("%d", &next);
        custo += matriz[cidade][next];
        cidade = next;
    }
    return custo;
}

void calcular_itinerarios(int **matriz, int dimensao, int itinerario){
    for (int i = 0; i < itinerario; i++){
        int cidades;
        printf("Quantas cidades nesse itinerario: ");
        scanf("%d", &cidades);

        int custo = itinerarios(matriz, dimensao, cidades);

        printf("O custo desse itineario é : %d \n", custo);
    }
}

int **alocar_matriz(int dimensao){
    int **matriz = (int**) malloc(dimensao* sizeof(int));

    for (int i = 0; i < dimensao; i++){
        matriz[i] = (int *) malloc(dimensao * sizeof(int));
    }
    return matriz;
}

void liberar_matriz(int **matriz, int dimensao){
    for (int i = 0; i < dimensao; i++){
        free(matriz[i]); 
    }
    free(matriz);
}

void custo_matriz(int **mat, int dimensao){
    for (int i = 0; i < dimensao; i++){
        for (int j = 0; j < dimensao; j++){
            printf("O custo da cidade [%d] para cidade [%d]: ", i, j);
            
            scanf("%d", &mat[i][j]);  
        }
    }
}
