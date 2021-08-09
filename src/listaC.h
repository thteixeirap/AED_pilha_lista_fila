#ifndef listaC_H
#define listaC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAMLC 10

typedef struct Lista1 Lista1;
typedef struct Bloco1 Bloco1; 
typedef struct Itens1 Itens1;

typedef struct Lista2 Lista2;
typedef struct Bloco2 Bloco2; 
typedef struct Itens2 Itens2;

typedef struct Lista3 Lista3;
typedef struct Bloco3 Bloco3; 
typedef struct Itens3 Itens3;

typedef struct Aux Aux;

struct Itens1{
	char produto[10];
	int quant;
	int id; 
};

struct Itens2{
	char mercado[10];
	int id; 
};

struct Itens3{ //Preço
	Itens2 mercado;
	Itens1 produto; 
	float preco;
};

struct Bloco1{
	Itens1 itens;
	Bloco1 *prox;
};

struct Bloco2{
	Itens2 itens;
	Bloco2 *prox;
};

struct Bloco3{
	Itens3 itens;
	Bloco3 *prox;
};

struct Lista1{
	Bloco1 *first;
	Bloco1 *last;
};

struct Lista2{
	int qnt;
	Bloco2 *first;
	Bloco2 *last;
};

struct Lista3{
	Bloco3 *first;
	Bloco3 *last;
};

struct Aux{
	Itens2 mercado;
	float soma;
};

void AdicionaProdutoLC(Lista1 *l);
void AdicionaMercadoLC(Lista2 *l);
void AdicionaPrecoLC(Lista3 *l3,Lista2 *l2,Lista1 *l1);
void Linsere1LC(Lista1 *l,Itens1 d);
void Linsere2LC(Lista2 *l,Itens2 d);
void Linsere3LC(Lista3 *l,Itens3 d);
void LVazia1LC(Lista1 *l);
void LVazia2LC(Lista2 *l);
void LVazia3LC(Lista3 *l);
void LImprimi1LC(Lista1 *l);
void CarrinhoLC(Lista3 *l3,Lista2 *l2,Lista1 *l1);

#endif
