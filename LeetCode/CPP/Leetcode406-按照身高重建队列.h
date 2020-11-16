#include <vector>
#include <algorithm>
#include <list>
using namespace std;
//从大到小排身高
//身高一样的选择k小的站在前面
//之后按照k的位置去insert
//注意insert的插入效率而去选择相应的容器
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //身高从大到小排（身高相同k小的站前面）
        sort(people.begin(),people.end(),[](vector<int> &u,vector<int> &v){
            return u[0] > v[0] ||(u[0] == v[0] && u[1] < v[1]);
        });
        //选择底层是链表的list，插入效率高于vector
        list<vector<int>> que;
        for(int i = 0;i < people.size();++i){
            int position = people[i][1];
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) { 
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};