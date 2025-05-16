/*
Imagine que comm(n,k) representa o número de
diferentes comitês de k pessoas, que podem ser formados,
dadas n pessoas a partir das quais escolher. Por exemplo,
comm(4,3) = 4, porque dadas quatro pessoas, A, B, C e D
existem quatro possíveis comitês de três pessoas: ABC,
ABD, ACD e BCD. O número de comitês pode ser
calculado a partir da seguinte expressão:
comm(n ,k) = comm(n - 1, k) + comm(n - 1, k - 1)
Escreva e teste um programa recursivo em C para calcular
comm(n,k) para n,k >= 1.
*/

#include <stdio.h>

int comn(int n, int k);

int main(){

    int n, k;
    printf("Digite o número de pessoas: ");
    scanf("%d", &n);
    printf("Digite o número de comites: ");
    scanf("%d", &k);

    printf("Dado %d pessoas, o número de comites possiveis com %d pessoas é: %d \n", n, k, comn(n,k));

    return 0;
}


int comn(int n, int k){
    if (k > n){
        return 0;
    }
    if (n == 1 || k == 1){
        return n;
    }
    return comn(n - 1, k) + comn(n - 1, k - 1);
}