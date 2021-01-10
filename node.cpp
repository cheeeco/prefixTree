#include <iostream>
#include "node.h"


Node::Node(char letter, Node* parent): 
	letter_(letter), parent_(parent) {
	if (parent == nullptr) level_ = 0;	
	else level_ = parent->getLevel() + 1;
}

Node::~Node() {
    for (auto n: children_) {
        delete n.second;
    }
    std::cout << "node with key '" << letter_ << "' is destructed" << std::endl;
}

Node* Node::addChild(char key) {
	std::cout << "adding child for key '" << key << "'" << std::endl;
	Node* ptr = new Node(key, this);
	auto child = children_.find(key);
	children_.insert({key, ptr});
	return ptr;
}

Node* Node::findChild(char key) { 
	std::cout << "finding child for key '" << key << "'" << std::endl;
	auto child = children_.find(key);
	if (child != children_.end()) {
        std::cout << '\t' << "found!" << std::endl;
		return (*child).second;
	}
	else {
        std::cout << '\t' << "not found!" << std::endl;
		return nullptr;
	}
}

void Node::printKey() {
	for (unsigned int i = 1; i < level_; i++) {
		std::cout << '\t';
	}
    if (letter_) {
        std::cout << letter_ << std::endl;
    } else {
        std::cout << "\\0" << std::endl;
    }
}
