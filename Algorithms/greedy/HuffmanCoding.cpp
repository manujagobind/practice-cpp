#include <bits/stdc++.h>
using namespace std;

class MinHeapNode{
public:
	char data;
	unsigned int freq;
	MinHeapNode *left, *right;
	MinHeapNode(char, unsigned int);
};

MinHeapNode::MinHeapNode(char data, unsigned int freq){
	this->data = data;
	this->freq = freq;
}

class Compare{
public:
	bool operator()(const MinHeapNode *left, const MinHeapNode *right){
		return left->freq > right->freq;
	}
};

class HuffmanTree{
	MinHeapNode *root;
	void print(MinHeapNode*, string) const;
	void destroy(MinHeapNode*);
public:
	HuffmanTree();
	~HuffmanTree();
	void print() const;
	void build(char[], int[], int);
};

HuffmanTree::HuffmanTree(){
	root = NULL;
};

void HuffmanTree::print(MinHeapNode *node, string str) const{
	if(node){
		if(node->data != '$')
			cout << node->data << ": " << str << endl;
		print(node->left, str + '0');
		print(node->right, str + '1');
	}
}

void HuffmanTree::print() const{
	print(root, "");
}

void HuffmanTree::destroy(MinHeapNode *node){
	if(node){
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

HuffmanTree::~HuffmanTree(){
	destroy(root);
	root = NULL;
}

void HuffmanTree::build(char data[], int freq[], int size){
	
	MinHeapNode *left, *right, *parent;
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, Compare> minHeap;
	
	for(int i=0; i<size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	while(minHeap.size() != 1){
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		
		parent = new MinHeapNode('$', left->freq + right->freq);
		parent->left = left;
		parent->right = right;

		minHeap.push(parent);
	}

	root = minHeap.top();
}

int main(){
	
	char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	int size = sizeof(data)/sizeof(data[0]);

	HuffmanTree huffman;

	huffman.build(data, freq, size);
	huffman.print();

	return 0;
}
