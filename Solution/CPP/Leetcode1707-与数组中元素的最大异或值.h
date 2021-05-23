#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    Node():minValue(INT_MAX){ }
    int minValue;
    Node* child[2] = {nullptr,nullptr};
};


class Trie{
public:
    Trie(){
        head = new Node();
    }
    void insert(int val){
        auto cur = head;
        cur->minValue = min(cur->minValue,val); 
        for(int i = 30;i >= 0;i--){
            int x = (val >> i) & 1;
            if(!cur->child[x]) cur->child[x] = new Node();
            cur = cur->child[x];
            cur->minValue = min(cur->minValue,val);
        }
    }
    int query(int val,int limit){
        auto cur = head;
        if(cur->minValue > limit) return -1;
        int res = 0;
        for(int i = 30;i >= 0;i--){
            int x = (val >> i) & 1;
            if(cur->child[!x] != nullptr && cur->child[!x]->minValue <= limit){
                res |= 1 << i;
                x ^= 1;
            }
            cur = cur->child[x];
        }
        return res;
    }
private:
    Node* head;
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie tree;
        for(auto num:nums){
            tree.insert(num);
        }
        vector<int> res;
        for(auto q:queries){
            int ans = tree.query(q[0],q[1]);
            res.push_back(ans);
        }
        return res;
    }
};