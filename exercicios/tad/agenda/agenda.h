typedef char String[60];
typedef char String_menor[30];

typedef struct endereco {
    String rua;
    String_menor numero;
    String complemento;
    String bairro;
    String_menor cep;
    String_menor cidade;
    String_menor estado;
    String_menor pais;
} Endereco;

typedef struct telefone {
    char DDD[5];
    char numero[15];
} Telefone;

typedef struct aniversario {
    int dia;
    int mes;
    int ano;
} Aniversario;

typedef struct pessoa {
    String nome;
    String email;
    Endereco endereco;
    Telefone telefone;
    Aniversario aniversario;
    String observacao;
} Pessoa;

Pessoa *criar_agenda();
void liberar_agenda(Pessoa *agenda);
void inserir_pessoa(Pessoa *pessoa_para_adicionar);
int comparar_nomes(const void *a, const void *b);
void imprimir_pessoa(Pessoa *pessoa);
void imprimir_pessoa_parcial(Pessoa *pessoa);
void imprimir_dados_parcial(Pessoa *agenda,const int *qtd_pessoa);
void imprimir_dados_total(Pessoa *agenda,const int *qtd_pessoa);
void buscar_pessoa_por_mes(Pessoa *pessoa, int mes,const int qtd_pessoa);
void buscar_pessoa_por_dia_e_mes(Pessoa *pessoa, int dia, int mes, const int qtd_pessoa);
void buscar_pessoa_nome(char *pessoa_nome, Pessoa *agenda,const int qtd_pessoa);
void remover_pessoa(char *nome, Pessoa *pessoa, int *qtd_pessoa);
