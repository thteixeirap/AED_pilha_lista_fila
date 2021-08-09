#ifndef listaB_H
#define listaB_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXTAMLB 3

typedef struct ItemLB ItemLB;
typedef struct ListaLB ListaLB;

struct ItemLB{
	int dado;
};

struct ListaLB{
	int quantid;
	ItemLB item[MAXTAMLB];
};

void FLVaziaLBLB(ListaLB *l);
void FInserirLB(ListaLB *l,ItemLB d);
void PreencheListaLB(ListaLB *l);
void ImprimeListasLB(ListaLB *l1,ListaLB *l2);
int CriaNumAleatorioLB();
void SubtraiListaLB(int num,ListaLB *l1,ListaLB *l2);
void VerificaListaVencedoraLB(ListaLB *l1,ListaLB *l2);

#endif
