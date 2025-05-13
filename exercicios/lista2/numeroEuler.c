/*
Escreva uma função que recebe por parâmetro um valor inteiro e positivo n
e retorna o valor de S, calculado pela fórmula
S = 1 + 1/1! + 1/2! + 1/3! + 1/N!
*/

#include <stdio.h>

long double somaEuler(int a);
int fatorial(int num);

int main(){
    int n;
    printf("Quantos temos: ");
    scanf("%d", &n);

    printf("A soma dos termos da aproximação do número de euler é: %Lf", somaEuler(n));

    return 0;
}

long double somaEuler(int a){
    long double soma = 0;

    for (int i = 0; i < a; i++){
        soma += 1.0/fatorial(i);
    }
    return soma;
}

int fatorial(int num){
    if (num == 0){
        return 1;
    }
    else {
        return num * fatorial(num - 1);
    }
}