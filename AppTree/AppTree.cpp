#include "arvore.h"

int main()
{
	setlocale(LC_ALL, ".utf-8");
	vector<int> v = { 10,5,20,1,7,33,2,30 }; //basta inserir aos numeros que quiser no vetor para criar a árvore.
	arvore t;
	t.inserir(v);
	t.imprimirLargura();
	cout << endl;
	t.imprimirProfundidadePre();
	cout << endl;
	t.imprimirProfundidadeIn();
	cout << endl;
	t.imprimirProfundidadePos1pilha();
	cout << endl;
	t.imprimirProfundidadePos2pilha();
	cout << endl;
	t.mostraArvore();
	t.imprimirMaxMin();
	cout << endl;
	cout << "tamanho da arvore é " << t.getTamanho();
	cout << endl;
	t.apagarArvore();
	t.imprimirLargura();
	cout << endl;
	cout << "tamanho da arvore é " << t.getTamanho();
	cout << endl << endl;
	system("pause");
	return 0;
}
