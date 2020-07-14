#include <stdio.h>

#include <vector>
struct BSTNode {
	int val;
	int count;
	BSTNode *left;
	BSTNode *right;
	BSTNode(int x) : val(x), left(NULL), right(NULL), count(0) {}
};

void BST_insert(BSTNode *node, BSTNode *insert_node, int &count_small){
	if (insert_node->val <= node->val){
		node->count++;
		if (node->left){
			BST_insert(node->left, insert_node, count_small);
		}
		else{
			node->left = insert_node;
		}
	}
	else{
		count_small += node->count + 1;
		if (node->right){
			BST_insert(node->right, insert_node, count_small);
		}
		else{
			node->right = insert_node;
		}
	}
}

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
    	std::vector<int> result;
    	std::vector<BSTNode *> node_vec;
    	std::vector<int> count;
    	for (int i = nums.size() - 1; i >= 0; i--){
    		node_vec.push_back(new BSTNode(nums[i]));
	    }
	    count.push_back(0);
	    for (int i = 1; i < node_vec.size(); i++){
	    	int count_small = 0;
    		BST_insert(node_vec[0], node_vec[i], count_small);
    		count.push_back(count_small);
    	}
        for (int i = node_vec.size() - 1; i >= 0; i--){
        	delete node_vec[i];
        	result.push_back(count[i]);
        }
        return result;
    }
};

