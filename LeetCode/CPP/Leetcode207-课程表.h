#pragma once
#include <vector>
using namespace std;
struct GraphNode {
    int label;
    vector<GraphNode*> neighbors;
    GraphNode(int x) :label(x) {};
};

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