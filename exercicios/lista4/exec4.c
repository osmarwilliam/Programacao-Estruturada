/*
Os números de Catalan são definidos pela seguinte
recursão

Alguns números desta sequência são: 1, 1, 2, 5, 14, 42,
132, 429, 1430, 4862, 16796, 58786...
Faça uma função recursiva que receba um número N e
retorne o N-ésimo número de Catalan
*/

#include <stdio.h>
#include <stdlib.h>

float catalan(float a);

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Passe o numero na linha de comando. \n");
        return 1;
    }

    float num = atof(argv[1]);

    printf("o número da seq de catalan na posição %.2f é: %.2f",  num, catalan(num));

    return 0;
}

float catalan(float a){
    if (a == 0){
        return 1;
    }

    return (2 * (2*a - 1)/(a+1)) * catalan(a - 1);
}