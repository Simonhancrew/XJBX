#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        canReach.insert(0);
        DFS(rooms,0);
        for(int i = 0;i<rooms.size();i++){
            if(canReach.find(i)==canReach.end()){
                return false;
            }
        }
        return true;
    }
private:
    unordered_set<int> canReach;
    void DFS(const vector<vector<int>> &rooms,int index){
        for(auto room:rooms[index]){
            if(canReach.find(room) == canReach.end()){
                canReach.insert(room);
                DFS(rooms,room);
            }            
        }
    }
};