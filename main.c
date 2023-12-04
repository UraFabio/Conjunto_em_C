#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"


int main() {
	Conjunto A, B;
	criarConjunto(&A);
	criarConjunto(&B);
	
	int op, n, aux;
	
	
	printf("OPERACAO SOBRE O CONJUNTO A:\n");
	do{
		menu();
		printf(">> ");
		scanf("%d", &op);
		printf("\n\n\n");
		switch(op){
			case 1:
				do{
					printf("Digite o elemento a ser adicionado (-1 para parar): ");
					scanf("%d", &n);
					if(n != -1){
					
						aux = adicionarElemento(&A, n);
						if(aux == 1){
							printf("Elemento ja existe no conjunto\n");
						}else if(aux == 2){
							printf("Conjunto cheio, impossivel adicionar mais elementos\n");
						}else{
							printf("Elemento inserido com sucesso\n;");
						}
					}
				}while(n != -1);
				break;
				
			case 2:
				do{
					printf("Digite o elemento a ser removido (-1 para parar): ");
					scanf("%d", &n);
					if(n != -1){
						removerElemento(&A, n);
					}
				}while(n != -1);
				break;
				
			case 3:
				do{
					printf("Digite o elemento a ser buscado: ");
					scanf("%d", &n);
					if(n != -1){
						buscarElemento(A, n);
					}
				}while(n != -1);
				break;
				
			case 4:
				mostrarConjunto(A);
				break;
				
			case 5:
				destruirConjunto(&A);
				break;
				
			case 6:
				automatico(&A);
				break;
				
			case 0:
				printf("Finalizando...\n\n");
				break;
				
			default:
				printf("Digite uma opcao valida\n");
				break;
				
		}
		printf("\n\n\n\n");
	}while(op != 0);
	
	
	system("cls");
	
	printf("OPERACAO SOBRE O CONJUNTO B:\n");
	do{
		menu();
		printf(">> ");
		scanf("%d", &op);
		printf("\n\n\n");
		switch(op){
			case 1:
				do{
					printf("Digite o elemento a ser adicionado (-1 para parar): ");
					scanf("%d", &n);
					if(n != -1){
					
						aux = adicionarElemento(&B, n);
						if(aux == 1){
							printf("Elemento ja existe no conjunto\n");
						}else if(aux == 2){
							printf("Conjunto cheio, impossivel adicionar mais elementos\n");
						}else{
							printf("Elemento inserido com sucesso\n;");
						}
					}
				}while(n != -1);
				break;
				
			case 2:
				do{
					printf("Digite o elemento a ser removido (-1 para parar): ");
					scanf("%d", &n);
					if(n != -1){
						removerElemento(&B, n);
					}
				}while(n != -1);
				break;
				
			case 3:
				do{
					printf("Digite o elemento a ser buscado: ");
					scanf("%d", &n);
					if(n != -1){
						buscarElemento(B, n);
					}
				}while(n != -1);
				break;
				
			case 4:
				mostrarConjunto(B);
				break;
				
			case 5:
				destruirConjunto(&B);
				break;
				
			case 6:
				automatico(&B);
				break;
				
			case 0:
				printf("Finalizando...\n\n");
				break;
				
			default:
				printf("Digite uma opcao valida\n");
				break;
				
		}
		printf("\n\n\n\n");
	}while(op != 0);

	system("cls");
	
	printf("\n\n");
	printf("Conjunto A:\n");
	mostrarConjunto(A);
	
	printf("\n\n");
	printf("Conjunto B:\n");
	mostrarConjunto(B);
	
	
	printf("\n\n");
	Conjunto Uniao = uniaoConjuntos(A, B);
	printf("Uniao dos conjuntos A e B:\n");
	mostrarConjunto(Uniao);
	
	
	printf("\n\n");
	Conjunto Intersecao = intersecaoConjuntos(A, B);
	printf("Intersecao dos conjutnos A e B:\n");
	mostrarConjunto(Intersecao);
	
	
	printf("\n\n");
	Conjunto Diferenca1 = diferencaConjuntos(A, B);
	printf("Diferenca do conjunto A em relacao a B:\n");
	mostrarConjunto(Diferenca1);
	
	
	printf("\n\n");
	Conjunto Diferenca2 = diferencaConjuntos(B, A);
	printf("Diferenca do conjunto B em relacao a A:\n");
	mostrarConjunto(Diferenca2);
	

	
	return 0;
}
