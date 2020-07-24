#include <vector>
using namespace std;
class Disjointset{
public:
    Disjointset(int n){
        for(int i =0;i<n;i++){
            size.push_back(i);
            id.push_back(i);
            // count++;
        }
        count = n;
    }
    //find的时候会路径优化。父节点继续向上指
    int _find(int p){
        while(p != id[p]){
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    void _union(int p,int q){
        int pid = _find(p);
        int qid = _find(q);
        if(pid == qid){
            return;
        }
        if(size[pid]<size[qid]){
            id [pid] = qid;
            size[qid]+=size[pid];
        }
        if(size[pid]>size[qid]){
            id[qid] = pid;
            size[pid] +=qid;
        }
        count--;//总树的规模要减少
    }
private:
    vector<int> size;//开始每个元素都是一棵树，随后相同的id的合体。size[p]为以p为id的树有多大。根节点为p
    vector<int> id;
    int count;
};