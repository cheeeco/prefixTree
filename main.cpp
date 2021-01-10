#include <iostream>

#include "node.h"
#include "trie.h"

int main() {
	Trie test_trie;
	test_trie.insert("ab");
	test_trie.insert("ad");
	test_trie.drawTrie();
	return 0;
}
