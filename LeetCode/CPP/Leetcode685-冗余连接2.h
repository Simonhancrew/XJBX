#include <vector>
using namespace std;
//形如此类邻接表，互相连结，判断是否有环，可以考虑并查集
struct Unionfind{
    vector<int> id;
    Unionfind(int n){
        id.resize(n);
        for(int i=0;i<n;++i){
            id[i] = i;
        }
    }
    //查找的森林
    int find(int index){
        if(index == id[index]){
            return index;
        }else{
            return id[index] = find(id[index]);
        }
    }

    void merge(int u,int v){
        id[find(u)] = find(v);
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges){
        //边+1就是节点
        int allnode = edges.size()+1;
        //并查集判断有无环
        Unionfind uf = Unionfind(allnode);
        //每个节点的父节点，最开始都置为本身
        vector<int> parent = vector<int>(allnode,0);
        for(int i =0;i<allnode;i++){
            parent[i] = i;
        }
        //要么一个节点有两个父节点导致这条边冲突，要么有环，直接记录最后的有环边为冲突边。
        int conflict = -1;
        int cycle = -1;
        int alledge = edges.size();
        for(int i =0;i<alledge;i++){
            auto edge = edges[i];
            int node1 = edge[0],node2 = edge[1];
            //node2出现两个父节点，找到了冲突的边
            if(parent[node2] != node2){
                conflict = i;
            }else{
                parent[node2] = node1;
                //node1和node2的祖先都相同，说明此时导致有环
                if(uf.find(node1) == uf.find(node2)){
                    cycle = i;
                }else{
                    //union
                    uf.merge(node1,node2);
                }
            }
        }
        //有无冲突边？
        if(conflict<0){
            auto redundant = vector<int>{edges[cycle][0],edges[cycle][1]};
            return redundant;
        }else{
            //如果有冲突边，就判断有无环
            auto confictedge = edges[conflict];
            if(cycle>0){
                //有环有冲突，删除引起环的冲突边----[[2,1],[3,1],[4,2],[1,4]]
                auto redundant = vector<int> {parent[confictedge[1]],confictedge[1]};
                return redundant;
            }else{
                auto redundant = vector<int> {confictedge[0],confictedge[1]};
                return redundant;
            }
        }
    }
};