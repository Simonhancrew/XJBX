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