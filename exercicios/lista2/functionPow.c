/*
Escreva uma função que recebe dois valores x e z e calcula e retorna xz
(sem utilizar funções ou operadores de potência prontos).
*/

#include <stdio.h>

int powTest(int a, int b);

int main(){

    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("A potencia de %d por %d é: %d \n",num1,num2, powTest(num1,num2));

    return 0;
}

int powTest(int a, int b){
    if (b == 0){
        return 1;
    }
    int temp = a;
    for (int i = 1; i < b; i++){
        a *= temp;
    }
    return a;
}