
#include "listaMain.h"
#include "pilhaMain.h"
#include "quatroMain.h"


int main(int argc, char *argv[]) {
	
	int op,op1,op2;	
	
	do{
		
		printf("\n\tTRABALHO AEDS - MENU\n");
		printf("\n\n 1 - Exercicio 1|Listas\n 2 - Exercicio 2|Pilhas\n 3 - Exercicio 4|Lista Pilha Fila\ 4 - Sair");
		printf("\n Escolha uma opcao: ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("\n 1 - A\n 2 - B\n 3 - C\n");
				scanf("%d",&op1);
				switch(op1){
					
					case 1:
						system("cls||clear");
						listaA();
					break;	
					
					case 2:
						system("cls||clear");
						listaB();
					break;	
					
					case 3:
						system("cls||clear");
						listaC();
					break;	
					
					default:
						system("cls||clear");
						printf("\nDigito incorreto");
					break;	
				}
			break;	
			
			case 2:
				printf("\n 1 - A\n 2 - B\n 3 - C\n");
				scanf("%d",&op2);
				switch(op2){
					case 1:
						system("cls||clear");
						pilhaA();
					break;
					
					case 2:
						system("cls||clear");
						pilhaB();
					break;
					
					case 3:
						system("cls||clear");
						pilhaC();
					break;	
					
					default:
						printf("\nDigito incorreto");
					break;
				}
			break;
			
			case 3:
				system("cls||clear");
				quatroMain();
			break;
			
			case 4:
				system("cls||clear");
				printf("PROGRAMA FINALIZADO");
			
			default:
				printf("\nDigito incorreto");
			break;
					
		}				
	}while(true);
}
