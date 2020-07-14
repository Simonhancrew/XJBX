#pragma once
#include<vector>
#include<string>
using namespace std;
struct TrieNode
{
	TrieNode* child[26]={0};
	bool is_end;
	TrieNode() :is_end(false) {
		for (int i = 0; i < 26; i++) {
			child[i] = 0;
		}
	}
};
class TrieTree {
public:
	TrieTree() {}
	~TrieTree()
	{
		for (int i = 0; i < _node_vec.size(); i++) {
			delete _node_vec[i];
		}
	}
	void insert(const char* word) {
		TrieNode* ptr = &_root;
		while (*word) {
			int pos = *word - 'a';
			if (!ptr->child[pos]) {
				ptr->child[pos] = new TrieNode();
			}
			ptr = ptr->child[pos];
			word++;
		}
		ptr->is_end = true;
	}
	bool search(const char* word) {
		TrieNode* ptr = &_root;
		while (*word) {
			int pos = *word - 'a';
			if (!ptr->child[pos]) {
				return false;
			}
			ptr = ptr->child[pos];
			word++;
		}
		return ptr->is_end;
	}
	bool startwit(const char* prefix) {
		TrieNode* ptr = &_root;
		while (*prefix) {
			int pos = *prefix - 'a';
			if (!ptr->child[pos]) {
				return false;
			}
			ptr = ptr->child[pos];
			prefix++;
		}
		return true;
	}
private:
	TrieNode* new_node() {
		TrieNode* node = new TrieNode();
		_node_vec.push_back(node);
		return node;
	}
	vector<TrieNode*> _node_vec;
	TrieNode _root;
};
class worddic {
public:
	worddic() {}
	void addword(string &word) {
		_trie_tree.insert(word.c_str());
	}
	bool search(TrieNode *node,const char* word) {
		if (*word == '\0') {
			if (node->is_end) {
				return true;
			}
			return false;
		}
		if (*word == '.') {
			for (int i = 0; i < 26; i++) {
				if (node->child[i] && search(node->child[i], ++word)) {
					return true;
				}
			}
		}
		else {
			int pos = *word - 'a';
			if (node->child[pos] && search(node->child[pos], ++word)) {
				return true;
			}
		}
		return false;
	}
private:
	TrieTree _trie_tree;
};