#ifndef NODE_INTERFACE
#define NODE_INTERFACE

#include <unordered_map>

class Node 
{
private:
	char letter_;
	unsigned int level_;
	Node* parent_;
	std::unordered_map<char, Node*> children_;
	
public:
	Node(char letter, Node* parent);
	
//	~Node();
	
	unsigned int getLevel() { return level_; }
	char getKey() { return letter_; }
	Node* getParent() { return parent_; }
	std::unordered_map<char, Node*> getChildren() { return children_; }
		
	Node* addChild(char key);
	
	Node* findChild(char key);
	
	void printKey();
};

#endif
