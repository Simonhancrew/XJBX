#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//一个贪心的问题
//因为奇数偶数/2都是向下取整，在某个字符多余S.size()+1/2时，是一定不能重排的。无论如何都会相邻
//然后构建一个最大堆，按照字母出现的次数排序
//先push入所有出现的char，此时最大堆里面的单词都是唯一的
//之后取两个值，取完之后pop，奇数时，还剩下最后的一个，继续取一次
class Solution {
public:
    string reorganizeString(string S) {
        if(S.size() < 2){
            return S;
        }
        int maxword = 0;
        vector<int> counts(26,0);
        for(auto s:S){
            counts[s - 'a']++;
            maxword = max(maxword,counts[s - 'a']);
        }
        if(maxword > (S.size() + 1) / 2){
            return "";
        }
        auto cmp = [&](const char& letter1,const char& letter2){
            return counts[letter1 - 'a'] < counts[letter2 - 'a'];
        };
        priority_queue<char,vector<char>,decltype(cmp)> queue(cmp);
        for(auto i = 'a';i <= 'z';++i){
            if(counts[i - 'a'] > 0){
                queue.push(i);
            }
        }
        string ret = "";
        while(queue.size() > 1){
            char letter1 = queue.top();
            queue.pop();
            char letter2 = queue.top();
            queue.pop();
            ret += letter1;
            ret += letter2;
            counts[letter1 - 'a']--,counts[letter2-'a']--;
            if(counts[letter1 - 'a'] > 0){
                queue.push(letter1);
            }
            if(counts[letter2 - 'a'] > 0){
                queue.push(letter2);
            }
        }
        if(!queue.empty()){
            ret += queue.top();
            queue.pop();
        }
        return ret;
    }
};
//另外一种思想，先插入偶数位，再插入奇数位
//因为奇数位永远大于等于偶数位，所以现在奇数位插排序次数多的char、
#include <unordered_map>
class Solution{
public:
    string reorganizeString(string S){
        unordered_map<char,int> umap;
        if(S.length() < 2){
            return S;
        }
        int maxWord = 0;
        for(auto s:S){
            umap[s]++;
            maxWord = max(maxWord,umap[s]);
        }
        if(maxWord > (S.length() + 1) / 2){
            return "";
        }
        vector<pair<char,int>> vec(umap.begin(),umap.end());
        sort(vec.begin(),vec.end(),cmp);
        string ret(S);
        int index = 0;//先排奇数位置的，先排多的
        for(int i = 0;i < vec.size();++i){
            while(vec[i].second--){
                ret[index] = vec[i].first;
                index += 2;
                //奇数时会在S.size() + 1，偶数时，会在S.size()处
                //要作做好区间划分
                if(index >= S.size()) index = 1;
            }
        }
        return ret;
    }
private:
    static bool cmp(const pair<char,int> &a,const pair<char,int> &b){
        return a.second > b.second;//从大到小
    }
};