/*
Faça um programa que recebe o nome de um arquivo e conta o total de letras, vogais,
consoantes, espaços em branco, palavras e o total de linhas encontradas no arquivo.
Considere que uma palavra é separada de outra por um espaço em branco ou um fim de linha.
*/

#include <stdio.h>
#include <stdlib.h>

int verificar(char *file);

int main(int argc, char *argv[]){

    if (argc != 2){
        printf("Passe o arquivo na linha de comando. \n");
        exit(1);
    }

    verificar(argv[1]);


    return 0;
}  

int verificar(char *file){
    int consoantes = 0, vogais = 0, letras = 0, palavras = 0, espaco = 0, linhas = 0;
    char texto[200];
    
    FILE *fp = fopen(file, "r");

    if (fp == NULL){
        printf("Impossível abrir o arquivo: %s\n", file);
        exit(2);
    }

    while (fscanf(fp, " %199[^\n]", texto) == 1){
        printf("%s\n", texto);

        linhas += 1;
        if (texto[0] != '\0'){
            palavras ++;
        }
        for (int i = 0; texto[i] != '\0'; i++){
            if (texto[i] == ' '){
                espaco++;
                palavras ++;
            }
            
            if ((texto[i] > 64 && texto[i] < 91) || (texto[i] > 96 && texto[i] < 123)){
                letras++;
            }

                if(texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u'){
                    vogais++;
                }
                else if (texto[i] == 'A' || texto[i] == 'E' || texto[i] == 'I' || texto[i] == 'O' || texto[i] == 'U'){
                    vogais++;
                }
                else {
                    consoantes++;
                }
            
        }

    }

    printf("O total de consoantes é: %d\n", consoantes);
    printf("O total de vogais é: %d\n", vogais);
    printf("O total de letras é: %d\n", letras);
    printf("O total de palavras é: %d\n", palavras);
    printf("O total de espaços em branco é: %d\n", espaco);
    printf("O total de espaços em linhas é: %d\n", linhas);

    fclose(fp);

    return 1;
}
