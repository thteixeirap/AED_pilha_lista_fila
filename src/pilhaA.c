#include "pilhaA.h"

void FPVaziaPA(PilhaPA *p){
	p->base = (BlocoPA*) malloc (sizeof(BlocoPA));
	p->top  = p->base;
	p->base->prox = NULL; 
	p->cont.openClose = 0;
}

void PushPA(PilhaPA *p,ItemPA d){
	BlocoPA *aux = (BlocoPA*) malloc (sizeof(BlocoPA));
	aux->dado = d;
	aux->prox = p->top;
	p->top = aux;
}

void TokenizaPA(const int size,PilhaPA *p,char equation[size]){
	ItemPA item;
	int i;
	for(i=0;i<size;i++){
		if(equation[i] == '('){
			item.val = equation[i];
			PushPA(p,item);
			ConferePA(1,p);
		}else if(equation[i] == ')'){
			item.val = equation[i];
			PushPA(p,item);
			ConferePA(2,p);
		}
	}
}

void ValidaPA(PilhaPA *p){
	if(p->cont.openClose != 0)
		printf("\tPARENTESES ERRADAS");
	else printf("\tPARENTESES CORRETAS");
}

void ConferePA(int op,PilhaPA *p){
	
	if(p->cont.openClose <= 0 && op == 2){ //UM FECHADO SEM UM ABERTO DE PAR
		printf("ERRO DE PARENTESES NA EQUACAO!\n");
		exit(0);
	}else if(p->cont.openClose > 0 && op == 1){ //ABERTURA QUANDO CONT ZERADO
		p->cont.openClose++;
	}else if(p->cont.openClose >= 0 && op == 2){//
		p->cont.openClose--;
	}	
}

