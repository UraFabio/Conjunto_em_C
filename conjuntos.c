#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conjuntos.h"



// FUNÇÕES AUXILIARES:

void trocarElementos(Conjunto* conjunto, int a, int b){ // Troca a posição de 2 elementos no conjunto
	int aux = conjunto->elementos[a];
	conjunto->elementos[a] = conjunto->elementos[b];
	conjunto->elementos[b] = aux;
}

void automatico(Conjunto* conjunto){ // Preenche o conjunto com numero aleatorios
	srand(time(NULL));
 	while(conjunto->tamanho < (20) && conjunto->tamanho < MAX){
 		adicionarElemento(conjunto, (rand() % 99) + 1);
	 }
	
}

void menu(){
	printf("*********MENU**********\n");
	printf("Digite:\n\n");
	printf("1 - Para adicionar elementos ao conjunto\n");
	printf("2 - Para remover elementos do conjunto\n");
	printf("3 - Para buscar elementos no conjunto \n");
	printf("4 - Para mostrar o conjunto\n");
	printf("5 - Para destruir um conjunto\n");
	printf("6 - Para preencher o conjunto com numeros aleatorios\n");
	printf("0 - Para passar para a proxima etapa\n\n");
	printf("***********************\n");
}

///////////////////////////////////////////////////////////////






// FUNÇÕES ENVOLVENDO 1 CONJUNTO:

void criarConjunto(Conjunto* conjunto){
	conjunto->tamanho = 0;
}

int adicionarElemento(Conjunto* conjunto, int n){
	
	// Deve-se verificar se o elemento já está no conjunto
	int i;
	for(i = 0; i<conjunto->tamanho; ++i){
		if(n == conjunto->elementos[i]){
			
			return 1;
		}
	}
	
	// Verifica se tem espaço no conjunto
	if(conjunto->tamanho < MAX){
		conjunto->elementos[conjunto->tamanho] = n;
		conjunto->tamanho++;
		return 0;
	}
	return 2;
}

void removerElemento(Conjunto* conjunto, int n){
	int i = 0;
	while(i < conjunto->tamanho){
		if(n == conjunto->elementos[i]){
			if(i == (conjunto->tamanho - 1)){
					
			}else{
				while(i < (conjunto->tamanho - 1)){
					trocarElementos(conjunto, i, i+1);		
					i++;
				}
			}
			conjunto->tamanho = conjunto->tamanho - 1;
			printf("Elemento removido com sucesso\n");
			return;
		}
		i++;
	}
	printf("Elemento nao existe no conjunto\n");
}

void mostrarConjunto(Conjunto conjunto){
	int i;
	printf("[ ");
	for(i = 0; i < conjunto.tamanho; i++){
		printf("%d ", conjunto.elementos[i]);
	}
	printf("]\n");
	printf("Tamanho: %d\n", conjunto.tamanho);
}

void destruirConjunto(Conjunto* conjunto){
	conjunto->tamanho = 0;
}

void buscarElemento(Conjunto conjunto, int n){
	int i = 0;
	while(i < conjunto.tamanho){
		if(conjunto.elementos[i] == n){
			printf("Elemento encontrado!\n");	
			return;
		}
		i++;
	}
	printf("Elemento nao encontrado\n");
}

///////////////////////////////////////////////////////////////////


// FUNÇÕES ENVOLVENDO 2 CONJUNTOS:

Conjunto uniaoConjuntos(Conjunto c1, Conjunto c2){
	Conjunto resultado;
	
	criarConjunto(&resultado);
	
	int i;
	for(i = 0; i < c1.tamanho; i++){
		adicionarElemento(&resultado, c1.elementos[i]);
	}
	
	for(i = 0; i < c2.tamanho; i++){
		adicionarElemento(&resultado, c2.elementos[i]);
	}
	
	return resultado;
}

Conjunto intersecaoConjuntos(Conjunto c1, Conjunto c2){
	Conjunto resultado;
	
	criarConjunto(&resultado);
	
	int i, j,  n;
	for(i = 0; i < c1.tamanho; i++){
		n = c1.elementos[i];
		for(j = 0; j < c2.tamanho; j++){
			if(n == c2.elementos[j]){
				adicionarElemento(&resultado, n);
				break;
			}
		}
	}
	return resultado;	
}

Conjunto diferencaConjuntos(Conjunto c1, Conjunto c2){
	Conjunto resultado;
	
	criarConjunto(&resultado);
	
	int i, j, n, v;
	for(i = 0; i < c1.tamanho;i++){
		n = c1.elementos[i];
		v = 0;
		for(j = 0; j < c2.tamanho; j++){
			if(n == c2.elementos[j]){
				v = 1;
				break;
			}
		}
		if(v == 0){
			adicionarElemento(&resultado, n);
		}
	}
	
	return resultado;
	
}
