#pragma once
#include<string>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class codec {
public:
	string serialize(TreeNode* root) {
		string data;
		BST_preorder(root, data);
		return data;
	}
	TreeNode* deserialize(string data) {
		if (data.size() == 0) {
			return NULL;
		}
		vector<TreeNode*> node_vec;
		int val = 0;
		for (int i = 0; i < data.size(); i++) {
			if (data[i] == '#') {
				node_vec.push_back(new TreeNode(val));
			}
			else {
				val = val * 10 + data[i] - '0';
			}
		}
		for (int i = 1; i < node_vec.size(); i++) {
			BST_insert(node_vec[0], node_vec[i]);
		}
		return node_vec[0];
	}
private:
	void change_int_to_string(int val, string& str_val) {
		string tmp;
		while (val) {
			tmp += val % 10 + '0';
			val = val / 10;
		}
		for (int i = tmp.size() - 1; i >= 0; i++) {
			str_val += tmp[i];
		}
		str_val += '#';
	}
	void BST_preorder(TreeNode* node, string& data) {
		if (!node) {
			return;
		}
		string str_val;
		change_int_to_string(node->val, str_val);
		data += str_val;
		BST_preorder(node->left, data);
		BST_preorder(node->right, data);
	}
	void BST_insert(TreeNode* root, TreeNode* insert_node) {
		if (root->val < insert_node->val) {
			if (!root->left) {
				root->left = insert_node;
			}
			else {
				BST_insert(root->left, insert_node);
			}
			
		}
		else {
			if (root->right) {
				BST_insert(root->right, insert_node);
			}
			else {
				root->right = insert_node;
			}
		}
	}
};