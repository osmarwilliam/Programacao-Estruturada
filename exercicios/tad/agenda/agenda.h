// char que será usado na criação das Struct
typedef char String[60];
typedef char String_menor[30];

// Cria a struct para armazenar os endereços 
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

// cria a struct para armazenar o telefone
typedef struct telefone {
    char DDD[5];
    char numero[15];
} Telefone;

// cria a struct para armazenar a data de aniversário
typedef struct aniversario {
    int dia;
    int mes;
    int ano;
} Aniversario;

// cria a struct para armazenar os dados de cada pessoa na agenda
typedef struct pessoa {
    String nome;
    String email;
    Endereco endereco;
    Telefone telefone;
    Aniversario aniversario;
    String observacao;
} Pessoa;

// cria a agenda
Pessoa *criar_agenda();

// libera a agenda depois dela ter sido utilizada
void liberar_agenda(Pessoa *agenda);

// usada para inserir a pessoa na agenda
void inserir_pessoa(Pessoa *pessoa_para_adicionar);

// utilizada para a ordenação das pessoas após uma nova pessoa ser armazenada na agenda
int comparar_nomes(const void *a, const void *b);

// imprime os dados da pessoa
void imprimir_pessoa(Pessoa *pessoa);

// imprime os dados parciais da pessoa
void imprimir_pessoa_parcial(Pessoa *pessoa);

// utilizada para procurar a pessoa e imprimir seus dados parciais
void imprimir_dados_parcial(Pessoa *agenda,const int *qtd_pessoa);

// utilizada para procurar a pessoa e imprimir todos dados
void imprimir_dados_total(Pessoa *agenda,const int *qtd_pessoa);

// busca e imprime o dado da pesssoa que tem aniversário no mês passado
void buscar_pessoa_por_mes(Pessoa *pessoa, int mes,const int qtd_pessoa);

// busca e imprime o dado da pesssoa que tem aniversário no mês e dia passados como parâmetro
void buscar_pessoa_por_dia_e_mes(Pessoa *pessoa, int dia, int mes, const int qtd_pessoa);

// busca e imprime os dados da pessoa cujo o nome foi passado como parâmetro
void buscar_pessoa_nome(char *pessoa_nome, Pessoa *agenda,const int qtd_pessoa);

// remove os dados da pessoa cujo o nome foi passado como parâmetro
void remover_pessoa(char *nome, Pessoa *pessoa, int *qtd_pessoa);
