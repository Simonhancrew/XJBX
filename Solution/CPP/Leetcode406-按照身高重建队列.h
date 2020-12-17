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

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int> a,vector<int> b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> que;
        //队列排序之后按照k插入，先插入身高高的
        //这样局部小问题时可以满足的
        //之后推到大问题也可以满足
        for(int i = 0;i < people.size();++i){
            int pos = people[i][1];
            que.insert(que.begin() + pos,people[i]);
        }
        return que;
    }
};