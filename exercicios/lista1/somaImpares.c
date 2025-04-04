/*
Sabe-se que um número da forma n3 é igual a soma de n ímpares consecutivos. 
Por exemplo: 1^3= 1, 2^3= 3+5, 3^3= 7+9+11, 4^3= 13+15+17+19,...
Escreva um programa que, dado um número m, sejam informados os ímpares
consecutivos cuja soma é igual a n3 para n assumindo valores de 1 a m. 
No exemplo acima, m = 4.
*/

#include <stdio.h>

void imprime_impares(int m);

int main(){
    int m = 0;
    printf("Digite o m: ");
    scanf("%d", &m);
    imprime_impares(m);
    printf("\n");
    return 0;
}

void imprime_impares(int m){
    int impar = 1;
    for (int i = 1; i <= m; i++){
      printf("\n %d^3 = ", i);
      for (int j = 0; j < i; j++){
        printf("%d ", impar);
        impar += 2;
      }
    }       
}