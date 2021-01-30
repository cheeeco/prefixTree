#include <iostream>
#include <cstring>

#include "trie.h"
#include "dbgs.h"

Trie::Trie() {
	vertex_ = new Node('\0', nullptr);
	dbgs << "trie constructed" << std::endl;
}

Trie::~Trie() {
    delete vertex_;
    dbgs << "trie destructed" << std::endl;
}

//prefix - null-terminated string
Node* Trie::insert(const char* prefix) {
    dbgs << "inserting prefix \"" << prefix << "\"" << std::endl;
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
    dbgs << "finding prefix \"" << prefix << "\"" << std::endl;
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

std::string Trie::getPrefix(Node* ptr) const {
	unsigned int length = ptr->getLevel();	//длина префикса
    std::string prefix;
    prefix.resize(length);
	
	for (unsigned int i = length; i > 0; i--) {
		prefix[i - 1] = ptr->getKey();
		ptr = ptr->getParent();	//когда дойдем до вершины, ptr == nullptr
	}
	return prefix;
}

void Trie::decayStr(const char* str) {
	long int length = std::strlen(str);
    long int it = 0;
    Node* ptr = vertex_;
    Node* a;
    
    while (it < length) {
    	if ((a = ptr->findChild(str[it])) != nullptr) {
    		ptr = a;
    		it++;
    	} else {
			//тут надо делать вывод номера
			ptr->addChild(str[it]);    	
			ptr = vertex_;
    	}   
    }
}

void Trie::init() {
	for (char i = 65; i <=90; i++) {
		vertex_->addChild(i);
	}
}

void Trie::drawTrie(Node* ptr, std::ostream& os /* = std::cout */) const {
	ptr->printKey(os);
	for (auto& n : ptr->getChildren()) {
		drawTrie(n.second);
	}
}

void Trie::drawTrie(std::ostream& os /* = std::cout */) const {
	drawTrie(vertex_, os);
}
