#include <stdio.h>
#include <math.h>

int somaNumPrimos(int num);
int verificarPrimo(int a);

int main(){
    int num;
    printf("Quantos números serão testados? ");
    scanf("%i", &num);
    
    printf("A soma dos números primos é: %i", somaNumPrimos(num));
    return 0;
}

int somaNumPrimos(int num){
    int countPrimos = 0;
    for (int i = 1; i <= num; i++){
        int numero;
        printf("Digite o %iª número: ", i);
        scanf("%i", &numero);
        if (verificarPrimo(numero)){
            countPrimos += numero;
        }
    }   
    return countPrimos;
}

int verificarPrimo(int a) {
    int count = 0;
    for (int i = 1; i <= sqrt(a); i++){
        if (a % i == 0){
            count++;
        }
    }
    if (count == 1) {
        return 1;
    }
    return 0;
}
