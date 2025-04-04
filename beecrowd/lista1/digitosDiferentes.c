/*
Os habitantes de Nlogônia são muito supersticiosos.
Uma de suas crenças é que os números das casas de rua que têm um dígito repetido traz sorte ruim para os moradores. 
Portanto, eles nunca iriam viver em uma casa que tem o número 838 ou 1004, por exemplo.

A rainha de Nlogônia ordenou a construção de uma nova avenida à beira-mar e 
quer atribuir para as novas casas apenas números sem dígitos repetidos, 
para evitar desconforto entre os seus súditos. 
Você foi nomeado por Sua Majestade para escrever um programa que, dado dois inteiros N e M, 
determine a quantidade máxima possível de casas que podem assumir um número entre N e M inclusive, 
sem que ocorram dígitos repetidos nestes números.

Entrada: Cada teste é descrito usando uma linha. A linha contém dois inteiros N e M, 
conforme descrito acima (1 ≤ N ≤ M ≤ 5000).

*/

#include <stdio.h>

int compare(int n);
int tamanho(int a);


int main(){
    int n, m;
    while (scanf("%i %i", &n, &m) == 2){
        int count = 0;
        for (int i = n; i <= m; i++){
            if(compare(i)){
                count++;
            }
        }
        printf("%i\n", count);
    }
    return 0;
}

int compare(int n){
    int vetor[tamanho(n)]; 
    int temp;
    int resto = n;
    for (int i = 0; i < tamanho(n); i++) {
        temp = resto % 10; 
        vetor[i] = temp;
        resto = resto / 10;
    }

    int count = 0;

    for(int i = 0; i < tamanho(n) - 1; i++){   
        for (int j = i + 1; j < tamanho(n); j++){
            if (vetor[i] == vetor[j]){
                count++;
            }
        }
    }
    if (count == 0){
        return 1;
    }
    return 0;
}

int tamanho(int a){
    int tam = 0;
    int num = a;
    while(num > 0){
        num /= 10;
        tam++;
    }
    return tam;
}