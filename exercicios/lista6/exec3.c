/*
Escreva um programa que decide se duas string lidas são palíndromas mútuas, ou seja,
se uma igual a outra, se escrita de trás para frente. Exs. amor e roma

*/
#include <stdio.h>

int verificar_palindromo(char *a, char *b);
int length(char * palavra);

int main(){
    char palavra_1[80], palavra_2[80];
    printf("Digite a primeira palavra: ");
    scanf("%79[^\n]", palavra_1);
    getchar();

    printf("Digite a segunda palavra: ");
    scanf("%79[^\n]", palavra_2);

    if(verificar_palindromo(palavra_1, palavra_2))
        printf("São palíndromas mútuas.\n");
    else 
        printf("Não são palíndromas mútuas.\n");

    return 0;
}

int verificar_palindromo(char *a, char *b){
    int tamanho1 = length(a);
    int tamanho2 = length(a);

    if (tamanho2 == tamanho1){
        for (int i = 0; i < tamanho1; i++){
            if (*a != b[tamanho1 - 1 - i]){
                return 0;
            }
            a++;
        }
        return 1;
    }
    return 0;
}

int length(char * palavra){
    int tamanho = 0;

    for (int i = 0; *palavra != '\0'; i++){
        tamanho++;
        palavra++;
    }
    return tamanho;
}
