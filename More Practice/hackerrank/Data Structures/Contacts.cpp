#include <iostream>
#include <cstring>
#define ALPH_SIZE 26
using namespace std;

class TrieNode{
public:
	TrieNode **next;	
    int count;
	TrieNode(){
		next = new TrieNode*[ALPH_SIZE];		
        count = 0;
		for(int i=0; i<ALPH_SIZE; ++i)
			next[i] = NULL;
	}
};

class Trie{
	TrieNode *root;		
public:
	Trie();	
	void insert(string);
	int search(string);	
};

Trie::Trie(){
	root = new TrieNode;	
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
        cursor->count = cursor->count + 1;
	}	
}

int Trie::search(string key){
	int len, index, count = 0;
	len = key.length();
	TrieNode *cursor = root;
	
	for(int i=0; i<len; ++i){
		index = int(key[i] - 'a');
		if(!cursor->next[index])
			return 0;        
		cursor = cursor->next[index];
	}
	
    return cursor->count;
}


int main(){

    int n;    cin >> n;
    Trie trie;
    while(n--){
        string command, word;
        cin >> command >> word;
        if(command == "add"){
            trie.insert(word);
        } else {
            cout << trie.search(word) << endl;
        }
    }
	return 0;
}
