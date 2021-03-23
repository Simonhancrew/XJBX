#include <vector>
using namespace std;
class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};




class NestedIterator {
public:
    int k;
    vector<int> num;
    NestedIterator(vector<NestedInteger> &nestedList) {
        k = 0;
        dfs(nestedList);
    }
    void dfs(vector<NestedInteger> &nestedList){
        for(auto &l:nestedList){
            if(l.isInteger()) num.push_back(l.getInteger());
            else{
                dfs(l.getList());
            }
        }
    }
    int next() {
        return num[k++];
    }
    
    bool hasNext() {
        return k < num.size();
    }
};
