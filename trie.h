#ifndef TRIE_INTERFACE
#define TRIE_INTERFACE

/* Реализуем функции:
 * поиск (возвращает Node*, если нашло, иначе NULL)
 * инсерт (возвращает Node*, если вставили удачно, иначе NULL)
 * getPrefix(Node* ptr) (возвращает префикс для ptr)
 * 
*/
#include "node.h"
#include <string>

class Trie
{
private:
	Node* vertex_;
public:
	Trie();
	~Trie();

    Node* getVertex() { return vertex_; }
    std::string getPrefix(Node* ptr) const;
	
	Node* insert(const char* prefix);
	Node* find(const char* prefix);
	void decayStr(const char* str);
	
	void init();
	void drawTrie(std::ostream& os = std::cout) const;
	void drawTrie(Node* ptr, std::ostream& os = std::cout) const;
};

#endif
