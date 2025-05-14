/*
Faça uma função que recebe dois vetores e intercala os elementos de
ambos formando um terceiro vetor. O terceiro vetor deve começar do primeiro
elemento do menor vetor. O maior vetor deverá ter seus elementos restantes
repetidos no fim do vetor de resposta.
Exemplo:
intercalar_vetor([1,2,3,4], [10,20,30,40,50,15])
[1,10,2,20,3,30,4,40,50,15]
*/

#include <stdio.h>

void ler_valores(float vet[], int tam);
void imprimir(float vet[], int tam);
void intercalar(float vet1[], int tam1,float vet2[], int tam2, float vet3[]);

int main(){

    int n1, n2;
    printf("Digite o valor do primeiro e do segundo vetor: ");
    scanf("%d %d", &n1, &n2);

    float v1[n1],v2[n2];

    ler_valores(v1, n1); 
    ler_valores(v2, n2); 

    int n3 = n1 + n2;
    float v3[n3];

    intercalar(v1,n1,v2,n2,v3);

    imprimir(v3,n3);

    return 0;
}

void ler_valores(float vet[], int tam){
    for (int i = 0; i < tam; i++){
        printf("Digite o nª %d: ", i+1);
        scanf("%f", &vet[i]);
    }
}

void imprimir(float vet[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%.2f ", vet[i]);
    }
    printf("\n");
}

void intercalar(float vet1[], int tam1,float vet2[], int tam2, float vet3[]){
    
    int menor = tam1, maior = tam2;

    if (tam1 > tam2){
        maior = tam1;
        menor = tam2;
    }

    int j = 0, i = 0;

    for (i = 0; i < menor; i++){
        vet3[j] = vet1[i];
        vet3[j+1] = vet2[i];
        j += 2;
    }

    if (tam1 == menor){
        while (i < maior) {
            vet3[j] = vet2[i];
            j++;
            i++;
        }
    }
    else {
        while (i < maior) {
            vet3[j] = vet1[i];
            j++;
            i++;
        }
    }
}