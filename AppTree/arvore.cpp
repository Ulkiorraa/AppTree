#include "arvore.h"

arvore::arvore()
{
	raiz = NULL;
	tamanho = 0;
}

arvore::~arvore()
{
	apagarArvore();
	raiz = NULL;
	tamanho = NULL;
}

void arvore::visitar(node* ponteiro)
{
	cout << ponteiro->dado << " ";
}

bool arvore::vazia()
{
	return raiz == NULL;
	// return tamanho==0;
}

void arvore::inserir(int item)
{
	node* novo = new node(item, NULL, NULL);
	node* aux;
	bool colocou = false;
	if (vazia()) 
	{
		raiz = novo;
		novo = NULL;
		delete novo;
		tamanho++;
	}
	else
	{
		aux = raiz;
		while (colocou == false)
		{
			if (novo->dado > aux->dado)
			{
				if (aux->direita == NULL)
				{
					aux->direita = novo;
					colocou = true;
				}
				else
				{
					aux = aux->direita;
				}
			}
			else
			{
				if (novo->dado < aux->dado)
				{
					if (aux->esquerda == NULL)
					{
						aux->esquerda = novo;
						colocou = true;
					}
					else
					{
						aux = aux->esquerda;
					}
				}
			}
		}
		novo = aux = NULL;
		delete novo;
		delete aux;
		tamanho++;
	}
}

void arvore::inserir(vector<int> item)
{
	for (vector<int>::iterator it = item.begin(); it != item.end(); it++)
	{
		inserir(*it);
	}
}

void arvore::imprimirLargura()
{
	if (vazia())
	{
		cout << "Sua arvore esta vazia";
	}
	else
	{
		cout << "Impressão por largura { ";
		queue <node*> fila;		
		fila.push(raiz);
		while (!fila.empty())
		{
			node* aux = fila.front();
			fila.pop();
			visitar(aux);
			if (aux->esquerda != NULL)
			{
				fila.push(aux->esquerda);
			}
			if (aux->direita != NULL)
			{
					fila.push(aux->direita);
			}
			aux = NULL;
			delete aux;
		}
		cout << "}\n";
	}
}

void arvore::imprimirMaxMin()
{
	if (vazia())
	{
		cout << "Sua arvore esta vazia";
	}
	else
	{
		node* aux;
		aux = raiz;
		while (aux->direita != NULL)
		{
			aux = aux->direita;
		}
		cout << "Maior item da arvore é " << aux->dado << ".\n";
		aux = raiz;
		while (aux->esquerda != NULL)
		{
			aux = aux->esquerda;
		}
		cout << "Menor item da arvore é " << aux->dado << ".\n";
		aux = NULL;
		delete aux;
	}
}

void arvore::apagarNos(node* ponteiro)
{
	if (vazia())
	{
		cout << "Sua arvore esta vazia";
	}
	else
	{
		queue <node*> fila;
		fila.push(ponteiro);
		while (!fila.empty())
		{
			node* aux = fila.front();
			fila.pop();
			if (aux->esquerda != NULL)
			{
				fila.push(aux->esquerda);
			}
			if (aux->direita != NULL)
			{
				fila.push(aux->direita);
			}
			delete aux;
		}
	}
}

void arvore::mostraArvore()
{
	if (vazia())
	{
		cout << "Sua arvore esta vazia";
	}
	else
	{
		cout << "Arvore por camadas:\n";
		queue <node*> filaAtual, proxima;
		filaAtual.push(raiz);
		while (!filaAtual.empty())
		{
			node* aux = filaAtual.front();
			filaAtual.pop();
			if (aux)
			{
				visitar(aux);
				proxima.push(aux->esquerda);
				proxima.push(aux->direita);
			}
			if (filaAtual.empty())
			{
				cout << endl;
				swap(filaAtual, proxima);
			}
			aux = NULL;
			delete aux;
		}
	}
}

void arvore::imprimirProfundidadePre()
{
	if (vazia())
	{
		cout << "Sua arvore esta vazia";
	}
	else
	{

		cout << "Impressão por profundidade(pré-ordem) { ";
		stack <node*> pilha;
		pilha.push(raiz);
		while (!pilha.empty())
		{
			node* aux = pilha.top();
			pilha.pop();
			visitar(aux);
			if (aux->direita != NULL)
			{
				pilha.push(aux->direita);
			}
			if (aux->esquerda != NULL)
			{
				pilha.push(aux->esquerda);
			}
			aux = NULL;
			delete aux;
		}
		cout << "}\n";
	}
}

void arvore::apagarArvore()
{
	apagarNos(raiz);
	raiz = NULL;
	tamanho = 0;
}

int arvore::getTamanho()
{
	return tamanho;
}

void arvore::imprimirProfundidadeIn()
{
	if (vazia())
	{
		cout << "Sua arvore esta vazia";
	}
	else
	{

		cout << "Impressão por profundidade(in-ordem) { ";
		stack <node*> pilha;
		node* aux = raiz;
		do
		{
			while (aux != NULL)
			{
				pilha.push(aux);
				aux = aux->esquerda;
			}
			if (!pilha.empty())
			{
				aux = pilha.top();
				pilha.pop();
				visitar(aux);
				aux = aux->direita;
			}
		} while (!pilha.empty() || aux != NULL);
		aux = NULL;
		delete aux;
		cout << "}\n";
	}
}

void arvore::imprimirProfundidadePos1pilha()
{
	if (vazia())
	{
		cout << "Sua arvore esta vazia";
	}
	else
	{
		cout << "Impressão por profundidade(pós-ordem com 1 pilha) { ";
		stack <node*> pilha;
		node* aux = raiz;
		do
		{
			while (aux != NULL)
			{
				if (aux->direita != NULL)
				{
					pilha.push(aux->direita);
				}
				pilha.push(aux);
				aux = aux->esquerda;
			}
			aux = pilha.top();
			pilha.pop();
			if (!pilha.empty())
			{
				if (aux->direita != NULL && pilha.top() == aux->direita)
				{
					pilha.pop();
					pilha.push(aux);
					aux = aux->direita;
				}
				else
				{
					visitar(aux);
					aux = NULL;
				}
			}
			else
			{
				visitar(aux);
			}
		} while (!pilha.empty());
		aux = NULL;
		delete aux;
		cout << "}\n";
	}
}

void arvore::imprimirProfundidadePos2pilha()
{
	if (vazia())
	{
		cout << "Sua arvore esta vazia";
	}
	else
	{

		cout << "Impressão por profundidade(pós-ordem com 2 pilhas) { ";
		stack <node*> pilha1, pilha2;
		node* aux = raiz;
		pilha1.push(aux);
		while (!pilha1.empty())
		{
			aux = pilha1.top();
			pilha1.pop();
			pilha2.push(aux);
			if (aux->esquerda != NULL)
			{
				pilha1.push(aux->esquerda);
			}
			if (aux->direita != NULL)
			{
				pilha1.push(aux->direita);
			}
		}
		while (!pilha2.empty())
		{
			aux = pilha2.top();
			pilha2.pop();
			visitar(aux);
		}
		aux = NULL;
		delete aux;
		cout << "}\n";
	}
}
