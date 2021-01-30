#include <iostream>
#include "node.h"
#include "dbgs.h"


Node::Node(char letter, Node* parent): 
	letter_(letter), parent_(parent) {
	if (parent == nullptr) level_ = 0;	
	else level_ = parent->getLevel() + 1;
}

Node::~Node() {
    for (auto n: children_) {
        delete n.second;
    }
    dbgs << "node with key '" << letter_ << "' is destructed" << std::endl;
}

Node* Node::addChild(char key) {
	dbgs << "adding child for key '" << key << "'" << std::endl;
	Node* ptr = new Node(key, this);
	auto child = children_.find(key);
	children_.insert({key, ptr});
	return ptr;
}

Node* Node::findChild(char key) { 
	dbgs << "finding child for key '" << key << "'" << std::endl;
	auto child = children_.find(key);
	if (child != children_.end()) {
        dbgs << '\t' << "found!" << std::endl;
		return child->second;
	} else {
        dbgs << '\t' << "not found!" << std::endl;
		return nullptr;
	}
}

void Node::printKey(std::ostream& os /* = std::cout */) const {
	for (unsigned int i = 1; i < level_; i++) {
		os << '\t';
	}
    if (letter_) {
        os << letter_ << std::endl;
    } else {
        os << "\\0" << std::endl;
    }
}
