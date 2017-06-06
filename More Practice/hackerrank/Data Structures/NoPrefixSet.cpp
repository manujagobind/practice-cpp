#include <iostream>
#include <cstring>
#define ALPH_SIZE 26
using namespace std;

class TrieNode{
public:
	TrieNode **next;	
    bool leaf;    
    int count;
	TrieNode(){
		next = new TrieNode*[ALPH_SIZE];		
        leaf = false;
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
	bool search(string);	
    int search2(string);
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
    
    cursor->leaf = true;
}

bool Trie::search(string key){
	int len, index, count = 0;
	len = key.length();
	TrieNode *cursor = root;
	
	for(int i=0; i<len; ++i){
		index = int(key[i] - 'a');
		if(!cursor->next[index])
			return false;        
		cursor = cursor->next[index];
	}
	
    return cursor != NULL && cursor->leaf;
}

int Trie::search2(string key){
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
    string *words = new string[n];    
    bool flag = true;    
    Trie trie;    
    for(int i=0; i<n; i++){        
        cin >> words[i];   
        int len = words[i].length();
                
        // Smaller strings inserted first
        for(int j=1; j<=len; ++j){
            string sub = words[i].substr(0, j);                        
            if(trie.search(sub)){
                flag = false;
                cout << "BAD SET\n" << words[i] << endl;
                break;
            }        
        }        
                
        if(flag){      
            // Larger strings inserted first
            if(trie.search2(words[i])){
                cout << "BAD SET\n" << words[i] << endl;
                flag = false;
                break;
            }
            trie.insert(words[i]);            
        }  
        
        if(!flag){
            break;
        }
    }
    if(flag)
        cout << "GOOD SET\n";
	return 0;
}
