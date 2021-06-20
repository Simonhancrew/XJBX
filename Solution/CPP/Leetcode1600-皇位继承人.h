#include <unordered_set>
#include <unordered_map>
#include<functional>

using namespace std;

class ThroneInheritance {
public:
    ThroneInheritance(string kingName):king(move(kingName)) {

    }
    
    void birth(string parentName, string childName) {
        relation[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        // can auto
        function<void(const string&)> dfs = [&](const string& name){
            if(!dead.count(name)) ans.push_back(name);
            if(relation.count(name)){
                for(auto &childName:relation[name]){
                    dfs(childName);
                }
            }
        };
        dfs(king);
        return ans;
    }
private:
    string king;
    unordered_map<string,vector<string>> relation;
    unordered_set<string> dead;
};