/*
Um número a é dito permutação de um número b se os dígitos de a
formam uma permutação dos dígitos de b. Exemplo: 5412434 é uma
permutação de 4321445, mas não é uma permutação de 4312455.
Obs.: Considere que o dígito 0 (zero) não aparece nos números.
(b) Usando a função do item anterior, faça um programa que lê dois inteiros
positivos a e b e responde se a é permutação de b.
*/

#include <stdio.h>

int contadigitos(int num, int a);
int ehPermutacao(int num1, int num2);

int main(){
    int num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    if (ehPermutacao(num1,num2))
        printf("São permutações \n");
    else
        printf("Não são permutações \n");

    return 0;
}

int ehPermutacao(int num1, int num2) {
    for (int i = 0; i < 10; i++){
        if (contadigitos(num1, i) != contadigitos(num2, i))
            return 0; 
    }
    return 1;
}

int contadigitos(int num, int a) {
    int digitos = 0;
    while (num > 0) {
        if (num % 10 == a)
            digitos++;
        num = num / 10;
    }
    return digitos;
}
