#include "node.h"
#include <iostream>
Node::Node(char letter, Node* parent): 
	letter_(letter), parent_(parent) {
	if (parent == nullptr) level_ = 0;	
	else level_ = parent->getLevel() + 1;
}

//Node::~Node() {}

Node* Node::addChild(char key) {
	std::cout << "addChild(" << key << ")" << std::endl;
	Node* ptr = new Node(key, this);
	auto child = children_.find(key);
	children_.insert({key, ptr});
	return ptr;
}

Node* Node::findChild(char key) { 
	std::cout << "findChild(" << key << ")" << std::endl;
	auto child = children_.find(key);
	if (child != children_.end()) {
		return (*child).second;
	}
	else {
		return nullptr;
	}
}

void Node::printKey() {
	for (unsigned int i = 1; i < level_; i++) {
		std::cout << '\t';
	}
	std::cout << letter_ << std::endl;
}