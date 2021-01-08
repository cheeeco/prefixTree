#include <iostream>

#include "trie.h"

Trie::Trie() {
	vertex_ = new Node('\0', nullptr);
	std::cout << "trie constructed" << std::endl;
}

Node* Trie::insert(char* prefix, unsigned int length) {
	Node* ptr = vertex_;
	Node* child = nullptr;
	for (unsigned int i = 0; i < length-1; i++) {
		child = ptr->findChild(prefix[i]);
		if ( child == nullptr ) {
			ptr = ptr->addChild(prefix[i]);
		}
		else {
			ptr = child;
		}
	}
	return ptr;
	
}

Node* Trie::find(char* prefix, unsigned int length) {	//sizeof(prefix) равен length
	Node* ptr = vertex_;
	for (unsigned int i = 0; i < length; i++) {
		if ( (ptr = ptr->findChild(prefix[i])) == nullptr ) {
			std::cout << "Prefix " << prefix << " doesn't exist" << i << std::endl;
			return nullptr;
		}
	}
	
	return ptr;
}

char* Trie::getPrefix(Node* ptr) {
	unsigned int length = ptr->getLevel();	//длина префикса
	char* prefix = new char[length + 1];
	prefix[length] = '\0';
	
	for (unsigned int i = length; i > 0; i--) {
		prefix[i - 1] = ptr->getKey();
		ptr = ptr->getParent();	//когда дойдем до вершины, ptr == nullptr
	}
	return prefix;
}

void Trie::drawTrie(Node* ptr) {
	ptr->printKey();
	for (auto n : ptr->getChildren()) {
		drawTrie(n.second);
	}
}

void Trie::drawTrie() {
	drawTrie(vertex_);
}