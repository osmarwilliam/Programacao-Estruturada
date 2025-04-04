/* Leia um valor inteiro correspondente à idade de uma pessoa em dias e informe-a em anos, meses e dias
Obs.: apenas para facilitar o cálculo, considere todo ano com 365 dias e todo mês com 30 dias. 
Nos casos de teste nunca haverá uma situação que permite 12 meses e alguns dias, como 360, 363 ou 364. 
Este é apenas um exercício com objetivo de testar raciocínio matemático simples.
Entrada: O arquivo de entrada contém um valor inteiro.
*/

#include <stdio.h>

int main(){
    int ano = 0;
    int mes = 0;
    int dia = 0;
    
    int valor;
    scanf("%i", &valor);
    int resto = 0;

    if (valor >= 365) {
        ano = valor / 365;
        valor = valor - ano*365;
    }
    if (valor >= 30) {
        mes = valor / 30;
        valor = valor - mes*30;
    }
    dia = valor;

    printf("%i ano(s)\n", ano);
    printf("%i mes(es)\n", mes);
    printf("%i dia(s)\n", dia);

    return 0;
}