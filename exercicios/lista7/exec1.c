/*
Implemente um programa que gere uma versão criptografada de um arquivo texto trocando
cada caractere de código ASCII j pelo caractere de código ASCII j + k, onde k é um parâmetro
especificado pelo usuário. Fique atento para não gerar códigos ASCII fora da faixa permitida.
Em seguida, implemente outro programa que desfaça a criptografia. Evidente que se um
arquivo texto for criptografado pelo primeiro programa e descriptografado pelo segundo, o
resultado deverá ser idêntico à entrada original.
*/

#include <stdlib.h>
#include <stdio.h>


void criptografia(char *file1, char *file2, int k);
void descriptografado(char *file1, char *file2, int k);
void imprimir(char * file);

int main(int argc, char * argv[]){
    if (argc != 3){
        printf("Passe o arquivo pelo comando.\n");
        exit(1);
    }

    int num
    printf("Digite o número para criptografia: ");
    scanf("%d", &num);


    criptografia(argv[1], argv[2], num);
    imprimir(argv[2]);
    descriptografado(argv[1], argv[2], num);
    imprimir(argv[1]);

    return 0;
}

void imprimir(char * file){

    FILE *fp = fopen(file, "r");

    if (fp == NULL){
        printf("Erro ao abrir o arquivo: %s\n", file);
        exit(6);
    }

    char linha[100];

    while(fgets(linha, sizeof(linha), fp)){
        printf("%s", linha);
    }

    
    fclose(fp);
    printf("\n");
}

void descriptografado(char *file1, char *file2, int k){
    FILE *fp1 = fopen(file1, "w");

    if(fp1 == NULL){
        printf("Erro ao abrir arquivo: %s\n", file1);
        exit(4);
    }

    FILE *fp2 = fopen(file2, "r");

    if(fp2 == NULL){
        printf("Erro ao abrir arquivo: %s\n", file2);
        exit(5);
    }

    char lido;
    char escrito;

    int read = fscanf(fp2, "%c", &lido);
    while (read == 1    ){
        if (lido >= 'a' && lido <= 'z'){
            escrito = lido - k;

            if(escrito < 'a'){
                escrito = escrito + 'z' - 'a';
            }
        }
        else{
            escrito = lido;
        }
        fprintf(fp1, "%c", escrito);
        read = fscanf(fp2, "%c", &lido);
    }

    fclose(fp1);
    fclose(fp2);

}

void criptografia(char *file1, char * file2, int k){

    FILE *fp1 = fopen(file1, "r");
    if (fp1 == NULL){
        printf("Erro na abertuda do arquivo %s\n", file1);
        exit(2);
    }

    FILE *fp2 = fopen(file2, "w");

    if (fp2 == NULL){
        printf("Erro na abertuda do arquivo %s\n", file2);
        exit(3);
    }

    char lido;
    char escrito;

    // daria para melhorar colocando uma função que analisa se o número é uppercase ou lowercase

    int read1 = fscanf( fp1,"%c", &lido);
    while (read1 == 1) {
        if (lido >= 'a' && lido <= 'z'){
            escrito = lido + k;

            if (escrito > 'z'){
                escrito = escrito - 'z' + 'a';
            }
        
        } 
        else {
            escrito = lido;
        }  
        fprintf(fp2, "%c", escrito);
        read1 = fscanf(fp1, "%c", &lido);

    }

    fclose(fp1);
    fclose(fp2);
}
