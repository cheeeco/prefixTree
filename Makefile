all: trie trie-debug

trie: *.cpp *.h
	c++ $(CXXFLAGS) *.cpp -o $@

trie-debug: *.cpp *.h
	c++ $(CXXFLAGS) *.cpp -DANALYZE -o $@

clean:
	rm -f trie trie-debug
