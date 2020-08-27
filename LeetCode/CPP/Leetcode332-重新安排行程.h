#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
class Solution{
public:    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        for(const vector<string> &vec:tickets){
            flytos[vec[0]][vec[1]]++;
        }
        result.push_back("JFK");
        backtrack(tickets.size(),1,result);
        return result;
    }
private:
    unordered_map<string,map<string,int>> flytos;
    bool backtrack(int ticketNum,int index,vector<string> result){
        if(index == ticketNum){
            return true;
        }
        for(pair<const string,int> &flyto:flytos[result[result.size()-1]]){
            if(flyto.second > 0){
                result.push_back(flyto.first);
                flyto.second--;
                if(backtrack(ticketNum,index+1,result)) return true;
                result.pop_back();
                flyto.second++;
            }
        }
        return false;
    }

};