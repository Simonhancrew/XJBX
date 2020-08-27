#include "./ADT.hpp"
#include<iostream>
using namespace std;
//morris遍历利用了大量空右孩子的信息，达到了附加空间为O(1)的访问遍历
//一个有左孩子的节点会到达两次
class Morristraverse{
    //morris的前序遍历
    void MorrisPre(TreeNode* root){
        if(root == nullptr){
            return;
            //特殊情况处理
        }
        TreeNode *cur = root;
        TreeNode *mostRight;
        while(cur != nullptr){
            //找到左子树的最右节点，连接最右的右空节点到当前cur节点
            mostRight = cur->left;
            if(mostRight!=nullptr){
                while(mostRight->right!=nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                //连接
                if(mostRight->right == nullptr){
                    mostRight->right = cur;
                    //连接之后将cur进入左子树遍历
                    cur = cur->left;
                    continue;
                } 
                else{
                    //配合上一个if和开始的while，此时 mostRight->right 不空，就只说明他的右边连接着cur,需要断开连接
                    mostRight ->right = nullptr;
                }
            }
            cout<<cur->val<<'\n';
            cur=cur->right;
        }
        cout<<endl;
    }
    void MorrisMid(TreeNode* root){
        if(root == nullptr){
            return;
        }
        TreeNode *cur,*mostRight;//careful about the second*
        cur = root;
        while(cur != nullptr){
            mostRight = cur->left;
            if(mostRight!=nullptr){
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == nullptr){
                    mostRight->right = cur;
                    cout<<cur->val<<'\n';
                    cur = cur->left;
                    continue;
                }else{
                    mostRight->right = nullptr;
                }
            }else{
               cout<<cur->val<<'\n'; 
            }
            cur = cur->right;
        }
    }
    //后序遍历？？？？？？？？？？？?
    //后序可能会引入一点空间复杂度，个人觉得没必要
    void MorrisPos(TreeNode* root){
        //help help help
    }
};