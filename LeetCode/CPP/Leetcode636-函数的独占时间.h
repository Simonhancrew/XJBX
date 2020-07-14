class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n,0);
        stack<pair<int,int>> stk;
        for(string &log:logs){
            size_t pos1 = log.find(':');
            size_t pos2 = log.rfind(':');
            int curId = stoi(log.substr(0,pos1));
            string curAction = log.substr(pos1+1,pos2-pos1-1);
            int curTime = stoi(log.substr(pos2+1));
            if(curAction == "start"){
                stk.push(make_pair(curId,curTime));
            }
            else{
                int duration = curTime - stk.top().second+1;
                result[curId]+=duration;
                stk.pop();
                if(!stk.empty()){
                    result[stk.top().first] -= duration;
                }
            }
        }
        return result;
    }
};