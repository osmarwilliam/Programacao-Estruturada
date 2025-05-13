/*
Construa uma função sufixo que, dados dois inteiros positivos a e b, verifica se b corresponde
aos últimos dígitos de a.
*/

#include <stdio.h>

int sufixo(int a, int b);

int main(){
    int a, b;

    printf("digite o valor de a: ");
    scanf("%d", &a);

    printf("digite o valor de b: ");
    scanf("%d", &b);

    if (sufixo(a,b)){
        printf("É sufixo\n");
    }    
    else {
        printf("Não é sufixo \n");
    } 

}

int sufixo(int a, int b){
    int i = 1;
    int temp1 = a % 10;
    int temp2 = b % 10;
     
    while (i){
        if (temp1 != temp2){
            return 0;
        }
        a = a / 10;
        b = b / 10;

        temp1 = a % 10;
        temp2 = b % 10;
        
        if (temp2 < 0.9){
            i = 0;
        }
    }
    return 1;
}