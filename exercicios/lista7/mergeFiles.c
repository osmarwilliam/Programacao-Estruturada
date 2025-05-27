/*
há dois arquivos, e em cada um deles há números em forma ordenada,
do menor número para o maior, crie um programa que crie um terceiro 
arquivo que tenha ambos os conteúdos do arquivo 1 e arquivo 2 e que ordene os números 
dos dois arquivos nesse novo arquivos, faça isso usando C
*/

#include <stdio.h>
#include <stdlib.h>

void mergeFiles(const char * file1, const char *file2, const char *out);

int main(int argc, char* argv[]){

    if (argc != 4){
        printf("Passe os arquivos pela linha de comando, sendo o último arquivo o de saida. ");
        return 1;
    }

    mergeFiles(argv[1], argv[2], argv[3]);


    return 0;
}

void mergeFiles(const char * file1, const char *file2, const char *output){

    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    FILE *out = fopen(output, "w");

    if (f1 == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", file1);
        exit(EXIT_FAILURE);
    }    
    if (f2 == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", file2);
        exit(EXIT_FAILURE);
    }    
    if (out == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", output);
        exit(EXIT_FAILURE);
    }    


    int num1, num2;


    int read1 = fscanf(f1, "%d", &num1);
    int read2 = fscanf(f2, "%d", &num2);

    while (read1 == 1 && read2 == 1){
        if (num1 < num2){
            fprintf(out, "%d\n", num1);
            read1 = fscanf(f1, "%d", &num1);
        }
        else {
            fprintf(out, "%d\n", num2);
            read2 = fscanf(f2, "%d", &num2);
        }

    } 
    while (read1 == 1){
        fprintf(out, "%d\n", num1);
        read1 = fscanf(f1, "%d", &num1);
        
    }
    while (read2 == 1){
        fprintf(out, "%d\n", num2);
        read2 = fscanf(f2, "%d", &num2);
    }

    fclose(f1);
    fclose(f2);
    fclose(out);

}


