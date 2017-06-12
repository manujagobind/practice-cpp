#include <iostream>
#define ALPH_SIZE 26
using namespace std;

int max_priority = -1;

class TrieNode{
public:
    TrieNode **next;
    bool leaf;
    int priority;
    int count;
    TrieNode();
    bool isEmpty();
    inline bool isLeaf();
};

TrieNode::TrieNode(){
    next = new TrieNode*[ALPH_SIZE];
    leaf = false;
    priority = count = 0;
    for(int i=0; i<ALPH_SIZE; ++i)
        next[i] = NULL;
}

bool TrieNode::isEmpty(){
    for(int i=0; i<ALPH_SIZE; ++i)
        if(next[i])
            return false;
    return true;
}

inline bool TrieNode::isLeaf(){
    return leaf;
}

class Trie{
    TrieNode *root;
    int index(char);
public:
    Trie();
    void insert(string, int);
    TrieNode* search(string);
    void priority(TrieNode*);
};

Trie::Trie(){
    root = new TrieNode();
}

int Trie::index(char a){
    return int(a - 'a');
}

void Trie::insert(string key, int priority){
    int len, id;
    len = key.length();
    TrieNode *cur = root;
    
    for(int i=0; i<len; ++i){
        id = index(key[i]);
        if(!cur->next[id])
            cur->next[id] = new TrieNode();
        cur = cur->next[id];
        cur->count++;
    }
    
    cur->priority = priority;
    cur->leaf = true;
}

TrieNode* Trie::search(string key){
    int len, id;
    len = key.length();
    TrieNode *cur = root;
    
    for(int i=0; i<len; ++i){
        id = index(key[i]);
        if(!cur->next[id])
            return NULL;
        cur = cur->next[id];
    }
    
    return cur;
}

void Trie::priority(TrieNode* node){
    if(!node)
        return;
    if(node->isLeaf()){
        if(node->priority > ::max_priority)
            ::max_priority = node->priority;
    }
    for(int i=0; i<ALPH_SIZE; ++i){
        if(node->next[i])
            priority(node->next[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    int n, q, priority;
    string key;
    Trie trie;
    cin >> n >> q;
    while(n--){
        cin >> key >> priority;
        trie.insert(key, priority);
    }
    while(q--){
        cin >> key;
        ::max_priority = -1;
        trie.priority(trie.search(key));
        cout << ::max_priority << endl;
    }
    return 0;
}

