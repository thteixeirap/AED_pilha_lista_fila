#include "pilhaC.h"

void FPVaziaPC(PilhaPC *p){
	p = (PilhaPC*) malloc(sizeof(struct PilhaPC));
	p->qnt = 0;
}

void PUSHPC(PilhaPC *p, ItemPC d){
	if(p == NULL) printf("ERRO");
	if(p->qnt>MAXTAMPC) printf("ERRO");
	p->itens[p->qnt] = d;
	p->qnt++;
}

void PImprimePC(PilhaPC *p){
	
	int i=0;
	while(i<MAXTAMPC){
		printf("\t[%d]",p->itens[i].val);
		i++;
	}
}

void PreenchePilhaPC(PilhaPC *p){
	
	int i=0;
	int num;
	ItemPC d;
	while(i<MAXTAMPC){
		num = rand() % 100;
		if(num!=0) {
			d.val= num;
			PUSHPC(p,d);
			i++;
		}
	}
	printf("Lista Criada");
}

int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int phi( int n){
     int result = 1;
    int i;
    for(i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

void totientePC(PilhaPC *p){
	int i;
	int n;
	for(i=0;i<MAXTAMPC;i++){
		n =phi(p->itens[i].val);
		printf("Valor na Pilha: %d | Totiente: %d\n",p->itens[i].val,phi(p->itens[i].val));
	}
}
