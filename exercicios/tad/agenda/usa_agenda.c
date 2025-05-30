/*
 Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-se
ter os seguintes dados:
• Nome
• E-mail
• Endereco (contendo campos para Rua, numero, complemento, bairro, cep, cidade,
estado, paıs).
• Telefone (contendo campo para DDD e numero) 
• Data de aniversario (contendo campo para dia, mes, ano). 
• Observacoes: Uma linha (string) para alguma observacao especial. 

(a) Definir a estrutura acima.
(b) Declarar a variavel agenda (vetor) com capacidade de agendar ate 100 nomes.
(c) Definir um bloco de instrucoes busca por primeiro nome: Imprime os dados da pessoa com esse nome (se tiver 
mais de uma pessoa, imprime para todas).
(d) Definir um bloco de instrucoes busca por mes de aniversario: Imprime os dados de 
todas as pessoas que fazem aniversario nesse mes.
(e) Definir um bloco de instrucoes busca por dia e mes de aniversario: Imprime os
dados de todas as pessoas que fazem aniversario nesse dia e mes. 
(f) Definir um bloco de instrucoes insere pessoa: Insere por ordem alfabetica de nome.
(g) Definir um bloco de instrucoes retira pessoa: Retira todos os dados dessa pessoa e
desloca todos os elementos seguintes do vetor para a posicao anterior.
(h) Definir um bloco de instruc¸oes imprime agenda com as opcoes: 
• Imprime nome, telefone e e-mail.
• Imprime todos os dados.
(i) O programa deve ter um menu principal oferecendo as opcoes acima.
*/

#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

void opcoes_para_escolha();
void opcoes_imprimir();
void ler_dia_mes(int *dia, int *mes);
void ler_mes(int *mes);
void ler_pessoa(char *pessoa);
void ler_pessoa_para_remover(char *nome);

int main(){

    int contagem = 0;
    int opcoes = 0;
    
    Pessoa *agenda = criar_agenda();
    int opcao1;
    int mes, ano, dia;
    char pessoa[60];

    do{
        opcoes_para_escolha();
        scanf("%d", &opcoes);
        // Escolha uma pessoa para imprimir seus dados
        if (opcoes == 1){
            ler_pessoa(pessoa);
            buscar_pessoa_nome(pessoa, agenda, contagem); 
        }
        // Busca uma pessoa pelo mês de aniversário
        else if(opcoes == 2){ 
            ler_mes(&mes);
            buscar_pessoa_por_mes(agenda, mes, contagem);
        }
        // Buscar uma pessoa pelo dia e mês de aniversário
        else if(opcoes == 3){
            ler_dia_mes(&dia, &mes);
            buscar_pessoa_por_dia_e_mes(agenda, dia, mes, contagem);

        }
        // inserir pessoa
        else if (opcoes == 4){
            if (contagem < 100) {
                inserir_pessoa(&agenda[contagem]);
                contagem++;
                qsort(agenda, contagem, sizeof(Pessoa), comparar_nomes);
            } 
            else {
                printf("Agenda cheia! Não é possível adicionar mais contatos.\n");
            }
        }

        // remover pessoa
        else if (opcoes == 5){
            ler_pessoa_para_remover(pessoa);
            remover_pessoa(pessoa, agenda, &contagem);
    
        }

        // imprimir agenda
        else if (opcoes == 6){
            opcoes_imprimir();
            scanf("%d", &opcao1);

            if(opcao1 == 1){
                imprimir_dados_parcial(agenda, &contagem);
                printf("\n");
            }
            else if (opcao1 == 2){
                imprimir_dados_total(agenda, &contagem);
                printf("\n");
            }
        }
        // sair da agenda
        else if(opcoes == 7){
            printf("Saindo da agenda...");
        }
        // caso tenha digitado algum número inválido
        else{
            printf("Digite uma opção válida.\n");
        }
    } while(opcoes != 7);

    liberar_agenda(agenda);

    return 0;
}

void ler_pessoa_para_remover(char *nome){
    printf("Digite o nome da pessoa que você deseja remover: ");
    scanf(" %59[^\n]", nome);
    getchar();
}

void ler_pessoa(char *pessoa){
    printf("Digite o nome da pessoa que você deseja procurar: ");
    scanf(" %59[^\n]", pessoa);
    getchar();
}

void ler_mes(int *mes){
    printf("\n");
    printf("Digite o valor do mês:");
    scanf("%d", mes);
}

void ler_dia_mes(int *dia, int *mes){
    printf("\n");
    printf("Digite o dia: ");
    scanf("%d", dia);
    printf("Digite o mês: ");
    scanf("%d", mes);
}

void opcoes_imprimir(){
    printf("\n");
    printf("1) •Imprime nome, telefone e e-mail. \n");
    printf("2) •Imprime todos dados. \n");
    printf("Escolha uma das opções: ");
}

void opcoes_para_escolha(){
    printf("********* AGENDA *********\n");
    printf("Escolha umas das opções abaixo:\n");
    printf("1) Escolha uma pessoa para imprimir seus dados:\n");
    printf("2) Buscar uma pessoa pelo mês de aniversário:\n");
    printf("3) Buscar uma pessoa pelo dia e mês de aniversário:\n");
    printf("4) Inserir pessoa:\n");
    printf("5) Remover pessoa:\n");
    printf("6) Imprimir agenda:\n");
    printf("7) Sair:\n");
    printf("Escolha uma das opções (1-7): ");
}
