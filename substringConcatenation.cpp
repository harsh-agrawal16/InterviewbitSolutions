#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
	//struct TrieNode* children[256];
	vector<TrieNode*> children(256,NULL);
	bool isEndOfWord=false;
};

TrieNode* constructTrie(vector<string> L){

	TrieNode* root = new TrieNode;
	TrieNode* temp = root;

	for(int i=0;i<L.length();i++){
		for(int j=0;j<L[i].length();j++){
			if(!temp->children[L[i][j]-'a']){
				temp->children[L[i][j]-'a'] = new TrieNode;
			}

			temp = temp->children[L[i][j]-'a'];
		}

		temp->isEndOfWord = true;
	}

	return root;
}

/*
bool searchTrie(TrieNode* X, char a){
	if(X->children[a - 'a']){

	}
}*/

vector<int> substringConcatenation(string S, vector<string> L){
	//construct a Trie for the words in L

	TrieNode* root = constructTrie(L);
	vector<int> ans;
	int start = 0;

    int count = 0;
	for(int i=0;i<L.length();i++){
		for(int j=0;j<L[i].length();j++){
			   count++;			
			}
		}
	}
 

    TrieNode* temp = root;
    int temp_count = count;
	for(int i=0;i<S.length();i++){		
		if(!temp->children[S[i]-'a']){
			temp_count--;
			temp = temp->children[S[i]-'a'];

			if(temp_count==0){
				temp_count = count;
				ans.push_back(start);
				start = i+1;
				temp = root;
			}
		}

		else if(temp->isEndOfWord){
			temp = root;
			i--;
			continue;
		}
		else{
			temp_count = count;
			start = i+1;
			temp = root;
		}
	}


}