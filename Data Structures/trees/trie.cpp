#include <iostream>
#include <cstring>
#define ALPH_SIZE 26
using namespace std;

class TrieNode{
public:
	TrieNode **next;
	bool leaf;
	TrieNode(){
		next = new TrieNode*[ALPH_SIZE];
		leaf = false;
		for(int i=0; i<ALPH_SIZE; ++i)
			next[i] = NULL;
	}
	~TrieNode(){
		delete next;
	}
	inline bool isLeaf(){
		return leaf;
	}
	bool empty(){
		for(int i=0; i<ALPH_SIZE; ++i)
			if(next[i])
				return false;
		return true;
	}
};

class Trie{
	TrieNode *root;
	int count;
	bool remove(TrieNode*, string, int, int);
	void deallocate(TrieNode*);
public:
	Trie();
	~Trie(){}
	void insert(string);
	bool search(string);
	void remove(string);
};

Trie::Trie(){
	root = new TrieNode;
	count = 0;
}

void Trie::insert(string key){
	int len, index;
	len = key.length();
	TrieNode *cursor = root;

	for(int i=0; i<len; ++i){
		index = int(key[i] - 'a');
		if(!cursor->next[index])
			cursor->next[index] = new TrieNode();
		cursor = cursor->next[index];
	}

	cursor->leaf = true;
	++count;
}

bool Trie::search(string key){
	int len, index;
	len = key.length();
	TrieNode *cursor = root;
	
	for(int i=0; i<len; ++i){
		index = int(key[i] - 'a');
		if(!cursor->next[index])
			return false;
		cursor = cursor->next[index];
	}
	return cursor != NULL && cursor->isLeaf();
}

void Trie::deallocate(TrieNode* node){
	delete node;
	node = NULL;
}

bool Trie::remove(TrieNode* node, string key, int level, int len){
	if(node){
		if(level == len){
			if(node->isLeaf()){				
				node->leaf = false;
				if(node->empty()){
					return true;
				}
				return false;
			}
		} else{
			int index = int(key[level] - 'a');
			if(remove(node->next[index], key, level+1, len)){
				deallocate(node->next[index]);
				return !node->isLeaf() && node->empty();
			}
		}
	}
	return false;
}

void Trie::remove(string key){
	(search(key) && key.length()>0)? remove(root, key, 0, key.length()) : cout << "Key not found!\n";
}

int main(){
	Trie trie;
	trie.insert("abcdef");
	trie.insert("abc");
	trie.insert("xyz");
	trie.remove("abc");
	cout << trie.search("ab") << endl;
	cout << trie.search("abc") << endl;
	cout << trie.search("abcdef") << endl;
	return 0;
}
