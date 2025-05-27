/*
Desenvolva um jogo da forca. O programa terá uma lista de palavras lidas de um arquivo
texto (palavras.txt) e escolherá uma palavra aleatoriamente. Seu programa deve ler as palavras
do arquivo e colocá-las em um vetor. Após, ele deve sortear uma posição válida da lista e obter
a palavra. O jogador poderá errar 6 vezes antes de ser enforcado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int leitura(char * file, char palavras[100][100]);

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("digite o arquivo no console\n");
        exit(1);
    }

    char palavra[100][100];

    int npalavras = leitura(argv[1], palavra);

    //forca(npalavras, palavra);

    return 0;
}

int leitura(char * file, char palavras[100][100]){
    
    FILE *fp; 
    fp = fopen(file, "r");

    char palavra[100];

    if (fp == NULL){
        printf("Erro ao ler arquivo\n");
        exit(2);
    }

    int i = 0;

    while(fscanf(fp, " %s", palavra) == 1){
        strcpy(palavras[i], palavra);
        i++;
    }

    srand(time(NULL));
    printf("%i", (rand() % i));

    fclose(fp);

    return i;
}