#include <iostream>

#include "trie.h"

Trie::Trie() {
	vertex_ = new Node('\0', nullptr);
	std::cout << "trie constructed" << std::endl;
}

Trie::~Trie() {
    delete vertex_;
    std::cout << "trie destructed" << std::endl;
}

//prefix - null-terminated string
Node* Trie::insert(const char* prefix) {
    std::cout << "inserting prefix \"" << prefix << "\"" << std::endl;
	Node* ptr = vertex_;
	Node* child = nullptr;
    int i = 0;

	while (prefix[i] != '\0') {
		child = ptr->findChild(prefix[i]);
		if ( child == nullptr ) {
			ptr = ptr->addChild(prefix[i]);
		}
		else {
			ptr = child;
		}
        i++;
    }
	return ptr;
	
}

//prefix - null-terminated string
Node* Trie::find(const char* prefix) {
    std::cout << "finding prefix \"" << prefix << "\"" << std::endl;
    Node* ptr = vertex_;
    int i = 0;
	while (prefix[i] != '\0') {
		if ( (ptr = ptr->findChild(prefix[i])) == nullptr ) {
			std::cout << "Prefix " << prefix << " doesn't exist" << i << std::endl;
			return nullptr;
		}
        i++;
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
