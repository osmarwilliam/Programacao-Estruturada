#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "agenda.h"

Pessoa *criar_agenda() {
    Pessoa *agenda = (Pessoa*)malloc(100 * sizeof(Pessoa));
    if (agenda == NULL) {
        printf("Impossível criar a agenda!\n");
        exit(1);
    }
    return agenda;
}

void liberar_agenda(Pessoa *agenda) {
    free(agenda);
}

void inserir_pessoa(Pessoa *pessoa_para_adicionar) {
    printf("Digite o NOME: ");
    scanf(" %59[^\n]", pessoa_para_adicionar->nome);

    printf("Digite o EMAIL: ");
    scanf(" %59[^\n]", pessoa_para_adicionar->email);

    printf("Digite a RUA: ");
    scanf(" %59[^\n]", pessoa_para_adicionar->endereco.rua);

    printf("Digite o CEP: ");
    scanf(" %29[^\n]", pessoa_para_adicionar->endereco.cep);

    printf("Digite o NÚMERO: ");
    scanf(" %29[^\n]", pessoa_para_adicionar->endereco.numero);

    printf("Digite o BAIRRO: ");
    scanf(" %59[^\n]", pessoa_para_adicionar->endereco.bairro);
    
    printf("Digite o CIDADE: ");
    scanf(" %29[^\n]", pessoa_para_adicionar->endereco.cidade);

    printf("Digite o ESTADO: ");
    scanf(" %29[^\n]", pessoa_para_adicionar->endereco.estado);

    printf("Digite o PAÍS: ");
    scanf(" %29[^\n]", pessoa_para_adicionar->endereco.pais);

    printf("Complemento: ");
    scanf(" %59[^\n]", pessoa_para_adicionar->endereco.complemento);

    printf("Digite o DDD do seu número: ");
    scanf(" %4[^\n]", pessoa_para_adicionar->telefone.DDD);

    printf("Digite o seu número: ");
    scanf(" %14[^\n]", pessoa_para_adicionar->telefone.numero);
    getchar();

    printf("Digite o dia do seu aniversário: ");
    scanf("%d", &pessoa_para_adicionar->aniversario.dia);
    getchar();

    printf("Digite o mês do seu aniversário: ");
    scanf("%d", &pessoa_para_adicionar->aniversario.mes);
    getchar();

    printf("Digite o ano do seu aniversário: ");
    scanf("%d", &pessoa_para_adicionar->aniversario.ano);
    getchar();

    printf("Caso queira adicionar alguma observação: ");
    scanf(" %59[^\n]", pessoa_para_adicionar->observacao);
    getchar();
}

int comparar_nomes(const void *a, const void *b) {
    const Pessoa *pessoaA = (const Pessoa *)a;
    const Pessoa *pessoaB = (const Pessoa *)b;
    return strcmp(pessoaA->nome, pessoaB->nome);
}

void imprimir_pessoa(Pessoa *pessoa){
    printf("----------------------\n");
    printf("Nome: %s\n", pessoa->nome);
    printf("Email: %s\n", pessoa->email);
    printf("Endereço: \n");
    printf("    Rua: %s\n", pessoa->endereco.rua);
    printf("    CEP: %s\n", pessoa->endereco.cep);
    printf("    Número: %s\n", pessoa->endereco.numero);
    printf("    Bairro: %s\n", pessoa->endereco.bairro);
    printf("    Cidade: %s\n", pessoa->endereco.cidade);
    printf("    País: %s\n", pessoa->endereco.pais);
    printf("    Complemento: %s\n", pessoa->endereco.complemento);
    printf("Telefone: (%s) %s \n", pessoa->telefone.DDD, pessoa->telefone.numero);
    printf("Aniversário: %d/%d/%d \n", pessoa->aniversario.dia, pessoa->aniversario.mes, pessoa->aniversario.ano);
    printf("Observação: %s\n", pessoa->observacao);
    printf("----------------------\n");
}

void imprimir_pessoa_parcial(Pessoa *pessoa){
    printf("----------------------\n");
    printf("Nome: %s\n", pessoa->nome);
    printf("Telefone: (%s) %s \n", pessoa->telefone.DDD, pessoa->telefone.numero);
    printf("Email: %s\n", pessoa->email);
    printf("----------------------\n");
}


void imprimir_dados_parcial(Pessoa *agenda, const int *qtd_pessoa){
    for (int i = 0; i < *qtd_pessoa; i++){
        imprimir_pessoa_parcial(agenda);
        agenda++;
    }
}

void imprimir_dados_total(Pessoa *agenda,const int *qtd_pessoa){
    for (int i = 0; i < *qtd_pessoa; i++){
        imprimir_pessoa(agenda);
        agenda++;
    }
}

void buscar_pessoa_por_mes(Pessoa *pessoa, int mes,const int qtd_pessoa){
    int count = 0;
    for (int i = 0; i < qtd_pessoa; i++){
        if (pessoa->aniversario.mes == mes){
            imprimir_pessoa(pessoa);
            count ++;
        }
        pessoa++;
    }
    if (count == 0){
        printf("\n");
        printf("\n\n* Não há na lista ninguém com esse mês de aniversário.\n\n");
    }
}

void buscar_pessoa_por_dia_e_mes(Pessoa *pessoa, int dia, int mes,const int qtd_pessoa){
    int count = 0;
    for (int i = 0; i < qtd_pessoa; i++){
        if (pessoa[i].aniversario.dia == dia && pessoa[i].aniversario.mes == mes){
            imprimir_pessoa(&pessoa[i]);
            count++;
        }
    }
    if (count == 0){
        printf("\n");
        printf("\n\n* Não há ninguém na lista nascido no dia %d no mes %d \n\n", dia, mes);
    }
}

void buscar_pessoa_nome(char *pessoa_nome, Pessoa *agenda, const int qtd_pessoa){
    int count = 0;

    for (int i = 0; i < qtd_pessoa; i++){
        if(strcmp(pessoa_nome, agenda[i].nome) == 0){
            imprimir_pessoa(&agenda[i]);
            count++;
        }
    }
    if (count == 0){
        printf("\n\n* Pessoa não encontrada na agenda.\n\n");

    }
}

void remover_pessoa(char *nome, Pessoa *pessoa,int *qtd_pessoa){
    int posicao = 0;
    int count = 0;

    for (int i = 0; i < *qtd_pessoa; i++){
        if (strcmp(nome, pessoa[i].nome) == 0){
            posicao = i;
            count++;
            break;
        }
    }

    if (count == 0){
        printf("\n\n* Não foi possível achar esse nome na lista.\n\n");
        return;
    }

    for (int i = posicao; i < *qtd_pessoa - 1; i++){
        pessoa[i] = pessoa[i+1];
    }

    *qtd_pessoa -= 1;
    printf("\n\nPessoa removida com sucesso.\n\n");
}
