/*
Dado qualquer inteiro n (1 <= n <= 10000) não divisível por
2 ou por 5, algum múltiplo de n deve ser um número que é uma
sequência de números 1. Você deve escrever uma função
recursiva que retorna quantos dígitos tem o menor múltiplo de n
que tem todos seus dígitos iguais a 1. Por exemplo, se a entrada
for 3, a saída deve ser 3, pois 111 é o menor múltiplo de 3 que
tem todas as saídas iguais a 1. Se a entrada for 7, a saída deve
ser 6, pois 111111 é o menor múltiplo de 7 que tem todas as
saídas iguais a 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int testa_numero(int a);
int forma_numero(int i);
int testa_uns(int a, int i);

int main(int argc, char * argv[]){
    if (argc != 2){
        printf("Digite o valor de N na entrada:");
        return 1;
    }
    
    int num = atoi(argv[1]);

    printf("%d \n", testa_numero(num));

    return 0;
}

int testa_numero(int a){
    if ((a % 5 == 0) || (a % 2 == 0)){
        return 0;
    }
    
    return testa_uns(a, 1);
}

int testa_uns(int a, int i){
    int teste = forma_numero(i);
    if (teste % a == 0){
        return i;
    }

    return testa_uns(a, i + 1);
}

int forma_numero(int i){
    if (i == 1){
        return 1;
    }
    return pow(10, i - 1) + forma_numero(i - 1);
}

