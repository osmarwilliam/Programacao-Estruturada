/*
Um anagrama é uma palavra que é feita a partir da transposição das letras de outra
palavra ou frase. Por exemplo, “Iracema” é um anagrama para “America”. Escreva um
programa que decida se uma string é um anagrama de outra string, ignorando espaços e
pontuações
*/

#include <stdio.h>

int anagrama(char *a, char *b);
// void transformar_maisculo(char * palavra);
int compare(char a, char *b);

int main(){
    char palavra1[80];
    char palavra2[80];

    printf("Digite a primeira palavra: ");
    scanf("%79[^\n]", palavra1);
    getchar();

    printf("Digite a segunda palavra: ");
    scanf("%79[^\n]", palavra2);

    if (anagrama(palavra1, palavra2)){
        printf("São anagramas.\n");
    }
    else 
        printf("Não são anagramas.\n");

    return 0;
}

void transformar_minusculo(char *palavra){
    for (int i = 0; *palavra != '\0'; i++){
        if (*palavra >= 'A' && *palavra <= 'Z'){
            *palavra = (*palavra - 'A') + 'a';
        }
        palavra++;
    }
    
}

void transformar_maisculo(char * palavra){
    for (int i = 0; *palavra != '\n';){
        if (*palavra >= 'a' && *palavra <= 'z'){
            *palavra = (*palavra - 'a') + 'A';
        }
    }
}


int anagrama(char *a, char *b){
    transformar_minusculo(a);
    transformar_minusculo(b);

    for (int i = 0; *a != '\0'; i++){
        if(!compare(*a, b)){
            return 0;
        }
        a++;
        b++;
    }

    if (*b == '\0'){
        return 1;
    }
    
    return 0;
}

int compare(char a, char *b){
    for (int i = 0; *b != '\0'; i++){
        if (a == *b){
            *b = '|';
            return 1;
        }
        b++;
    }

    return 0;
}