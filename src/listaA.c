#include "listaA.h"

void FLVaziaLA(ListaLA *l){
	l = (ListaLA*) malloc(sizeof(ListaLA));
	if(l == NULL) printf("ERRO");
	l->quantid = 0;
}

void FCVaziaLA(Concatena *c){
	c = (Concatena*) malloc(sizeof(Concatena));
	if(c == NULL) printf("ERRO");
	c->quantid = 0;
}

void LInsereLA(ListaLA *l,ItemLA d){
	if(l->quantid > MAXTAMLA){
		printf("LISTA CHEIA\n");
		return;
	}
	
	l->item[l->quantid] = d;
	l->quantid++;
}

void PreencheListaParLA(ListaLA *l){
	int i=0;
	ItemLA num;
		l->quantid=0;
	while(i<MAXTAMLA){	
		num.dado = (rand() % 100);
		if(num.dado%2==0 && num.dado != 0) {
			LInsereLA(l,num);	
			i++;
		}
	}
	printf(" - LISTA PAR CRIADA\n\n");
}

void PreencheListaImparLA(ListaLA *l){
	l->quantid=0;
	int i=0;
	ItemLA num;
	
	while(i<MAXTAMLA){	
		num.dado = (rand() % 100);
		if(num.dado%2!=0) {
		LInsereLA(l,num);	
		i++;
		}
	}
	printf(" - LISTA IMPAR CRIADA\n\n");
}

void LConcatenaLA(Concatena *c,ListaLA *lA, ListaLA *lB){

	int i=0;
	
	while(i<MAXTAMLA){
		c->item[i].dadoL1 = lA->item[i].dado;
		c->item[i].dadoL2 = lB->item[i].dado;
		c->quantid++;
		i++;
	}	
	
	printf(" - LISTA CONCATENACAO CRIADA\n\n");
}

void LImprimeLA(Concatena *c){
	
	int i=0;
	
	while(i<MAXTAMLA){
		
		printf("\t[%d|%d]",c->item[i].dadoL1,c->item[i].dadoL2);
		i++;
	}
}

void ImprimeListaLA(ListaLA *l){
	
	int i=0;
	int num;
	
	while(i<MAXTAMLA){
		printf("\t [%d]\n", l->item[i].dado);
		i++;
	}
}
