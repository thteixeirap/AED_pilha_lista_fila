#ifndef listaA_h
#define listaA_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXTAMLA 100

typedef struct BlocoLA BlocoLA;
typedef struct ItemLA ItemLA;
typedef struct ItemC ItemC;
typedef struct ListaLA ListaLA;
typedef struct Concatena Concatena;

struct ItemLA{
	int dado;
};

struct ListaLA{
	int quantid;
	ItemLA item[MAXTAMLA];
};

struct ItemC{
	int dadoL1;
	int dadoL2;
};

struct Concatena{
	int quantid;
	ItemC item[MAXTAMLA];
};

void PreencheListaParLA(ListaLA *l);
void PreencheListaImparLA(ListaLA *l);
void FLVaziaLA(ListaLA *l);
void FCVaziaLA(Concatena *c);
void LInsereLA(ListaLA *l,ItemLA d);
void LImprimeLA(Concatena *c);
void ImprimeListaLA(ListaLA *l);
void LConcatenaLA(Concatena *c,ListaLA *lA, ListaLA *lB);

#endif
