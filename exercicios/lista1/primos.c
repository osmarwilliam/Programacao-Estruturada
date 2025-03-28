#include <stdio.h>
#include <math.h>

int primo(int a);

int main(){
    int num;
    puts("Digite um numero para verificar se ele e primo: ");
    scanf("%d", &num);

    int valor = primo(num);

    if (valor == 1) {
        printf("O numero: %i e primo", num);
    } else {
        printf("O numero: %i nao primo", num);
    }
}

int primo(int a){
    int count = 0;
    for (int i = 1; i <= sqrt(a); i++) {
        if (a % i == 0){
            count++;
        }
    }   
    if (count == 2){
        return 1;
    }
    return 0;
}