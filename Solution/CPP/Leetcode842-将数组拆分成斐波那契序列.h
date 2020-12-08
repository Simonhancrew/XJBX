#include <string>
#include <vector>
using namespace std;
//什么时候回溯需要返回值？
//找到一组符合情况的解需要bool数组加速
//有三种情况不需要继续下去
//1 开头为0，且位数大于1
//2 大于INT_MAX
//3 无法凑成斐波那契数列
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        backTrack(S,list,0,0,0);
        return list;
    }
private:
    bool backTrack(string &S,vector<int> &list,int index,int sum,int prev){
        if(index == S.size()){
            return list.size() >= 3;
        }
        //cur记得要赋值
        long long cur = 0;
        for(int i = index;i < S.size();++i){
            //第一种情况
            if(i > index && S[index] == '0'){
                break;
            }
            cur = 10 * cur + S[i] - '0';
            //2
            if(cur > INT_MAX){
                break;
            }
            //3
            if(list.size() >= 2){
                if(cur < sum){
                    continue;
                }else if(cur > sum){
                    break;
                }
            }
            //回溯
            list.push_back(cur);
            if(backTrack(S,list,i + 1,prev + cur,cur)){
                return true;
            }
            list.pop_back();
        }
        return false;
    }
};