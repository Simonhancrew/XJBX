//模板最大异或对
//trie + 从高位尽量每一位都选和当前不一样的

class Node{
public:
    Node():left(nullptr),right(nullptr){}
    Node(int val):left(nullptr),right(nullptr){}
    Node *left,*right;//left 1 right 0
};


class Trie{
public:
    Trie(){
        head = new Node();
    }
    void insert(int val){
        auto cur = head;
        for(int i = 30;i >= 0;i--){
            int x = val >> i & 1;
            if(x == 1){
                if(!cur->left){
                    auto node = new Node(x);
                    cur->left = node;
                }
                cur = cur ->left;
            }else{
                if(!cur ->right){
                    auto node = new Node(x);
                    cur -> right = node;
                }
                cur = cur -> right;
            }
        }
    }
    int query(int val){
        auto cur = head;
        int res = 0;
        for(int i = 30;i >= 0;i--){
            int x = val >> i & 1;
            if(x == 1){
                if(cur ->right){
                    res = res * 2 + 0;
                    cur = cur ->right;
                }else{
                    res = res * 2 + 1;
                    cur = cur ->left;
                }
            }else{
                if(cur ->left){
                    res = res * 2 + 1;
                    cur = cur ->left;
                }else{
                    res = res * 2;
                    cur = cur->right;
                }
            }
        }
        return res ^ val;
    }
private:
    Node* head;
};

#include <vector>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie tree;
        int ans = 0;
        for(int i = 0;i < n;i++){
            tree.insert(nums[i]);
        }
        for(auto x:nums){
            int cur = tree.query(x);
            ans = max(ans,cur);
        }
        return ans;
    }
};