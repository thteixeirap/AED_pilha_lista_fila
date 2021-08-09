```bash
Projeto feito com o DevC++ 5.11 / Windowns 10 64x
```


#                      LISTA|PILHA|FILHA


##  1)A

- Programa criado utilizando a estrutura LISTA
- Criar uma lista A com 100 números aleatórios par e uma LISTA B com 100 números aleatórios impar
- Concatenar essas lista unindo listaA e listaB mantendo as posições
- Ex: {{L1[0], L2[0]},{L1[1], L2[1]}, . . . , {L1[99], L2[99]}}


Markdown is a lightweight markup language based on the formatting conventions
that people naturally use in email.
As [John Gruber] writes on the [Markdown site][df1]

### Construção

1) Inicialmente no main criase a lista A, que armazenará os números pares, a lista b que recebera os números impares e a lista de concatenação.

2) Usando a função de iniciação padrão de uma lista FLVazia(Lista *l), iniciasse as lista adicionando o bloco de memoria a ser armazenado futuramente.

3) Utilizando a função (rand() % 100), iremos gerar os números aleatórios para serem adicionado nas listas dentro as funções PreencheListaPar(Lista *l) e PreencheListaImpar(Lista *l).

4) Com as duas lista criadas, chama-se a função LConcatena(&listaC,&listaA,&listaB). No qual é usada uma lista com uma struct que armazena dois inteiros em 2 variáveis, juntando assim os valores de listaA e listaB das mesmo posições em uma mesma variavel struct.

###### Exemplo struct lista

```sh
struct Item{
	int dado;
};
struct Lista{
	int quantid;
	Item item[MAXTAM];
};
```
###### Exemplo struct lista Concatenada
```sh
struct ItemC{
	int dadoL1;
	int dadoL2;
};
struct Concatena{
	int quantid;
	ItemC item[MAXTAM];
};
```
##  1)B

### Construção

1) Programa criado utilizando Lista
2) Cria-se duas listas com uma struct de armazena um vetor de inteiros com 3 posições
3) Listas iniciados no main com a função padrao de Lista FLVazia(Lista *l);
4) Na função PreencheLista(Lista *l) logo iniciado apos a criação da lista, utiliza-se da função (rand() % 13) para armazenar os valores no vetor da struct das listas. Valores esses aleatórios entre 1 e 13;
5) Logo após, é criado um outro número aleatório, entre 1 e 13, recebido na variável num. 
6) Em seguida, a função SubtraiLista() uni os valores iguais dos vetores das duas listas, ou seja {{L1[0], L2[0]}, {L1[1], L2[1]}, {L1[2], L2[2]}}. e subtrai dessas duplas o valor de num ateriormente criado.
7) A função VerificaListaVencedora(&l1,&l2) pega os valores dessas lista apos a subtração de num e soma, a lista que tiver o maior valor vence.


## 1C

- Programa criado utilizando a estrutura LISTA
- Criação de 3 Lista diferentes 

### Construção
1) Foi realizada a criação de 3 lista com structs diferentes
2) Lista1 armazena uma string para adicionar o nome do produto, um int para o identificador e um outro para a quantidade
3) Lista2 armazena uma string para adicionar o nome do mercado e um int para o identificador
4) Lista3 adiciona a struct da lista1 com dados do produto, adiciona a struct da lista2 com os dados do produto e um float para adicionar o valor do produto;

## Funcionalidade

1) Primeiro com a função AdicionaProduto(&lista1), ocorre a adição de todos os produtos, informando o nome, a identidicação e a quantidade. Usando um while para a opção de sair(No qual ira levar para adicionar o mercado), ou a função de adicionar novamente outro produto.
2) Logo após todo o incremento dos produtos, ocorre a adição dos mercados, com a adição do nome e do identificador, utilizando um while para a opção de sair e de adicionar novamente outro mercado
3) Após adicionar esses dados, iniciasse a função de adicionar preço, em que inicialmente aparece um menu com todos os produtos.Logo a escolha do produto, seleciona-se em qual mercado esse produto será cadastrado e seguindo qual valor nesse mercado o produto terá.
4) Na função de cadastro de preço, é utilizado um while no qual apos a ação apresentará um menu em que oferece a possibilidade de adicionar outro produto nesse mercado, escolher outro mercado, ou sair.
5)Escolhendo sair, aparece a opção carrinho no qual o usuário escolhe quais produtos ele deseja comprar, no qual será somados entre todos os mercados essas escolhas e apresentado qual mercado terá o menor preço dessa compra.

