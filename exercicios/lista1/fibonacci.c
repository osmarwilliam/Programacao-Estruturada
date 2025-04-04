/* Escreva um programa em C que imprima os N primeiros termos da série de
Fibonacci, lembrando que esta série é definida da seguinte forma:

Termo 1 = 1
Termo 2 = 1
Termo (x +1) = termo (x) + termo (x − 1)
*/

#include <stdio.h>

int fibonacci(int n);

int main(){
    int n;
    printf("Digite a quantidade de números da sequência: ");
    scanf("%i", &n);

    fibonacci(n);

    return 0;
}

int fibonacci(int n){
    if (n == 1){
        printf("Termo 1 = 1 \n");
        return 1;
    }
    if (n == 2){
        printf("Termo 1 = 1 \n");
        printf("Termo 2 = 1 \n");
        return 2;
    }

    printf("Termo 1 = 1 \n");
    printf("Termo 2 = 1 \n");
    int num1 = 1;
    int num2 = 1;
    int num3 = num1 + num2;
    for (int i = 2; i < n; i++){
        printf("Termo %i = %i \n", i + 1, num3);
        
        num1 = num2;
        num2 = num3;
        num3 = num3+ num1; 
    }
}