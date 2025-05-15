/*
Faça um programa para informar a linha de maior soma de uma matriz de
inteiros.
*/

#include <stdio.h>

int maiorLinha(int l1, int c1, int v[l1][c1], int *soma);

int main(){
    
    int vetor[2][2] = {1,2,3,4};
    int soma;
    int linha = maiorLinha(2, 2, vetor, &soma);

    printf("A soma da linha %d é: %d", linha, soma);
    return 0;
}

int maiorLinha(int l1, int c1, int v[l1][c1], int *soma) {
    int soma1;
    int soma2 = 0; 
    int linha = 0;
    for(int i =0; i < l1; i++){
        for(int j = 0; j < c1; j++){
            soma2 += v[i][j]; 
        }
        if (soma2 > soma1){
            soma1 = soma2;
            linha = i;
        }
        soma2 = 0;
    }
    *soma = soma1;
    return linha; 
}
