#include "listaB.h"

void ImprimeListasLB(ListaLB *l1,ListaLB *l2){
int i=0;
	
	while(i<l1->quantid){
		printf("[%d|%d] \t",l1->item[i].dado,l2->item[i].dado);
		i++;
	}
}

void FLVaziaLB(ListaLB *l){
	l = (ListaLB*) malloc(sizeof(ListaLB));
	if(l == NULL) printf("ERRO");
	l->quantid = 0;
}

void InserirLB(ListaLB *l,ItemLB d){

	if(l->quantid > MAXTAMLB){
		printf("LISTA CHEIA");
		//return -1;
	}
	
	l->item[l->quantid] = d;
	l->quantid++;
}

void PreencheListaLB(ListaLB *l){
	ItemLB d;
	//srand(time(NULL));
	while(l->quantid<MAXTAMLB){	
		d.dado = (rand() % 13);
		InserirLB(l,d);
	}
}

int CriaNumAleatorioLB(){
	int num;
	srand(time(NULL));
	return num = (rand() % 13);
}

void SubtraiListaLB(int num,ListaLB *l1,ListaLB *l2){
	int i=0;
	
	while(i<l1->quantid){
		l1->item[i].dado = l1->item[i].dado-num;
		l2->item[i].dado = l2->item[i].dado-num;	
		i++;
	}
}

void VerificaListaVencedoraLB(ListaLB *l1,ListaLB *l2){

	int i=0,resulL1=0,resulL2=0;	
	
	while(i<l1->quantid){
		resulL1 = resulL1 + l1->item[i].dado;
		resulL2 = resulL2 + l2->item[i].dado;	
		i++;
	}
	
	if(resulL1>resulL2){
		printf("\n [%d]>[%d] ====>  LISTA 1 VENCEU",resulL1,resulL2);
	}else if(resulL1<resulL2)
	printf("\n [%d]<[%d] ====>  LISTA 2 VENCEU",resulL1,resulL2);
		else printf("\n [%d]==[%d] ====>  EMPATE",resulL1,resulL2);
}
