#include "quatro.h"

int quatroMain() {
	
	Fila4 f;
	Lista4 l;
	Pilha4 p;

	LVazia4(&l);
	FVazia4(&f);
	FPVazia4(&p);
	int op;
	
	do{
	printf("\t\tMENU\n");
	printf("\n 1 - Adicionar Paciente\n 2 - Organizar fila por Idade\n 3 - Iniciar atendimentos\n 4 - Sair");
	scanf("%d",&op);
	system("cls||clear");
	switch(op){
		
		case 1:
			AdicionarPaciente(&f);
			system("cls||clear");
			printf("\tPACIENTE CADASTRADO\n\n");
		break;
		
		case 2:
			OrganizaIdade(&f,&l);
			system("cls||clear");
			printf("\tORGANIZADO COM SUCESSO\n\n");
		break;
		
		case 3:
			AtendimentePaciente(&l,&p);
		break;	
		
		case 4:
			printf("\n\tPROGRAMA FINALIZADO");
			return 0;
		break;			
	}
}while(true);

}
