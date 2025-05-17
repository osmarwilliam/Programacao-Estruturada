/*
Faça um programa para calcular a área e o perímetro de um hexágono. O programa deve
implementar uma função chamada calc_hexa que calcula a área e o perímetro de um hexágono
regular de lado L. O programa deve solicitar ao usuário o lado do polígono, calcular e imprimir a área
e o perímetro do polígono. O programa termina quando for digitado um valor negativo qualquer para o
lado. A função deve obedecer o seguinte protótipo:
void calc_hexa(float l, float *area, float *perimetro);
*/

#include <stdio.h>
#include <math.h>

void calc_hexa(float l, float *area, float *perimetro);


int main(){

    float lado = 0;
    printf("Digite o valor do lado: ");
    scanf("%f", &lado);
    float area = 0, perimetro = 0;

    while(lado >= 0){

        calc_hexa( lado, &area, & perimetro);

        printf("O valor da área é: %.2f \n", area);
        printf("O valor do perimetro é: %.2f \n", perimetro);
        printf("Digite o valor do lado: ");
        scanf("%f", &lado);
    }

    return 0;
}

void calc_hexa(float l, float *area, float *perimetro){
    *area = (3 * l * l *sqrt(3) / 2);
    *perimetro = 6* l;
}