#include "pilhaA.h"
#include "pilhaB.h"
#include "pilhaC.h"

int pilhaA(){
	
	char equation[] = "()))((";
	int size;
	size = strlen(equation);
	PilhaPA p;
	FPVaziaPA(&p);
	TokenizaPA(size,&p,equation);
	ValidaPA(&p);
	
 return 0;
}

int pilhaB() {
	
	PilhaPB p1;
	PilhaPB p2;
	FPVaziaPB(&p1);
	FPVaziaPB(&p2);
	PreenchePilhaPB(&p1);
	printf("\n\nLISTA A\n");
	PImprimePB(&p1);
 	TransferePilhaPB(&p1,&p2);
 	printf("\n\nLISTA B\n");
 	PImprimePB(&p2);
	return 0;
}

int pilhaC() {
	
	PilhaPC p;
	FPVaziaPC(&p);
	PreenchePilhaPC(&p);
	PImprimePC(&p);
	printf("\n\n\n");
	totientePC(&p);	
	return 0;
}
