// Rearrange a given string such that no two adjacent letters are same

#include <bits/stdc++.h>
#define ALPH_SIZE 26
using namespace std;

class Key{
public:
	int freq;
	char ch;
	Key(int freq, char ch){
		this->freq = freq;
		this->ch = ch;
	}
	bool operator<(const Key &k) const{
		return this->freq < k.freq;
	}
};

void rearrange(string str){
	int len = str.length();

	int count[ALPH_SIZE] = {0};
	for(int i=0; i<len; ++i)
		++count[str[i]-'a'];

	priority_queue< Key > pq;
	for(char c='a'; c <= 'z'; ++c)
		if(count[c-'a'])
			pq.push( Key(count[c-'a'], c) );

	str = "";
	Key prev(-1, '#');

	while(!pq.empty()){
		Key k = pq.top();
		pq.pop();

		str += k.ch;
		
		if(prev.freq > 0)
			pq.push(prev);

		k.freq--;
		prev = k;
	}

	cout << str << endl;
}

int main(){
	rearrange("bbbbaac");
	return 0;
}
