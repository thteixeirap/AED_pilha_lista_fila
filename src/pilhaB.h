
#ifndef pilhaB_H
#define pilhaB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXTAMPB 6

typedef struct ItemPB ItemPB;
typedef struct BlocoPB BlocoPB;
typedef struct PilhaPB PilhaPB;

struct ItemPB{
	int val;
};

struct BlocoPB{
	ItemPB dado;
	BlocoPB *prox;
};

struct PilhaPB{
	int qnt;
	BlocoPB *top;
	BlocoPB *base;
};

void FPVaziaPB(PilhaPB *p);
void PushPB(PilhaPB *p,ItemPB d);
void PopPB(PilhaPB *p, ItemPB *d);
void PImprimePB(PilhaPB *p);
void PreenchePilhaPB(PilhaPB *p);
void TransferePilhaPB(PilhaPB *p1,PilhaPB *p2);


#endif
