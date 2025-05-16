/*
- Escreva uma função recursiva que determine quantas vezes um dígito K
ocorre em um número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em
762021192.
*/

#include <stdio.h>
#include <stdlib.h>

int ocorrencia(int numero, int digito);

int main(int argc, char * argv[]){

    if (argc != 3){
        printf("Passe o número e após isso o dígito na linha de comando! \n");
        return 1;
    }

    int num = atoi(argv[1]);
    int a = atoi(argv[2]);

    printf("o dígito %d aparece %d vezes em: %d", a, ocorrencia(num, a), num);

    return 0;
}

int ocorrencia(int numero, int digito){

    if (numero == 0 ){
        return 0;
    }
    else if ((numero % 10) == digito){
        return 1 + ocorrencia(numero / 10, digito);
    } 
    else
        return ocorrencia(numero / 10, digito);
}
