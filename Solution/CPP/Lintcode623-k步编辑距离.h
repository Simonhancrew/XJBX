#pragma once
#include <string>
#include <vector>
using namespace std;
//重复计算的字符串部分交给trie树
//其余的和编辑距离相同
struct TrieNode {
    TrieNode* child[26];
    bool hasword;
    //为方便找到word，记录一下
    string word;
    TrieNode() :hasword(false) {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
};
class Trietree {
public:
    Trietree() {
    
    }
    ~Trietree() {
        for (int i = 0; i < _node_vec.size(); ++i) {
            delete _node_vec[i];
        }
    }
    //不可以使用TireNode*
    //不会自动初始化
    TrieNode _root;
    void insertWord(string& words) {
        TrieNode* ptr = &_root;
        for (auto wd : words) {
            int pos = wd - 'a';
            if (ptr->child[pos] == nullptr) {
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
        }
        ptr->hasword = true;
        ptr->word = words;
    }
private:
    vector<TrieNode*> _node_vec;
    TrieNode* new_node() {
        TrieNode* node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
};
class Solution {
public:
    vector<string> kDistance(vector<string>& words, string& targetstr, int k) {
        //空间内的target
        target = targetstr;
        //最大距离
        K = k;
        //目标串长度
        n = target.size();
        //构建一下前缀树
        Trietree new_tree;
        for (int i = 0; i < words.size(); ++i) {
            new_tree.insertWord(words[i]);
        }
        //初始化dp数组
        //dp[空串][0~n]
        dp.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
        }
        //dfs
        dfs(&new_tree._root, dp);
        return res;
    }
private:
    string target;
    int K = 0;
    int n;
    vector<int> dp;
    vector<string> res;
    void dfs(TrieNode* p, vector<int> dp) {
        vector<int> ndp(26);
        //dp[某个串][n]
        if (p->hasword) {
            //距离不大于K，不要return，前缀树可能往下还有words
            if (dp[n] <= K) {
                res.push_back(p->word);
            }
        }
        for (int i = 0; i < 26; ++i) {
            //往下有单词
            if (p->child[i] == nullptr) {
                continue;
            }
            //dp[i][0] = i;
            //dp[0] = dp[进递归的单词][0]
            //ndp[0] = dp[进递归的单词往前一步][0]
            ndp[0] = dp[0] + 1;
            for (int j = 1; j <= n; ++j) {
                //dp[i][j] = min(dp[i-1][j] + 1,dp[i-1][j-1] + 1,dp[i][j - 1] + 1)
                //min(删除原串尾，替换原串尾，增加原串尾)，串是指此时的串
                ndp[j] = min(min(ndp[j - 1] + 1, dp[j] + 1), dp[j - 1] + 1);
                auto c = target[j - 1] - 'a';
                if (c == i) {
                    //最后一个char相同
                    //dp[i][j] = min(dp[i][j],dp[i - 1][j - 1])
                    ndp[j] = min(ndp[j], dp[j - 1]);
                }
            }
            //继续深搜下面的节点
            dfs(p->child[i], ndp);
        }
    }
};