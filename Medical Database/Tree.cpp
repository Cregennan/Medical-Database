#include "Tree.h"
#include "Record.h"
#include "MedicalCard.h"
template class Tree<int>;
template class Tree<Record*>;
template class Tree<MedicalCard*>;
template <class T>
void Tree<T>::Add(unsigned int incoming_key, T value) {
	if (this->root == nullptr) {
		this->root = new Node(incoming_key, value);
	}
	else {
		Node* walker = this->root;

		while (true) {
			if (walker->key < incoming_key) {
				if (walker->left == nullptr) {
					walker->left = new Node(incoming_key, value);
					break;
				}
				else {
					walker = walker->left;
				}
			}
			else {
				if (walker->right == nullptr) {
					walker->right = new Node(incoming_key, value);
					break;
				}
				else {
					walker = walker->right;
				}
			}
		}
	}
}
template <class T>
T Tree<T>::Find(unsigned int incoming_key) {
	Node* walker = this->root;
	while (true) {
		if (walker == nullptr) {
			throw std::exception("Not Found Exception");
		}
		if (incoming_key == walker->key) {
			return walker->data;
		}
		else if (incoming_key > walker->key) {
			walker = walker->left;
		}
		else {
			walker = walker->right;
		}
	}

}
template <class T>
Tree<T>::Tree() {

}
template <class T>
Tree<T>::Node::Node(unsigned int key, T data) {
	this->key = key;
	this->data = data;
}
/*
template <class T>
void Tree<T>::Fill(std::vector<std::tuple<int,T*>> records) {
	while (!records.empty()) {
		HashConvertable* record = records.back();
		records.pop_back();
		this->Add(record->GetHash, record);
	}
}*/
