#pragma once
#include <vector>
#include <queue>
using namespace std;
struct GraphNode {
    int label;
    vector<GraphNode*> neighbors;
    GraphNode(int x) :label(x) {};
};

//深度优先搜索 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<GraphNode*> graph;
        vector<int> visit;
        for (int i = 0; i < numCourses; i++) {
            graph.push_back(new GraphNode(i));
            visit.push_back(-1);
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            GraphNode* begin = graph[prerequisites[i][1]];
            GraphNode* end = graph[prerequisites[i][0]];
            begin->neighbors.push_back(end);
        }
        for (int i=0; i < graph.size(); i++) {
            if (visit[i] == -1 && !DFS_graph(graph[i], visit)) {
                return false;
            }
        }
        for (int i = 0; i < numCourses; i++) {
            delete graph[i];
        }
        return true;
    }
private:
    bool DFS_graph(GraphNode* node, vector<int>& visit) {
        visit[node->label] = 0;
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (visit[node->neighbors[i]->label] == -1) {
                if (DFS_graph(node->neighbors[i], visit) == 0) {
                    return false;
                }
            }
            else if (visit[node->neighbors[i]->label] == 0) {
                return false;
            }
        }
        visit[node->label] = 1;
        return true;
    }
};

//广度优先，顺序思考。减少每个节点相连的节点的入度，如有相邻节点的入度为0则可以开始学习。
class Solution2{
private:
    vector<int> inpower;
    vector<vector<int>> edge;
public:    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        inpower.resize(numCourses);
        edge.resize(numCourses);
        for(auto info:prerequisites){
            ++inpower[info[0]];
            edge[info[1]].push_back(info[0]);
        }
        queue<int> que;
        for(int i = 0;i<numCourses;i++){
            if(inpower[i] == 0){
                que.push(i);
            }
        }
        int visit = 0;
        while(!que.empty()){
            int a = que.front();
            que.pop();
            ++visit;
            for(int v:edge[a]){
                --inpower[v];
                if(inpower[v] == 0){
                    que.push(v);
                }
            }
        }
        return visit == numCourses;
    }
};