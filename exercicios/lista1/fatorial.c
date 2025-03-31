#include <stdio.h>

int fatorial(int a);

int main() {
   
    int num;
    printf("Digite o número: ");
    scanf("%i", &num);
    printf("O fatorial do número %i é %i.", num, fatorial(num));
    return 0;
}

int fatorial(int a) {
    if (a == 0){
        return 1;
    }
    else {
        return a * fatorial(a - 1);
    }
}
