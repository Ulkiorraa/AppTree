# Trabalho de criação de Arvore Binaria.
>Nesse trabalho implementei arvore binaria e funções destintas para a mesma.

```c++
class arvore
{
	public:
		node* raiz;
		int tamanho; //guarda quantidade de nós da árvore
		arvore();
		~arvore();
		void visitar(node *ponteiro); //visita ponto atual da arvore
		bool vazia(); //verifica se árvore ta vasia
		void inserir(int item); // inseri um inteiro na árvore
		void inserir(vector<int> item); //função para inserir um vetor inteiro na árvore
		void imprimirLargura(); //Impressão por largura
		void imprimirProfundidadePre(); //Impressão por profundidade(pré-ordem)
		void imprimirProfundidadeIn(); //Impressão por profundidade(in-ordem)
		void imprimirProfundidadePos1pilha(); //Impressão por profundidade(pós-ordem com 1 pilha)
		void imprimirProfundidadePos2pilha(); //Impressão por profundidade(pós-ordem com 2 pilhas)
		void mostraArvore(); //mostra composição atual da árvore
		void imprimirMaxMin(); // imprime o maior e menor item da árvore
		void apagarNos(node* ponteiro); //apaga nó selecionado da árvore
		void apagarArvore(); //apaga a árvore
		int getTamanho(); //mostra o tamanho da árvore
};
```