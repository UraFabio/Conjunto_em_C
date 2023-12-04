#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
	int elementos[MAX];
	int tamanho;
} Conjunto;

// Fun��es auxiliares:

void trocarElementos(Conjunto* conjunto, int a, int b);

void automatico(Conjunto* conjunto);

void menu();



// Fun��es sobre UM conjunto:

void criarConjunto(Conjunto* conjunto);

int adicionarElemento(Conjunto* conjunto, int n);

void removerElemento(Conjunto* conjunto, int n);

void mostrarConjunto(Conjunto conjunto);

void destruirConjunto(Conjunto* conjunto);

void buscarElemento(Conjunto conjunto, int n);




// Fun��es sobre DOIS conjunto:

Conjunto uniaoConjuntos(Conjunto c1, Conjunto c2);

Conjunto intersecaoConjuntos(Conjunto c1, Conjunto c2);

Conjunto diferencaConjuntos(Conjunto c1, Conjunto c2);
