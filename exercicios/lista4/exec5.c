/*
Crie uma função recursiva que receba um número inteiro positivo N e
calcule o somatório dos números de 1 a N.
*/

#include <stdio.h>
#include <stdlib.h>

int somatorio(int a);

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Digite o número na linha de comando \n");
        return 1;
    }

    int num = atoi(argv[1]);
    
    printf("O somario de 1 até %d é: %d", num, somatorio(num));
    
    return 0;
}

int somatorio(int a){
    if (a == 1){
        return 1;
    }
    return a + (somatorio(a -1));
}