# Pilha

## 2A
- Programa criado utilizando a estrutura PILHA
- Identificar erros nos parenteses na equação

### Construção

1) O programa é iniciado com uma equação modelo "(2+7)5)8*9)(7/9(3-7"
2) Inicialmente no main iniasse uma Pilha com a função padrao FPVazia();
3) A função tokeniza() terá como parametro o tamanho da equação e qual é essa equação.

##### Função Tonekiza
```sh
void Tokeniza(const int size,Pilha *p,char equation[size]){
	Item item;
	int i;
	for(i=0;i<size;i++){
		if(equation[i] == '('){
			item.val = equation[i];
			Push(p,item);
			Confere(1,p);
		}else if(equation[i] == ')'){
			item.val = equation[i];
			Push(p,item);
			Confere(2,p);
		}
	}
}
```
- Explicando função Tokeniza

O for irá varrer toda a equação, identidicando sempre quando houver uma abertura ou fechamento de parentes. Ocorrendo uma dessa situações, ocorre o empilhamentos dessa parenteses e a chamanda da função Confere.

##### Função Confere

```sh
void Confere(int op,Pilha *p){
	
	if(p->cont.openClose <= 0 && op == 2){ //UM FECHADO SEM UM ABERTO DE PAR
		printf("ERRO DE PARENTESES NA EQUACAO!\n");
		exit(0);
	}else if(p->cont.openClose > 0 && op == 1){ //ABERTURA QUANDO CONT ZERADO
		p->cont.openClose++;
	}else if(p->cont.openClose >= 0 && op == 2){//
		p->cont.openClose--;
	}	
}
```
- Explicando função Confere

Se o char recebido for '(', ocorre a soma de +1 na variável de verificação, caso char recebido for ')' ocorre o decremento de -1 nessa variavél. Caso verficado um ')' e, a variavel de verificação esteja em 0, significa o fechamento de uma parenteses em uma aberta para anular. O programa ja printa o erro e termina o programa. 

4) Não ocorrendo o erro de parenteses fechada sem uma aberta para anular, o iniciasse a função Valida, na qual identifica erro de parenteses abertas sem fechar, na qual verifica se a função valida esta em 0 ou >0.

## 2B
- Programa criado utilizando a estrutura PILHA
- Criação de uma Pilha dinâmica A e a transferencia dessa pilha pra uma outro pilha B

### Construção 

1) Criasse duas pilhas no main, iniciando-as com a função padrao VPVazia()
2) Logo apos, inicia a função de preenchimento da Pilha

#### Função de preencher pilha

```sh
void PreenchePilha(Pilha *p){
	p->qnt =0;
	Item d;
	int i;
	srand(time(NULL));
	int op = 0;

	do{
		printf("\nDigite um inteiro: ");
		scanf(" %d",&d.val);
		printf("\n");
		Push(p,d);
		p->qnt++;
		PImprime(p);
		printf("\n\n 1 - Adiciona Valor\n 2 - Sair ");
		scanf("%d",&op);
		//system ("cls||clear");
	}while(op!=2);
	system ("cls||clear");
	printf("\n - Pilha A criada\n");
}
```

3) Com a pilha A já criada, é inicada a funçaõ de transferencia para a pilha B, respeitando a ordem da pilha A

#### Função de tranferência da Pilha
```sh
void TransferePilha(Pilha *p1,Pilha *p2){
	
	Bloco *aux ;
	aux = p1->top;
	
	int i = 1;
	while(p1->qnt > 0){
		if(i==p1->qnt){
			i=1;
			Push(p2,aux->dado);
			aux = p1->top;
			p1->qnt--;
		}
		else{
			aux = aux->prox;
			i++;	
		}
	}
	printf("\n\n - Pilha transferida de A para B");
}
```
- Explicando TransferePilha()

