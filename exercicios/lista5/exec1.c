/*
Elabore um programa em C que preencha um vetor com N valores inteiros. Após, o
programa deverá ler um número qualquer X. O programa deverá buscar no vetor as
ocorrências de X, armazenando em um vetor de saída os endereços na memória,
nos quais X aparecem no vetor.
*/

#include <stdio.h>

void ler_vetor(int *v, int tam);
int ocorrencia(int *v, int n, int **vEnderecos, int numero);
void imprimir(int last_pos,int **vetorEnderecos);

int main(){

    int n;
    printf("Digite a quantidade de elementos que terá o vetor: ");
    scanf("%d", &n);

    int vetor[n];

    ler_vetor(vetor, n);

    int numero;
    printf("Digite o número que voce deseja buscar: ");
    scanf("%d", &numero);

    int *vetorEnderecos[n];

    int last_pos = ocorrencia(vetor, n, vetorEnderecos, numero); 

    imprimir(last_pos, vetorEnderecos);

    return 0;
}

void imprimir(int last_pos,int **vetorEnderecos){
    for (int i = 0; i < last_pos; i++){
        printf("%p\n", vetorEnderecos);
        vetorEnderecos++;
    }

}

void ler_vetor(int *v, int tam){
    for (int i = 0; i < tam; i++){
        printf("Digite o valor do vetor na posição %d: ", i+1);
        scanf("%d", v);
        v++;
    }
}

int ocorrencia(int *v, int n, int **vEnderecos, int numero){
    int ultima_posicao = 0;
    
    for (int i = 0; i < n; i++){
        if(*v == numero){
            vEnderecos = &v; 
            ultima_posicao++; 
            vEnderecos++;
        }
        v++;
    }
    return ultima_posicao;
}