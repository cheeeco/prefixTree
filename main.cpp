#include <iostream>
#include <cstdio>

#include "node.h"
#include "trie.h"

int main() {
	
	Trie test_trie;
	test_trie.init();
	char str[] = "TOBEORNOTTOBEORTOBEORNOT";
	test_trie.decayStr(str);
	test_trie.drawTrie();
	return 0;
}