É criado um único auxiliar como assim passado no exercício. A struct da pilha contem uma variavel q informa o tamanho da pilha, no qual é utilizado para varrer toda extensão da mesma. A medida que ocorre o loop no for, ocorre o Push para a pilhaB, informando o ultimo valor da pilha A, no qual a cada loop decrementa -1 parando assim quando chegar em >0. Portanto é inserido na Pilha B do ultimo ate o primeiro valor da Pilha A, respeitando assim as posições de B.

## 2C

- Criação de lista MAXTAM 20 com números aleatórios
- Utilizado a  função totiente de Euler para encontrar o valor de (phi)

### Funcionalidade

1) É criada no main uma pilha inciada com a função padrao FPVazia();
2) É criada uma função para o preenchimento dessa pilha
```sh
void PreenchePilha(Pilha *p){
	int i=0;
	int num;
	Item d;
	while(i<MAXTAM){
		num = rand() % 100;
		if(num!=0) {
			d.val= num;
			PUSH(p,d);
			i++;
		}
	}
	printf("Lista Criada");
}
```
- Explicando PreenchePilha
Foi utilizada o recurso rand()%100 para adicionar os valores aleatórios (1 a 100), no qual sempre quando passar pela condição de não ser nulo irá adicionar esse valor na pilha e incrementar +1 na variavel de validação, ate ser maior que o MAXTAM e sair do loop, concluindo o preenchimento.

3) Após essa criação, a pilha é enviada para a função totiente, na qual calculará o valor de phi para cada valor dessa pilha e exibirá na tela.

#### Função matemática para obter (phi)
```sh
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
```
## 4)

- Foi usado uma lógica de atendimento de pacientes em um hospital/clinica
- É pensado na fila como um de atendimento normal, no qual a ordem é de chegada
- A lista foi utilizada para organizar o atendimento, sendo ele preferencial por idade
- Após o processo de organização por idade, ocorre a incrementação do relatorio, no qual será feito e adicionado em um pilha
- A Pilha foi pensada como um armazenamento de arquivos, em que o mais antigos ficam mais ao fundo.

#### Structs importantes no processo 

```sh
struct Paciente{
	char nome[20];
	int idade;
};
```
```sh
struct Relatorio{
	Paciente paciente;
	char data[10];
	char prontuario[100];
};
```

## Funcionalidade
1) Em um primeiro momento ocorre o cadastro de pacientes (nome e idade), sendo eles adicionados em uma fila
2) Selecionando a opção de organizar idade, é chamada a função correspondente.

```sh
void OrganizaIdade(Fila *f,Lista *l){
	
	int idades[f->qtd];
	idades[0] = f->first->prox->paciente.idade;
	int menor;
	Bloco *aux;
	aux = f->first->prox->prox;
	int i=1,j,k,p;
	
	while(aux != NULL){
			
		idades[i] = aux->paciente.idade;
		k=i;
		p=i-1;
		for(j=i-1;j>=0;j--){	
			if(idades[p] < idades[k]){
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
				Linsere(l,aux->paciente);
			}
			aux = aux->prox;
		}
	}
}
```
- Explicando OrganizaIdade

É criado um vetor com a quantidade de pacientes informada na variavel contadora pertecente a struct da Fila. Dentro do While, é criado uma comparação para acrescentar a variavel idade dentro desse vetor. Essa adição é realizada sempre comparado os valores ja dentro do vetor com a nova informação adicionada, fazendo assim o maior valor(idade) ser sempre adicionado decrescente. 

Ponto a ser mellhorado: É desejado realizar essa organização de idade sem o auxilio de um vetor e diretamente utilizando a lista com uma função comparativa. 

Após o vetor pronto, é utilizado um for para adicionar esses pacientes na lista, que apresentará as idades dos pacientes de forma decrescente.

3) Após a organização de idade, iniciasse o processo de atendimento, no qual sera adicionado a data e o prontuário desse paciente e em que assim sendo feito ira ser adicionado na Pilha de processos.
