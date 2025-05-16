/*
Defina o máximo divisor comum (MDC) de
dois inteiros, x e y, por:
mdc(x, y) = y se (y <= x && x % y == 0)
mdc(x, y) = mdc(y, x) se(x < y)
mdc(x, y) = mdc(y, x % y) caso contrário

Escreva uma função recursiva em C para calcular mdc(x,y).
*/

#include <stdio.h>

int mdc(int x, int y);

int main(){
    int x, y;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);

    printf("O mdc de %d e %d é : %d", x, y, mdc(x,y));

}

int mdc(int x, int y){
    // printf("%d\n", x%y);

    if ((y <= x) && (x % y == 0)){
        return y;
    }
    else if (x < y){
        return mdc(y,x);
    }
    else
        return mdc(y, x % y);

}
