/*
Faça uma função que recebe um vetor de reais e retorna o valor mais
próximo da média.
Exemplo: supondo vetor = {2.5, 7.5, 10.0, 4.0}
(média = 6.0 (não deve ser impresso))
- Valor mais próximo da média = 7.5
*/

#include <stdio.h>

void ler_valores(float v[], int tamanho);
float calcular_media(float v[], int qtd);
float calculo_prox(float v[], float m, int len);

int main(){
    int n;
    printf("Qual será o tamanho da sequência: ");
    scanf("%d", &n);
    float v1[n];

    ler_valores(v1, n);    
    float media = calcular_media(v1, n);
    
    printf("O número mais proximo de %.2f é : %.2f", media, calculo_prox(v1, media, n));

    return 0;
}

void ler_valores(float v[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("Digite o elemento nª %d: ", i+1);
        scanf("%f", &v[i]);
    }
}

float calcular_media(float v[], int qtd){
    float media = 0;
    for (int i = 0; i < qtd; i++){
        media += v[i];
    }
    return media / qtd * 1.0;
}

float calculo_prox(float v[], float m, int len){
    float prox = v[0];
    float valor = v[0] - m;
    if (valor < 0)
        valor *= -1;
    
    float valorCmp = 0;
    
    for(int i = 1; i < len; i++){        
        if (valor < 0){
            valor *= -1;
        }
        valorCmp = v[i] - m;
        if (valorCmp < 0){
            valorCmp *= -1;
        }
        if (valorCmp < valor){
            valor = valorCmp;
            prox = v[i];
        }        
    }
    return prox;
}