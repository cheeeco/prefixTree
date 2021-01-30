#ifndef NODE_INTERFACE
#define NODE_INTERFACE

#include <unordered_map>
#include <iostream>

class Node final
{
private:
	char letter_;
	unsigned int level_;
	Node* parent_;
	std::unordered_map<char, Node*> children_;
	
public:
	Node(char letter, Node* parent);
	~Node();
    
    Node(const Node& other) = delete;
    Node(Node&& other) = delete;
    Node& operator =(const Node& other) = delete;
    Node& operator =(Node&& other) = delete;

	unsigned int getLevel() const { return level_; }
	char getKey() const { return letter_; }
	Node* getParent() { return parent_; }
	const std::unordered_map<char, Node*>& getChildren() const { return children_; }
		
	Node* addChild(char key);
	
	Node* findChild(char key);
	
	void printKey(std::ostream& os = std::cout) const;
};

#endif
