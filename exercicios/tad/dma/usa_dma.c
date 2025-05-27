#include <stdio.h>
#include "dma.h"

int main(){

    int dia1, mes1, ano1;

    printf("Digite o dia da primeira data: ");
    scanf("%d", &dia1);
    printf("Digite o mes da primeira data: ");
    scanf("%d", &mes1);
    printf("Digite o ano da primeira data: ");
    scanf("%d", &ano1);

    int dia2, mes2, ano2;

    printf("Digite o dia da segunda data: ");
    scanf("%d", &dia2);
    printf("Digite o mes da segunda data: ");
    scanf("%d", &mes2);
    printf("Digite o ano da segunda data: ");
    scanf("%d", &ano2);

    Dma *data1 = cria_dma(dia1, mes1, ano1);
    Dma *data2 = cria_dma(dia2, mes2, ano2);

    int dias = 0;

    dias = calcular_dias(data1, data2);

    printf("A diferença de dias entre as duas datas é: %d\n", dias);

    libera_dma(data1);
    libera_dma(data2);

    return 0;
}