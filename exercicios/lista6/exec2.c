/*
Faça uma função que dada uma frase, retorna o número de palavras da frase. Considere
que a frase pode ter espaços no início e no final e que entre duas palavras você pode ter
vários espaços.
*/

#include <stdio.h>

int qtd_palavras(char *frase);
int length(char *frase);

int main(){
    char frase[150];
    printf("Digite a frase: ");
    scanf("%149[^\n]", frase);

    printf("A quantidade de palavra é: %d",  qtd_palavras(frase));

    return 0;
}

int qtd_palavras(char *frase){

    int tamanho = length(frase);
    int numero = 0;

    int i = 0;
    while(i < tamanho){
        if (*frase != ' '){
            numero++;
            while(*frase != ' '){
                i++;
                frase++;
            }
        }        
        frase++;
        i++;
    }
    return numero;
}

int length(char *frase){

    int tamanho = 0;
    for(int i = 0; *frase != '\0'; i++){
        tamanho++;
        frase++;
    }

    return tamanho;
}







