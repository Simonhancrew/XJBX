#include <vector>
#include <numeric>
using namespace std;
class CombinationIterator {
public:
    CombinationIterator(string characters,int combinationLength){
        str = characters;
        pos.resize(combinationLength);
        iota(pos.begin(),pos.end(),0);// 0 1 2 3 4 5 6
        finished = false;
    }

    string next(){
        string cur;
        //第一次推入0-target-1的char
        //之后每一次都是之前算好的
        //类似于一个迭代器
        for(auto index:pos){
            cur.push_back(str[index]);
        }
        //结束记录
        int i = -1;
        //从后往前，减少变化之后的位置数增大次数
        for(int k = pos.size()-1;k>=0;--k){
            //如果当前位置数不是能达到的最大，标记这个位置
            if(pos[k] != str.size()-pos.size()+k){
                i = k;
                break;
            }
        }
        if( i == -1){
            finished = true;
        }else{
            //增大一次该位置，之后的每个位置也要迭代的增大
            ++pos[i];
            for(int j = i+1;j<pos.size();++j){
                pos[j] = pos[j-1] + 1;
            }
        }
        return cur;
    }

    bool hasNext(){
        return !finished;
    }
private:
    bool finished;
    string str;
    vector<int> pos;
};

