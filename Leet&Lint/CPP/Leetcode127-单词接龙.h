#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
//建立一个映射，从word到wordid，然后构建一张图。从这张图中广度搜索
//使用广搜的原因要清楚，无向图的最短通路，一般广搜就是最后的答案
//深搜会很复杂，需要标记已访问数组，不然死循环
class Solution {
public: 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto word:wordList){
            addEdge(word);
        }
        addEdge(beginWord);
        if(wordId.find(endWord) == wordId.end()){
            return 0;
        }
        vector<int> dis(nodeNum,INT_MAX);
        int beginId = wordId[beginWord],endId = wordId[endWord];
        dis[beginId] = 0;
        queue<int> que;
        que.push(beginId);
        while(!que.empty()){
            auto tmp = que.front();
            que.pop();
            if(tmp == endId){
                //因为加入了虚拟节点
                //距离是原来的两倍，且没考虑初始点
                //返回的是长度，即所有的节点个数
                return dis[tmp]/2 + 1;
            }
            for(int &it:edge[tmp]){
                //没被探索过，说明第一性搜索
                if(dis[it] == INT_MAX){
                    dis[it] = dis[tmp] + 1;
                    que.push(it);
                }
            }
        }
        return 0;    
    }
private:
    //单词和id的映射
    unordered_map<string,int> wordId;
    //id连接的图，其中包含虚拟节点
    //最后的结果是两倍的
    vector<vector<int>> edge;
    //总的节点数量
    int nodeNum = 0;
    //构造节点，赋予id
    void addWord(const string &word){
        if(wordId.find(word) == wordId.end()){
            wordId[word] = nodeNum++;
            //对每一个word初始他的邻接表为空
            edge.emplace_back();
        }
    }
    //建立节点并连接，构建虚拟节点方便处理
    void addEdge(string& word){
        addWord(word);
        int id1 = wordId[word];
        //独立的比较两个单词是否相差一个太繁琐
        //创建虚拟节点替换，每个单词连接替换一次字母的虚拟节点
        for(auto &it:word){
            auto tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            //不要忘记复原单词
            it = tmp;
        }
    }  
};


#include <unordered_set>
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 将vector转成unordered_set，提高查询速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // 如果endWord没有在wordSet出现，直接返回0
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        // 记录word是否访问过
        unordered_map<string, int> visitMap; // <word, 查询到这个word路径长度>
        // 初始化队列
        queue<string> que;
        que.push(beginWord);
        // 初始化visitMap
        visitMap.insert(pair<string, int>(beginWord, 1));

        while(!que.empty()) {
            string word = que.front();
            que.pop();
            int path = visitMap[word]; // 这个word的路径长度
            for (int i = 0; i < word.size(); i++) {
                string newWord = word; // 另一种手法，26个字母一个个的替换试试
                for (int j = 0 ; j < 26; j++) {
                    newWord[i] = j + 'a';
                    if (newWord == endWord) return path + 1; // 找到了end，返回path+1
                    // wordSet出现了newWord，并且newWord没有被访问过
                    if (wordSet.find(newWord) != wordSet.end()
                            && visitMap.find(newWord) == visitMap.end()) {
                        // 添加访问信息
                        visitMap.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};