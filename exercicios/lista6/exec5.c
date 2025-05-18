/*
Escreva uma função que recebe uma string e um caracter e retorne apenas o trecho da
string situado entre a primeira e a última ocorrência daquele caracter, excluindo os
extremos. Por exemplo, se a entrada for "abcabc" e "a", a saída deve ser "bc". Se a
entrada for "abcabcabc", a saída será "bcabc".

*/

#include <stdio.h>
#include <stdlib.h>

void criar_string(char *palavra, char letra);
int tamanho(char * a);

int main(){

    char *palavra = (char *)malloc(100 * sizeof(char));

    if (palavra == NULL){
        printf("Erro de alocação\n");
        exit(1);
    }

    char letra;

    printf("Escreva a palavra: ");
    scanf("%99[^\n]", palavra);
    getchar();
    printf("Escreva a letra: ");
    scanf("%c", &letra);
    
    criar_string(palavra, letra);
    
    free(palavra);

    return 0;
}

int tamanho(char * a){
    int len = 0; 
    while (*a != '\0'){
        len++;
        a++;
    }
    return len;
}

void criar_string(char *palavra, char letra){
    
    int tam = tamanho(palavra);
    int primeira_pos;
    int ultima_pos;
    for (int i = 0; palavra[i] != '\0'; i++){
        if (palavra[i] == letra){
            primeira_pos = i;
            break;
        }
    }
    
    for (int i = 0; ; i++){
        if (palavra[tam - i - 1] == letra){
            ultima_pos = tam - i - 1;
            break;
        }
    }

    for (int i = primeira_pos + 1; i < ultima_pos; i++){
        printf("%c", palavra[i]);
    }
    printf("\n");
}
