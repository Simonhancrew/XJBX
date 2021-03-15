//
// Create by Han on 2020/08/26
//

#ifndef MY_TRIE_TREE_H
#define MY_TRIE_TREE_H
#define MAX_CHAR_NUM 26
#include <vector>
#include <iostream>
using namespace std;
struct TrieNode{
    //数字映射到字母（ 1 -> a）
    TrieNode* child[MAX_CHAR_NUM];
    bool isEndOfWord;
    int cnt;
    TrieNode():isEndOfWord(false),cnt(0){
        for(int i =0;i<MAX_CHAR_NUM;i++){
            child[i] = 0;
        }
    }
};
//每个节点本身不能看作一个char，每个节点本身的child数组储存每个char
class TrieTree{
public:
    TrieTree(){

    }
    ~TrieTree(){
        for(int i =0;i<_node_vec.size();i++){
            delete _node_vec[i];
        }
    }
    //插入
    void insert(const char *word){
        //从trie树根节点开始往下搜索
        TrieNode *ptr = &_root;
        //遍历每一个字符
        while(*word){
            //找到在数组中的位置
            int pos = *word-'a';
            if(!ptr->child[pos]){
                ptr->child[pos] = new_node();
            }
            ptr = ptr->child[pos];
            word++;
        }
        //将单词结束标记为true
        ptr->isEndOfWord = true;
        ptr->cnt++;
    }
    //查找
    bool search(const char *word){
        TrieNode *ptr = &_root;
        while(*word){
            int pos = *word - 'a';
            if(!ptr->child[pos]){
                return false;
            }
            ptr = ptr->child[pos];
            word++;
        }
        return ptr->isEndOfWord;
    }
    //是否存在前缀为prefix
    bool startWith(const char *prefix){
        TrieNode *ptr = &_root;
        while(*prefix){
            int pos = *prefix - 'a';
            if(!ptr->child[pos]){
                return false;
            }
            //进入下一个节点去判断他的数组
            ptr = ptr->child[pos];
            //不要忘记将prefix也往前推一位
            prefix++;
        }
        return true;
    }
    //查找根节点
    TrieNode *root(){
        return &_root;
    }
    //前序遍历
    void preorder(TrieNode *node,int layer){
        for(int i = 0;i<MAX_CHAR_NUM;i++){
            if(node->child[i]){
                for(int j = 0;j<layer;j++){
                    cout<<'-';
                }
                cout<<i+'a';
                if(node->child[i]->isEndOfWord == true){
                    cout<<"end";
                }
                cout<<'\n';
                preorder(node->child[i],layer+1);
            }
        }
    }
    void get_all_words(TrieNode *node,vector<string> &result,string &cur){
        for(int i = 0;i<MAX_CHAR_NUM;i++){
            if(node->child[i]){
                cur.push_back(i+'a');
                if(node->child[i]->isEndOfWord){
                    result.push_back(cur);
                }
                get_all_words(node->child[i],result,cur);
                //回溯，往下走的时候进回溯，可以不用自己写循环
                cur.pop_back();
            }
        }
    }
private:
    //一个小技巧，方便析构，全部放进vector，析构的时候一个循环全部解决
    //空间换遍历时间
    TrieNode *new_node(){
        TrieNode *node = new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    vector<TrieNode*> _node_vec;
    //储存根节点，方便每次查找
    TrieNode _root;

};
#endif //MY_TRIE_TREE_H