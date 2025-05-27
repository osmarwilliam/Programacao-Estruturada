/* TAD : */
typedef struct ponto Ponto;

typedef struct circulo Circulo;


Circulo *cria_circulo(float x, float y, float raio);

/* Função distancia - Retorna a distância entre dois pontos e o circulo */
int verificar_pontos(float p,float q, Circulo *raio);

/* Função libera - Libera a memória de um ponto previamente criado */
void circulo_liberar(Circulo *p);

int distancia(float p, float q);

float calcular_area(Circulo *p);
