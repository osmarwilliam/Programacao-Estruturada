#include <stdio.h>

float calculoIr(int a);

int main() {
    float salario;
    printf("Informe seu salário: ");
    scanf("%f", &salario);
    
    float valor = calculoIr(salario);
    printf("o valor que deve ser descontado do seu imposto de renda é: %.2f", valor);    

    return 0;
}

float calculoIr(int a){
    float valor;
    if (a <= 1499.14) {
        valor = 0;
    } else if (a <= 2245.75) {
        valor = (a * 0.075) - 122.44;
    } else if (a <= 2995.70) {
        valor = (a * 0.15)  - 290.95;
    } else if (a <= 3473.19) {
        valor = (a * 0.225) - 505.62;
    } else {
        valor = (a * 0.275)   - 692.78;
    }
    return valor;
}
