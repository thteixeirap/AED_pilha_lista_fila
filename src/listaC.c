#include "listaC.h"

void LVazia1LC(Lista1 *l){
	l->first = (Bloco1*) malloc (sizeof(Bloco1));
	l->last  = l->first;
	l->first->prox = NULL;
}

void LVazia2LC(Lista2 *l){
	l->first = (Bloco2*) malloc (sizeof(Bloco2));
	l->last  = l->first;
	l->first->prox = NULL;
	l->qnt = 0;
}

void LVazia3LC(Lista3 *l){
	l->first = (Bloco3*) malloc (sizeof(Bloco3));
	l->last  = l->first;
	l->first->prox = NULL;
}

void Linsere1LC(Lista1 *l,Itens1 d){
	l->last->prox = (Bloco1*)malloc(sizeof(Bloco1));
	l->last = l->last->prox;
	l->last->itens = d;
	l->last->prox = NULL;	
}

void Linsere2LC(Lista2 *l,Itens2 d){
	l->last->prox = (Bloco2*) malloc (sizeof(Bloco2));
	l->last = l->last->prox;
	l->last->itens = d;
	l->last->prox = NULL;
	l->qnt++;
}

void Linsere3LC(Lista3 *l,Itens3 d){
	l->last->prox = (Bloco3*) malloc (sizeof(Bloco3));
	l->last = l->last->prox;
	l->last->itens = d;
	l->last->prox = NULL;
}

void LImprimi1LC(Lista1 *l){
	Bloco1 *aux;
	aux = l->first->prox;
	char nomeProduto[10];
		
	while(aux!=NULL){
		printf("Produto: %s\n",aux->itens.produto);
		aux = aux->prox;
	}
}

void AdicionaProdutoLC(Lista1 *l){
	
	Itens1 item;
	int valida=0, op;	
		
	do{
		printf("\t CADASTRO PRODUTO\n\n");
		printf("Insira o nome do produto: ");
		scanf("%s",item.produto);
		printf("Insira o codigo do produto [%s]: ",item.produto);
		scanf("%d",&item.id);
		printf("Insira a quantidade disponivel do produto [%s]: ",item.produto);
		scanf("%d",&item.quant);
		Linsere1LC(l,item);
		printf("\n1 - CADASTRAR NOVO PRODUTO\n2 - SAIR\nSeleciona uma opcao: ");
		scanf("%d",&op);
		if(op==2)
			valida++;	
		system("cls||clear");
	}while(!valida);
}

void AdicionaMercadoLC(Lista2 *l){

	Itens2 item;
	int valida=0, op;
	
	do{
	printf("\t CADASTRO MERCADO\n\n");
	printf("Nome do mercado: ");
	scanf("%s",item.mercado);
	printf("Codigo do mercado [%s]: ",item.mercado);
	scanf("%d",&item.id);
	printf("\n1 - CADASTRAR NOVO MERCADO\n2 - SAIR\nSeleciona uma opcao: ");
	scanf("%d",&op);
	Linsere2LC(l,item);
	if(op==2)
		valida++;	
	system("cls||clear");
	}while(!valida);
}

void AdicionaPrecoLC(Lista3 *l3,Lista2 *l2,Lista1 *l1){

	int op;
	char mercadoEscolha[10];
	char produtoEscolha[10];
	Bloco2 *aux;
	Itens3 item;
	Bloco1 *aux1;
	int i,cont=0;
	int mercado=0,produto=0;
	
	printf("\tCADASTRO PRECO\n\n");
	do{
		i=1;
		aux = l2->first->prox;
		while(aux!=NULL){
			printf("%d - %s\n",i,aux->itens.mercado);
			aux = aux->prox;
			i++;
		}

		op=0;
		printf("Escolha um mercado: ");
		scanf("%d",&mercado);
		aux = l2->first->prox;
		for(cont=0;cont<mercado;cont++){
	 		item.mercado = aux->itens;
			aux = aux->prox;
		}
	
		system("cls||clear");
		
		do{
			op=1;
			aux1 = l1->first->prox;
			printf("\t Cadastro mercado [%s]\n\n",item.mercado.mercado);
			i=1;
			while(aux1!=NULL){
				printf("%d - %s\n",i,aux1->itens.produto);           
				aux1 = aux1->prox;
				i++;
			}	
			printf("Escolha um produto: ");
			scanf("%d",&produto);
	
			aux1 = l1->first->prox;
			for(cont=0;cont<produto;cont++){
			 	item.produto=aux1->itens; 
				aux1 = aux1->prox;
			}
			printf("\nInsira o preco de [%s]: ",item.produto);
			scanf("%f",&item.preco);
			Linsere3LC(l3,item);
			printf("\n1 - Adicionar mais um produto em [%s]\n2 - Escolher outro mercado\n3 - Sair\nEscolha uma opcao: ",item.mercado.mercado);	
			scanf("%d",&op);
			system("cls||clear");
		}while(op == 1);
	}while(op!=3);
	
}

void CarrinhoLC(Lista3 *l3,Lista2 *l2,Lista1 *l1){
	
	Bloco2 *aux2;
	Bloco1 *aux1;
	Bloco3 *aux3;
	int i=1,produto,cont,j,op;
	Itens1 escolhaP;
	Aux soma[l2->qnt];
	
	aux2 = l2->first->prox;
	for(j=0;j<l2->qnt;j++){
		soma[j].mercado = aux2->itens;
		soma[j].soma = 0;
		aux2 = aux2->prox;
	}
	
	do{
		i=1;
		printf("\tADICIONAR CARRINHO\n\n");
	
		aux1 = l1->first->prox;
		while(aux1!=NULL){ //WHILE PARA MOSTRAR OS PRODUTOS DISPONÍVEIS
			printf("%d - %s\n",i,aux1->itens.produto);           
			aux1 = aux1->prox;
			i++;
		}
			printf("\nEscolha um produto pra adicionar na sacola: ");	
			scanf("%d",&produto);
	
			aux1 = l1->first->prox;
			for(cont=0;cont<produto;cont++){ //FOR PARA ADICIONAR O PRODUTO ESCOLHIDO NA VARIAVEL
				escolhaP = aux1->itens; 
				aux1 = aux1->prox;
			}
	
			aux3 = l3->first->prox;
			while(aux3!=NULL){ //PERCORRER A LTSTA 3 PROCURANDO O PRODUTO
			
				if(escolhaP.id == aux3->itens.produto.id){ //CASO ENCONTRE O PRODUTO CADASTRADO NA LISTA 3 ENTRA
					for(j=0;j<l2->qnt;j++){          
						if(aux3->itens.mercado.id == soma[j].mercado.id){ //ENCONTRADO O PRODUTO, PROCURA EM QUAL MERCADO ESTA CADASTRADO 
							soma[j].soma = 	soma[j].soma + aux3->itens.preco; //ENCONTRANDO O PRODUTO, SOMA O PREÇO

						}
					}		
				}			
				aux3 = aux3->prox;
			}
			
			printf("\n1 - Adicionar mais um item\n2 - Finalizar compra\nEscolha uma opcao: ");
			scanf("%d",&op);
	}while(op!=2);
	
	Aux auxSoma;
	auxSoma = soma[0];
	for(j=1;j<l2->qnt;j++){
		if(soma[j].soma < auxSoma.soma)
			auxSoma = soma[j];
	}
	printf("aqui\n");
	printf("\n\nMERCADO MAIS BARATO PARA COMPRAR: %s\n",auxSoma.mercado);
	printf("PRECO: R$%.2f",auxSoma.soma);
}
