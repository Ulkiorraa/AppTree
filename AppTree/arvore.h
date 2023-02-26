#pragma once
#include "node.h"
#include <queue>
#include <stack>
using namespace std;

class arvore
{
	public:
		node* raiz;
		int tamanho; //guarda quantidade de nós da árvore
		arvore();
		~arvore();
		void visitar(node *ponteiro);
		bool vazia();
		void inserir(int item); // a implementar
		void inserir(vector<int> item);
		void imprimirLargura(); // a implementar
		void imprimirProfundidadePre();
		void imprimirProfundidadeIn();
		void imprimirProfundidadePos1pilha();
		void imprimirProfundidadePos2pilha();
		void mostraArvore();
		void imprimirMaxMin(); // a implementar
		void apagarNos(node* ponteiro);
		void apagarArvore();
		int getTamanho();
};
