#include "quatro.h"

void LVazia4(Lista4 *l){
	l->first = (Bloco4*) malloc (sizeof(Bloco4));
	l->last  = l->first;
	l->first->prox = NULL;
}

void FVazia4(Fila4 *f){
	f->first = (Bloco4*) malloc (sizeof(Bloco4));
	f->last  = f->first;
	f->first->prox = NULL;
	f->qtd = 0;
}

void Linsere4(Lista4 *l,Paciente p){
	l->last->prox = (Bloco4*)malloc(sizeof(Bloco4));
	l->last = l->last->prox;
	l->last->paciente = p;
	l->last->prox = NULL;	
}

void AtendimentePaciente(Lista4 *l,Pilha4 *p){
	Bloco4 *aux;
	aux = l->first->prox;
	Relatorio rl;
	while(aux!=NULL){
		rl.paciente = aux->paciente;
		printf("\tPaciente : %s\n\n",aux->paciente.nome);
		printf("Data do atendimento: ");
		scanf("%s",&rl.data);
		printf("Descreva o prontuario: ");
		scanf("%s",&rl.prontuario);
		Push4(p,rl);
		system("cls||clear");
		printf("\n\tATENDIMENTO CONCLUIDO\n\n");
		aux = aux->prox;
	}
}

void Infileira4(Fila4 *f,Paciente p){
	f->last->prox = (Bloco4*)malloc(sizeof(Bloco4));
	f->last = f->last->prox;
	f->last->paciente = p;
	f->last->prox = NULL;
	f->qtd++;
}

void Desenfileira4 (Fila4 *f, Paciente *p){
	Bloco4 *aux;
	
	if(f->first == f->first || f == NULL || f->first->prox == NULL){
		printf("FILA VAZIA!");
		return;		
	}
	
	aux = f->first;
	f->first = f->first->prox;
	p->idade = f->first->paciente.idade;
}

void FPVazia4(Pilha4 *p){
	p->base = (BlocoPilha*) malloc (sizeof(BlocoPilha));
	p->top = p->base;
	p->base->prox = NULL;	
}

void Push4(Pilha4 *p,Relatorio r){
	BlocoPilha *aux = (BlocoPilha*) malloc(sizeof(BlocoPilha));
	aux->dados = r;
	aux->prox = p->top;
	p->top = aux;
}

void Pop4(Pilha4 *p,Relatorio r){
	BlocoPilha *aux;
	
	if(p->base == p->top || NULL){
		printf("PILHA VAZIA!");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	r = aux->dados;
	free(aux);
}


void AdicionarPaciente(Fila4 *f){
	
	Paciente p;
	int op=0;
			
		printf("\tCADASTRO PACIENTE\n\n");
		printf("Nome: ");
		scanf("%s",&p.nome);
		printf("Idade: ");
		scanf("%d",&p.idade);
		Infileira4(f,p);

}

void OrganizaIdade(Fila4 *f,Lista4 *l){
	
	int idades[f->qtd];
	idades[0] = f->first->prox->paciente.idade;
	int menor;
	Bloco4 *aux;
	aux = f->first->prox->prox;
	int i=1,j,k,p;
	
	while(aux != NULL){
			
		idades[i] = aux->paciente.idade;
	//	printf("IDADES[%d]: %d\n",i,aux->paciente.idade);
	
		k=i;
		p=i-1;
		for(j=i-1;j>=0;j--){	

			//printf("Compara IDADES[%d]: %d < IDADES[%d]: %d\n",p,idades[p],k,idades[k] );
			if(idades[p] < idades[k]){
			//	printf("%d é menor que %d", idades[p],idades[k]);
				menor = idades[k];
				idades[k] = idades[p];
				idades[p] = menor;
				k--;
			}
			p--;
		}
		aux = aux->prox;
		i++;
	}

	
	for(i=0;i<f->qtd;i++){
		aux = f->first->prox;
		while(aux != NULL){
			if(idades[i] == aux->paciente.idade){				
				Linsere4(l,aux->paciente);
			}
			aux = aux->prox;
		}
	}
}




