/*
Escreva um programa em C que receba um array de inteiros e gere uma
representação compacta usando o método RLE (Run Length Encoding). Para cada
ocorrência de um número inteiro o método RLE armazena o valor correspondente
juntamente com o número de ocorrências consecutivas. Exemplo:
1 2 3 5 5 5 7 7 7 7 7 2 2 2 0 0 0 0 0 9 9 9 12 12 12 4 4
1 1 2 1 3 1 5 3 7 5 2 3 0 5 9 3 12 3 4 2
*/

#include <stdio.h>

int last_pos(int vetor[], int vetor2[], int tamanho);
void imprimir(int vetor[], int pos);
void ler_vetor(int n, int vetor[]);

int main(){

    int n;
    printf("Quantos números terá a sequencia: ");
    scanf("%d", &n);
    
    int vetor[n];
    
    ler_vetor(n, vetor);
    
    int tamanho = sizeof(vetor)/ sizeof(int);
    
    int vetor2[tamanho*2];

    int position = last_pos(vetor, vetor2, tamanho);

    imprimir(vetor2, position);

}

void ler_vetor(int n, int vetor[]){
    for(int i = 0; i < n; i++){
        printf("Digite o elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }
}


int last_pos(int vetor[],int vetor2[], int tamanho){
    int i = 0, j = 0;
    int last_pos = 0;
    while (i < tamanho){
        int cont = 1;
        while (i < tamanho - 1 && vetor[i] == vetor[i+1]) {
            cont++;
            i++;
        }
        vetor2[j] = vetor[i];
        vetor2[j+1] = cont;
        j+= 2;
        i++;
    }
    return j;
}

void imprimir(int vetor[], int pos){
    for (int i = 0; i < pos; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
