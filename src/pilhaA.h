

#ifndef pilhaA_H
#define pilhaA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct ItemPA ItemPA;
typedef struct BlocoPA BlocoPA;
typedef struct PilhaPA PilhaPA;
typedef struct Cont Cont;


struct Cont{
	int openClose;
};

struct ItemPA{
	char val;
};

struct BlocoPA{
	ItemPA dado;
	BlocoPA *prox;
};

struct PilhaPA{
	Cont cont;
	BlocoPA *top;
	BlocoPA *base;
};

void FPVaziaPA(PilhaPA *p);
void PushPA(PilhaPA *p,ItemPA d);
void TokenizaPA(const int size,PilhaPA *p,char equation[size]);
void ValidaPA(PilhaPA *p);
void ConferePA(int op,PilhaPA *p);

#endif
