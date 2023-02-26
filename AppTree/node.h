#pragma once
#include <iostream>
class node
{
public:
	int dado;
	node* esquerda;
	node* direita;

	//Construtor: usado para criar um novo node 
	node();
	node(int item, node* ptr, node* ptr2);
};

