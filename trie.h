#ifndef TRIE_INTERFACE
#define TRIE_INTERFACE

/* Реализуем функции:
 * поиск (возвращает Node*, если нашло, иначе NULL)
 * инсерт (возвращает Node*, если вставили удачно, иначе NULL)
 * getPrefix(Node* ptr) (возвращает префикс для ptr)
 * getKey(Node* ptr) (возвращает префикс)
 * 
*/
#include "node.h"

class Trie
{
private:
	Node* vertex_;
public:
	Trie();
	~Trie();

    Node* getVertex() { return vertex_; }
	
	Node* insert(const char* prefix);
	Node* find(const char* prefix);
	
	char* getPrefix(Node* ptr);
	
	void drawTrie();
	void drawTrie(Node* ptr);
};

#endif
