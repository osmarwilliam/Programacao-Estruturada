/*
Implemente uma função que retorne uma aproximação do valor de PI, de
acordo com a fórmula de Leibniz abaixo. A função deve receber como entrada
o número que indica a quantidade de termos na série. Após, escreva um
programa completo que leia o número de termos via teclado e chame a função
implementada
*/

#include <stdio.h>

double pi(int termos);

int main(){
    int n;
    printf("Quantos termos da sequencia: ");
    scanf("%d", &n);

    printf("A soma desses termos é %lf", pi(n));
    
    return 0;
}

double pi(int termos){
    float valor= 1, sinal= -1;
    int tmp = 3;

    for (int i = 0; i < termos; i++){
        valor += 1*sinal/tmp;
        sinal *= -1;
        tmp += 2;
        printf("%lf %d \n", valor, tmp);
    }

    return 4 * valor;
}