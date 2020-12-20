#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//首先，怎么去除一个char让字典序最小？找到最小的下标i
//如果s[i] > s[i + 1],这个小标处的char是影响最大的，移除他
//本题，要不重复，则首先想到一个used数组，之后要去除相关的char，考虑栈，拿栈顶和当前遍历到的char比对
//怎么知道这个char可不可以删除？开一个全局的数组，记录所有的char的个数，并在遍历的时候动态的更新
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> used(26,0),nums(26,0);
        for(char chr:s){
            nums[chr - 'a']++;
        }
        string stk = "";
        for(auto chr:s){
            //可以push的情况
            if(stk.empty() || (chr > stk.back() && used[chr - 'a'] == 0)){
                stk.push_back(chr);
                nums[chr - 'a']--;
                used[chr - 'a']++;
            }else if(used[chr - 'a'] == 0){
                //需要移除的时候，并判断能不能移除
                while(!stk.empty() && chr < stk.back() && nums[stk.back() - 'a'] > 0){
                    used[stk.back() - 'a']--;
                    stk.pop_back();
                }
                stk.push_back(chr);
                used[chr - 'a']++;
                nums[chr - 'a']--;
            }else{
                //啥都不干，这个数要--
                nums[chr - 'a']--;
            }
        }
        return stk;
    }
};