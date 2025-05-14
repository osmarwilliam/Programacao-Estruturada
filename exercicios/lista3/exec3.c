/*
Dada uma seqüência de n números reais, determinar os números que compõem a
seqüência e o número de vezes que cada um deles ocorre na mesma.
*/

#include <stdio.h>

void ler_valores(float v[], int tamanho);
void iniciarVetor(int v[], int tamanho);
int verificar_ocorrencia(float v1[], float v2[], int qtd[], int tamanho);
int achar_elemento(float vetor[], float elem, int tamanho);
void imprimir(float vetor[], int qtd[], int last_pos);

int main(){
    int n;
    printf("Qual será o tamanho da sequência: ");
    scanf("%d", &n);
    float v1[n], v2[n];
    int qtd[n];

    iniciarVetor(qtd, n);

    ler_valores(v1, n);    


    int last_pos = verificar_ocorrencia(v1, v2, qtd, n);
  
    imprimir(v2,qtd,last_pos);
    
    return 0;
}

void ler_valores(float v[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("Digite o elemento nª %d: ", i+1);
        scanf("%f", &v[i]);
    }
}

void iniciarVetor(int v[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        v[i] = 0;
    }
}

int verificar_ocorrencia(float v1[], float v2[], int qtd[], int tamanho){
    int last_pos = 0;
    for (int i = 0; i < tamanho; i++){
        int pos = achar_elemento(v2, v1[i], last_pos);
        if (pos == -1){
            v2[last_pos] = v1[i];
            qtd[last_pos] = 1;
            last_pos++;
        }
        else {
            qtd[pos]++;
        }
    }
    return last_pos;
}

int achar_elemento(float vetor[], float elem, int tamanho){
    for (int i = 0; i < tamanho; i++){
        if (vetor[i] == elem)
            return i;
    }
    return -1;
}

void imprimir(float vetor[], int qtd[], int last_pos){
    for (int i = 0; i < last_pos; i++){
        if(qtd[i] == 1){
            printf("O elemento %.2f aparece 1 vez\n", vetor[i]);
        }
        else{
            printf("O elemento %.2f aparece %d vezes\n", vetor[i], qtd[i]);
        }
    }
}