#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    static constexpr int TARGET = 24;
    //除法运算为实数除法，因此结果为浮点数，列表中存储的数字也都是浮点数。在判断结果是否等于 2424 时应考虑精度误差，这道题中，误差小于1e-6
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

    bool judgePoint24(vector<int> &nums) {
        //为了除，转成double再处理
        vector<double> list;
        for(const int &num:nums){
            list.push_back(static_cast<double>(num));
        }
        return solve(list);
    }

    bool solve(const vector<double> &l) {
        if(l.size() == 0){
            return false;
        }
        if(l.size()==1){
            return fabs(l[0] - TARGET) < EPSILON;
        }
        int size = l.size();
        //i和j是要处理的有序的两个数，剩下的数放入一个新的list中
        for(int i =0;i<size;i++){
            for(int j = 0;j<size;j++){
                if(i != j){
                    vector<double> list2;
                    for(int k =0;k<size;k++){
                        if(k != i && k !=j){
                            list2.push_back(l[k]);
                        }
                    }
                    //因为加法和乘法的顺序是无所谓的，所以可以放弃一个有序的对
                    for(int signal = 0;signal < 4;signal++){
                        if(signal < 2 && i>j){
                            continue;
                        }
                        if(signal == ADD){
                            list2.push_back(l[i]+l[j]);
                        }else if(signal == MULTIPLY){
                            list2.push_back(l[i]*l[j]);
                        }else if(signal == SUBTRACT){
                            list2.push_back(l[i]-l[j]);
                        }else if(signal == DIVIDE){
                            if(l[j]<EPSILON){
                                //j是0的话除法就没必要做了
                                continue;
                            }else{
                                list2.push_back(l[i]/l[j]);
                            }
                        }
                        //递归的处理剩下的几个数字
                        if(solve(list2)){
                            return true;
                        }else{
                            //不能成功的话就把之前的一个数字拿出来回溯，试试别的运算
                            list2.pop_back();
                        }
                    }
                }
            }
        }
        //所有的情况结束，无法跳到true，则返回false;
        return false;
    }
};