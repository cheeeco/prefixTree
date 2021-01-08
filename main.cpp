#include <iostream>

#include "node.h"
#include "trie.h"

int main() {
	Trie test_trie;
	test_trie.insert("ab", sizeof("ab"));
	test_trie.insert("ad", sizeof("ad"));
	test_trie.drawTrie();
	return 0;
}