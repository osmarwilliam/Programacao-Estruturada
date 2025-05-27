#include <stdio.h>
#include "circulo.h"


int main(){

    Circulo *p = cria_circulo(2.0, 3.0, 2);

    printf("A area do circulo é %f \n", calcular_area(p));

    float a = 2;
    float b = 2;
    scanf("%f", &a);
    scanf("%f", &b);

    if(verificar_pontos(a,b, p)){
        printf("Está no circulo\n");
    } else {
        printf("Não está no circulo\n");
    }

    
    circulo_liberar(p);

    return 0;
}