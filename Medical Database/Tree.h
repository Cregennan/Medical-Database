#pragma once
#include <stdio.h>
#include <string>	
#include <functional>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <stack>
#include <vector>
template <class T>
class Tree
{
	struct Node {
		unsigned int key = 0;
		T data = NULL;
		Node* left = nullptr;
		Node* right = nullptr;
		Node(unsigned int id, T data);
	};
	Node* root = nullptr;
public:
	Tree();
	void Add(unsigned int key, T value);
	T Find(unsigned int key);
	//void Fill(std::vector<std::tuple<int, T*>> records);



};

