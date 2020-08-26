//
// Create by Han on 2020/08/26
//

#ifndef MY_TRIE_TREE_H
#define MY_TRIE_TREE_H
#include <unordered_map>
using namespace std;
struct TrieNode{
    unordered_map<char,TrieNode> children;
    bool isEndOfWord;

    TrieNode(){
        isEndOfWord = false;
    }    
};
class TrieTree{

};
#endif //MY_TRIE_TREE_H