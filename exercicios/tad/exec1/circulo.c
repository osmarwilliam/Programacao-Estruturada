#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "circulo.h"

typedef struct ponto{
    float x;
    float y;
}Ponto;

typedef struct circulo{
    Ponto centro;
    float raio;
}Circulo;

// Cria o circulo
Circulo *cria_circulo(float x, float y, float raio){
    Circulo *p = (Circulo*)malloc(sizeof(Circulo));
    if(p == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }

    p->centro.x = x;
    p->centro.y = y;
    p->raio = raio;

    return p;
}

void circulo_liberar(Circulo *p){
    free(p);
}

float calcular_area(Circulo *p){
    return M_PI * (p->raio) *  (p->raio);
}

int distancia(float p,float q){
    float dist;
    dist = sqrt((q - p)*(q - p) + (q - p)*(q - p));
    return dist;
}

int verificar_pontos(float p, float q, Circulo *raio){
    
    float dist = distancia(p, q);

    return (dist < raio->raio);
}
