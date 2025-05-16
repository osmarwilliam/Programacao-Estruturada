/*
O superfatorial de um número N é definida pelo produto dos N primeiros
fatoriais de N. Assim, o superfatorial de 4 é sf(4) = 1! * 2! * 3! * 4! = 288
Faça uma função recursiva que receba um número inteiro positivo N e retorne
o superfatorial desse número.
*/

#include <stdio.h>
#include <stdlib.h>

int superfatorial(int a);
int fatorial(int a);


int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Digite o superfatorial do número na linha de comando!\n");
        return 1;
    }
    int num = atoi(argv[1]);


    printf("O super fatorial do número %d é: %d", num, superfatorial(num));

    return 0;
}

int superfatorial(int a){
    if (a == 1){
        return 1;
    }

    return a * fatorial(a - 1) * superfatorial(a - 1);
}

int fatorial(int a){
    if (a == 1){
        return 1;
    }

    return a * fatorial(a - 1);
}