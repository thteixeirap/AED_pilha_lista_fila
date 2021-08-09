
#ifndef pilhaC_H 
#define pilhaC_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXTAMPC 20

typedef struct ItemPC ItemPC;
typedef struct PilhaPC PilhaPC;

struct ItemPC{
	int val;
};

struct PilhaPC{
	int qnt;
	ItemPC itens[MAXTAMPC];
};

void FPVaziaPC(PilhaPC *p);
void PUSHPC(PilhaPC *p, ItemPC d);
void PreenchePilhaPC(PilhaPC *p);
void PImprimePC(PilhaPC *p);
int phi( int n);
int gcd(int a, int b);
void totientePC(PilhaPC *p);

#endif
