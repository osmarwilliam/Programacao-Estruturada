/*Escreva um programa em C que caso um número informado seja primo,
escreve os dois primos anteriores e os dois primos sucessores a ele*/

#include <stdio.h>

int verifPrimos(int a);
int antecessor(int num);
int sucessor(int num);

int main(){
	int num;
    printf("Digite o número: ");
    scanf("%i", &num);
	
    if (verifPrimos(num)){
		if (num == 2) {
			printf("o número %i não tem antecessor \n", num);
			int suc_1 = sucessor(num);
			int suc_2 = sucessor(suc_1);
			printf("sucessor: %i \n", suc_1);
			printf("sucessor: %i \n", suc_2);
	
			return 3;
		}
		if (num == 3){
			printf("o número %i tem um antecessor que é o número: %i\n", num, antecessor(num));
			int suc_1 = sucessor(num);
			int suc_2 = sucessor(suc_1);
			printf("sucessor: %i \n", suc_1);
			printf("sucessor: %i \n", suc_2);
			return 4;
		}
	}
	else {
		printf("Digite um número primos.\n");
		return 2;
	}
	
	int ant_1 = antecessor(num);
	int ant_2 = antecessor(ant_1);
	printf("antecessor: %i \n", ant_1);
	printf("antecessor: %i \n", ant_2);
	int suc_1 = sucessor(num);
	int suc_2 = sucessor(suc_1);
	printf("sucessor: %i \n", sucessor(num));
	printf("sucessor: %i \n", sucessor(suc_1));
	

	return 0;
}

int antecessor(int num){

	for (int i = num - 1; i >= 2; i--){
		if(verifPrimos(i)){
			return i;
		}
	}
	return 0;
}

int sucessor(int num){
	int a = num + 1; 
	while(1){
		if(verifPrimos(a)){
			return a;
		}
		a++;
	}
	return 0;
}


int verifPrimos(int a){

	int count = 0;
	for (int i = 1; i <= a; i++){
		if (a % i == 0){
			count++;
		}

	}
	if (count == 2){
		return 1;
	}
	return 0;
}