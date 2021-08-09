#include "pilhaB.h"

void FPVaziaPB(PilhaPB *p){
	p->base = (BlocoPB*) malloc (sizeof(BlocoPB));
	p->top  = p->base;
	p->base->prox = NULL;
}

void PushPB(PilhaPB *p,ItemPB d){
	BlocoPB *aux = (BlocoPB*) malloc (sizeof(BlocoPB));
	aux->dado = d;
	aux->prox = p->top;
	p->top = aux;
}

void PopPB(PilhaPB *p, ItemPB *d){
	BlocoPB *aux;
	
	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA");
		return;
	}
		
	aux = p->top;
	p->top = aux->prox;
	d->val = aux->dado.val;
	free(aux);	
}

void PImprimePB(PilhaPB *p){
	int i=0;
	
	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA");
		return;
	}
	
	BlocoPB *aux;
	aux = p->top;
	while(aux != p->base){
		if(	aux->prox->prox == NULL){
		printf("%d ===> NULL",aux->dado.val);
		aux = aux->prox;
		i++;
		}else{
			printf("%d ===> ",aux->dado.val);
			aux = aux->prox;
		}
	}
}

void PreenchePilhaPB(PilhaPB*p){
	p->qnt =0;
	ItemPB d;
	int i;
	srand(time(NULL));
	int op = 0;

	do{
		printf("\nDigite um inteiro: ");
		scanf(" %d",&d.val);
		printf("\n");
		PushPB(p,d);
		p->qnt++;
		PImprimePB(p);
		printf("\n\n 1 - Adiciona Valor\n 2 - Sair ");
		scanf("%d",&op);
		//system ("cls||clear");
	}while(op!=2);
	system ("cls||clear");
	printf("\n - Pilha A criada\n");
}
	
void TransferePilhaPB(PilhaPB *p1,PilhaPB *p2){
	
	BlocoPB *aux ;
	aux = p1->top;
	
	int i = 1;
	while(p1->qnt > 0){
		if(i==p1->qnt){
			i=1;
			PushPB(p2,aux->dado);
			aux = p1->top;
			p1->qnt--;
		}
		else{
			aux = aux->prox;
			i++;	
		}
	}
	printf("\n\n - Pilha transferida de A para B");
}

