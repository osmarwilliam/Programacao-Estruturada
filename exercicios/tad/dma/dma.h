typedef struct dma Dma;


// Função usada para criar uma struct da data, recebe dias, mes e ano como parâmetro
Dma *cria_dma(int dia, int mes, int ano);

// Libera a struct criada e alocada
void libera_dma(Dma *p);

// verifica qual a data mais antiga
int calcular_data_mais_antiga(Dma *a, Dma *b);

// troca as datas, caso elas estejam em ordem errada
void trocar_datas(Dma *a, Dma *b);

// verifica se um ano é bissexto
int eh_bissexto(int ano);

// verifica em qual mes está e retorna quantos dias tem aquele mes
int dias_no_mes(int mes, int ano);

// calcula os dias restantes no ano da data mais antiga
int calcular_dias_restantes_data_antiga(Dma *a);

// calcula os dias nos anos inteiros entre as duas datas 
int calcular_dias_restantes_data_recente(Dma *data1, Dma *data2);

// calcula os dias restantes no ano da data mais recente
int calcular_dias_restantes_data_atual(Dma *data);

// calcula os dias caso o ano sejam iguais
int calcular_dias_no_mesmo_ano(Dma *data1, Dma *data2);

// calcula a quantidade de dias entre as duas datas
int calcular_dias(Dma *a, Dma *b);
