#include <stdio.h>
#include <stdlib.h>

#include "dma.h"


typedef struct dma {
    int dia;
    int mes;
    int ano;
} Dma;

Dma *cria_dma(int dia, int mes, int ano){
    Dma *data = (Dma*)malloc(sizeof(Dma));

    if (data == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}


void libera_dma(Dma *p){
    free(p);
}


// retorna 1 se a data mais antiga for a primeira, e 0 se for a segunda, e -1 se forem iguais
int calcular_data_mais_antiga(Dma *a, Dma *b){
    
    // Verifica se A é um ano mais antigo
    if (a->ano < b->ano){
        return 1;
    }
    // Verifica se B é um ano mais antigo
    if (a->ano > b->ano){
        return 0;
    }

    // se chegou aqui é por que os anos são iguais
    if (a->mes < b->mes){
        return 1; // a é o mes mais antigo
    }
    if (a->mes > b->mes){
        return 0; // b é o mes mais antigo
    }

    // se chegou aqui é por que os meses são os mesmos
    if (a->dia < b->dia){
        return 1; // a é o dia mais antigo
    }
    if (a->dia > b->dia){
        return 0; // b é o dia mais antigo
    }
    
    // a data é igual
    return -1;
}

void trocar_datas(Dma *a, Dma *b){
    Dma *c = (Dma*)malloc(sizeof(Dma));
    c->dia = a->dia;
    c->mes = a->mes;
    c->ano = a->ano;

    a->dia = b->dia;
    a->mes = b->mes;
    a->ano = b->ano;

    b->dia = c->dia;
    b->mes = c->mes;
    b->ano = c->ano;

    libera_dma(c);
}

int eh_bissexto(int ano){
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        return 1;
    }

    return 0;
}

// verifica em qual mes está e retorna quantos dias tem aquele mes
int dias_no_mes(int mes, int ano){
    if (mes == 2){
        return eh_bissexto(ano) ? 29 : 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }
    else {
        return 31;
    }
}

// calcula os dias restantes no ano da data mais antiga
int calcular_dias_restantes_data_antiga(Dma *a){
    int dias_restantes_mes_atual = 0;
    int dia_restantes_meses_seguintes = 0;
    int dias_restantes_total = 0;
    
    dias_restantes_mes_atual = dias_no_mes(a->mes, a->ano) - a->dia;

    for (int i = a->mes + 1; i <= 12; i++){
        dia_restantes_meses_seguintes += dias_no_mes(i,  a->ano); 
    }

    dias_restantes_total = dias_restantes_mes_atual + dia_restantes_meses_seguintes;

    return dias_restantes_total;
}

// calcula os dias nos anos inteiros entre as duas datas 
int calcular_dias_entre_as_duas_datas(Dma *data1, Dma *data2){

    int dias_restante = 0;

    for (int i = data1->ano + 1; i < data2->ano; i++){
        for (int j = 1; j < 13; j++){
            dias_restante += dias_no_mes( j, i);
        }
    }
    return dias_restante;
}

// calcula os dias restante na data mais atual
int calcular_dias_restantes_data_atual(Dma *data){
    int dias_meses_anteriores = 0;
    int dia_ultimo_mes = 0;
    
    for (int i = 1; i < data->mes; i++){
        dias_meses_anteriores += dias_no_mes(i,  data->ano);
    }

    dia_ultimo_mes = data->dia;

    return dias_meses_anteriores + dia_ultimo_mes;
}

// calcula os dias caso o ano sejam iguais
int calcular_dias_no_mesmo_ano(Dma *data1, Dma *data2){
    int dias_restantes_primeiro_mes = 0;
    int dias_restantes_ultimo_mes = data2->dia;
    int dias_restantes_entre_meses = 0;

    dias_restantes_primeiro_mes = dias_no_mes(data1->mes, data1->ano) - data1->dia;

    for (int i = data1->mes + 1; i < data2->mes; i++){
        dias_restantes_entre_meses += dias_no_mes(i, data1->ano);
    }

    int dias_total = dias_restantes_primeiro_mes + dias_restantes_ultimo_mes + dias_restantes_entre_meses;

    return dias_total;
}

// retorna a quantidade de dias entre as duas datas
int calcular_dias(Dma *a, Dma *b){

    int i = calcular_data_mais_antiga( a, b);

    if (i == -1){
        printf("As datas são iguais");
        exit(2);
    }
    else if( i == 0){
        trocar_datas(a, b);
    }

    // verifica se as datas sao do mesmo ano e mesmo mes
    if (a->ano == b->ano && a->mes == b->mes){
        return b->dia - a->dia;
    }
    else if(a->ano == b->ano){
        return calcular_dias_no_mesmo_ano(a, b); // caso sejam do mesmo ano
    }

    int dias_restantes_data_antigo = calcular_dias_restantes_data_antiga(a);
    int dias_restante_entre_datas = calcular_dias_entre_as_duas_datas(a, b);
    int dias_restante_data_atual = calcular_dias_restantes_data_atual(b);
    
    int dias_totais = dias_restante_data_atual + dias_restante_entre_datas + dias_restantes_data_antigo;
    return  dias_totais;
}

