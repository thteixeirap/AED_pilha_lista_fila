#ifndef QUATRO_H
#define QUATRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Paciente Paciente;
typedef struct Bloco4 Bloco4;
typedef struct BlocoPilha BlocoPilha;
typedef struct Lista4 Lista4;
typedef struct Fila4 Fila4;
typedef struct Relatorio Relatorio;
typedef struct Pilha4 Pilha4;

struct Paciente{
	char nome[20];
	int idade;
};

struct Bloco4{
	Paciente paciente;
	Bloco4 *prox;
};

struct Relatorio{
	Paciente paciente;
	char data[10];
	char prontuario[100];
};

struct BlocoPilha{
	Relatorio dados;
	BlocoPilha *prox;
};

struct Lista4{
	Bloco4 *first;
	Bloco4 *last;
};

struct Fila4{
	int qtd;
	Bloco4 *first;
	Bloco4 *last;
};

struct Pilha4{
	BlocoPilha *top;
	BlocoPilha *base;
};


void LVazia4(Lista4 *l);
void Linsere4(Lista4 *l, Paciente p);
void AdicionarPaciente(Fila4 *f);
void LImprimi4(Lista4 *l);

void FVazia4(Fila4 *f);
void Enfileira4(Fila4 *f,Paciente p);
void Desenfileira4 (Fila4 *f, Paciente *p);
void OrganizaIdade(Fila4 *f,Lista4 *l);

void Push4(Pilha4 *p,Relatorio r);
void Pop4(Pilha4 *p,Relatorio r);
void PImprime4(Pilha4 *p);
void AtendimentePaciente(Lista4 *l,Pilha4 *p);

#endif
