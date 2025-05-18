/*
Escreva um programa que verifica se uma palavra é palíndroma (considere que a palavra
é um vetor de char)
o Modifique sua solução para considerar se uma frase palíndroma
*/

#include <stdio.h>

int tamanho(char *palavra);
int verificar_palindromo(char *palavra, int length);


int main(){

    char palavra[81];

    scanf("%80[^\n]", palavra);


    int length = tamanho(palavra);

    if(verificar_palindromo(palavra, length))
        printf("É palíndroma");
    else
        printf("Não é palíndroma");


    return 0;
}

int verificar_palindromo(char *palavra, int length){
    for (int i = 0; i < length; i++){
        printf("%c        %c\n", palavra[i], palavra[length - i - 1]);


        if (palavra[i] != palavra[length - i - 1]){
            return 0;
        }
    }
    
    return 1;
}   

int tamanho(char *palavra){
    int length = 0;
    while (*palavra != '\0'){
        length++;
        palavra++;
    }
    return length;
}


