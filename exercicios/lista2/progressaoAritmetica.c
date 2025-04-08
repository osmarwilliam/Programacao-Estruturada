#include <stdio.h>
int progAritmetica(int inicio, int final, int termos);

int main() {
    int valorInicial, valorFinal, termos;
    
    printf("Digite o valor inicial: ");
    scanf("%i", &valorInicial);

    printf("Digite o valor final: ");
    scanf("%i", &valorFinal);

    printf("Digite número de termos: ");
    scanf("%i", &termos);


    int soma = progAritmetica(valorInicial, valorFinal, termos);
    printf("A soma dos termos dessa seq é: %i", soma);

    return 0;
}

int progAritmetica(int inicio, int final, int termos){
    int soma = 0;
    soma = ((inicio + final) * termos) / 2; 
    return soma;
}

