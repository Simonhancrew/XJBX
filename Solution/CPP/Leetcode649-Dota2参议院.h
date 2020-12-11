#include <string>
#include <queue>
using namespace std;
//贪心，总考虑先灭掉对方靠前面的
//用队列模拟循环，push入坐标
//比对队列头的大小，小的更具有优势，pop掉大的
//最后队列中还有值的就是结果
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant,dire;
        int n = senate.size();
        for(int i = 0;i < n;++i){
            if(senate[i] == 'R'){
                radiant.push(i);
            }else{
                dire.push(i);
            }
        }
        while(!radiant.empty() && !dire.empty()){
            if(radiant.front() < dire.front()){
                radiant.push(radiant.front() + n);
            }else
            {
                dire.push(dire.front() + n);
            }
            radiant.pop();
            dire.pop();
        }
        return dire.empty()?"Radiant":"Dire";
    }
};