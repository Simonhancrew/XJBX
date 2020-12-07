#include <vector>
#include <string>
using namespace std;
//所有的回溯可以理解为树的深搜，列出所有情况。根据需要进行减枝。
class Solution {
public:
    //path存放此时从s[0,...,pos-1]找到的ip子串，size最大值为4    
    void DFS(const string& s, int pos, vector<string>& path){
        int maxSize = (4-path.size())*3;//剩余位数的最大长度，最大为12
        //若剩余位数大于最大剩余位数长度，可提前终止
        if(s.size()-pos>maxSize) return;
        //ip字串的个数为4并且保证pos已经到s的末尾
        if(path.size()==4 && pos == s.size()){
            //构造ip串
            string str = path[0]+"."+path[1]+"."+path[2]+"."+path[3];
            res.push_back(str);//存放结果
            return;
        }
        //递归回溯
        //i<字符串s的长度，并且ip字串的长度不会超过3
        for(int i=pos;i<s.size()&&i<=pos+2;++i){
            string ip = s.substr(pos,i-pos+1);
            if(isValid(ip)){
                path.push_back(ip);
                DFS(s,i+1,path);
                path.pop_back();//手动对path进行回溯
            }
        }
    }
    bool isValid(string ip){
        int val = stoi(ip);
        if(val>255) 
            return false;//ip子串最大值不能超过255
        if(ip.size()>=2 && ip[0] == '0')
            return false;//当ip子串长度大于2时,开头不能为0
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4) return res;
        vector<string>path;
        DFS(s,0,path);
        return res;
    }
private:
    vector<string> res;//存放最终的结果
};


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        backtracking(s, 0, 0);
        return result;
    }
private:
    vector<string> result;// 记录结果
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // 点数量为3时，分隔结束
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--;                         // 回溯
                s.erase(s.begin() + i + 1);         // 回溯删掉逗点
            } else break; // 不合法，直接结束本层循环
        }
    }
    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
                return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
};