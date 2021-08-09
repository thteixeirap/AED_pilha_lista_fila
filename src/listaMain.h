#include "listaA.h"
#include "listaB.h"
#include "listaC.h"

 void listaA(){
	ListaLA listaA;
	ListaLA listaB;
	Concatena listaC;
	FLVaziaLA(&listaA);
	FLVaziaLA(&listaB);
	PreencheListaParLA(&listaA);
	PreencheListaImparLA(&listaB);
	FCVaziaLA(&listaC);
	LConcatenaLA(&listaC,&listaA,&listaB);
	LImprimeLA(&listaC);
	
//return 0;
}

int listaB(){
	ListaLB l1;
	ListaLB l2;
	int num;
	FLVaziaLB(&l1);
	FLVaziaLB(&l2);	
	PreencheListaLB(&l1);
	PreencheListaLB(&l2);
	ImprimeListasLB(&l1,&l2);
	num= CriaNumAleatorioLB();
	printf("\nNumero aleatorio: %d",num);
	SubtraiListaLB(num,&l1,&l2);
	printf("\n");
	VerificaListaVencedoraLB(&l1,&l2);
	
return 0;
}

int listaC(){
			printf("ENTRO\n");
	Lista1 lista1;
	Lista2 lista2;
	Lista3 lista3;
	LVazia1LC(&lista1);
	LVazia2LC(&lista2);
	LVazia3LC(&lista3);
	AdicionaProdutoLC(&lista1);
	AdicionaMercadoLC(&lista2);
	AdicionaPrecoLC(&lista3,&lista2,&lista1);
	CarrinhoLC(&lista3,&lista2,&lista1);

return 0;		
}

