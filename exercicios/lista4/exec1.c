/*
Crie uma função recursiva que calcula a
potência de um número positivo.
*/

#include <stdio.h>

int potencia(int a, int n);

int main(){

    int a, n;

    printf("Digite o número: ");
    scanf("%d", &a);
    printf("Deseja elevar ele por qual valor: ");
    scanf("%d", &n);
    
    printf("o num %d elevado a %d é: %d", a, n, potencia(a,n));

    return 0;
}


int potencia(int a, int n){
    if (n == 1){
        return a;
    }
    return a * potencia(a, n -1);
}
