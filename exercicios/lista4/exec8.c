/*
A função fatorial duplo é definida como o produto de todos os números
naturais ímpares de 1 até algum número natural ímpar N.
Assim, o fatorial duplo de 5 é 5!! = 1 * 3 * 5 = 15
Faça uma função recursiva que receba um número inteiro positivo ímpar N e
retorne o fatorial duplo desse número.
*/

#include <stdio.h>
#include <stdlib.h>

int fatorialDuplo(int a);

int main(int argc, char * argv[]){
    if (argc != 2){
        printf("Passe o número na linha de comando.\n");
        return 1;
    }

    int num = atoi(argv[1]);
    printf("o fatorial duplo de %d é :%d", num, fatorialDuplo(num));

    return 0;
}

int fatorialDuplo(int a){
    if (a == 1){
        return 1;
    }
    else if (a % 2 == 0){
        return fatorialDuplo(a - 1);
    }
    else 
        return a * fatorialDuplo(a - 1);
}