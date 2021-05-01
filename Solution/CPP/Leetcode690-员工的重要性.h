#include <vector>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int res;
    vector<Employee*> employee;
    int getImportance(vector<Employee*> employees, int id) {
        res = 0;
        employee = employees;
        for(Employee* ep:employees){
            if(ep->id == id){
                dfs(ep);
            }
        }
        return res;
    }
    void dfs(Employee* ep){
        res += ep->importance;
        if(ep->subordinates.size() == 0){
            return;
        }
        for(auto e:ep->subordinates){
            for(Employee* ee:employee){
                if(ee->id == e){
                    dfs(ee);
                }
            }
        }
    }
};