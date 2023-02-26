#include "node.h"

node::node()
{
	dado = NULL;
	esquerda = NULL;
	direita = NULL;
}

node::node(int item, node* ptr, node *ptr2)
{
	dado = item;
	esquerda = ptr;
	direita = ptr2;
}

