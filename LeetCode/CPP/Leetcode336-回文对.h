//没做出来，明天看
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

struct Trie {
    struct node {
        int ch[26];
        int flag;
        node() {
            flag = -1;
            memset(ch, 0, sizeof(ch));
        }
    };

    vector<node> tree;

    Trie() { tree.emplace_back(); }

    void insert(string& s, int id) {
        int len = s.length(), add = 0;
        for (int i = 0; i < len; i++) {
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                tree.emplace_back();
                tree[add].ch[x] = tree.size() - 1;
            }
            add = tree[add].ch[x];
        }
        tree[add].flag = id;
    }

    vector<int> query(string& s) {
        int len = s.length(), add = 0;
        vector<int> ret(len + 1, -1);
        for (int i = 0; i < len; i++) {
            ret[i] = tree[add].flag;
            int x = s[i] - 'a';
            if (!tree[add].ch[x]) {
                return ret;
            }
            add = tree[add].ch[x];
        }
        ret[len] = tree[add].flag;
        return ret;
    }
};

class Solution {
public:
    vector<pair<int, int>> manacher(string& s) {
        int n = s.length();
        string tmp = "#";
        tmp += s[0];
        for (int i = 1; i < n; i++) {
            tmp += '*';
            tmp += s[i];
        }
        tmp += '!';
        int m = n * 2;
        vector<int> len(m);
        vector<pair<int, int>> ret(n);
        int p = 0, maxn = -1;
        for (int i = 1; i < m; i++) {
            len[i] = maxn >= i ? min(len[2 * p - i], maxn - i) : 0;
            while (tmp[i - len[i] - 1] == tmp[i + len[i] + 1]) {
                len[i]++;
            }
            if (i + len[i] > maxn) {
                p = i, maxn = i + len[i];
            }
            if (i - len[i] == 1) {
                ret[(i + len[i]) / 2].first = 1;
            }
            if (i + len[i] == m - 1) {
                ret[(i - len[i]) / 2].second = 1;
            }
        }
        return ret;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie1, trie2;

        int n = words.size();
        for (int i = 0; i < n; i++) {
            trie1.insert(words[i], i);
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            trie2.insert(tmp, i);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            const vector<pair<int, int>>& rec = manacher(words[i]);

            const vector<int>& id1 = trie2.query(words[i]);
            reverse(words[i].begin(), words[i].end());
            const vector<int>& id2 = trie1.query(words[i]);

            int m = words[i].size();

            int all_id = id1[m];
            if (all_id != -1 && all_id != i) {
                ret.push_back({i, all_id});
            }
            for (int j = 0; j < m; j++) {
                if (rec[j].first) {
                    int left_id = id2[m - j - 1];
                    if (left_id != -1 && left_id != i) {
                        ret.push_back({left_id, i});
                    }
                }
                if (rec[j].second) {
                    int right_id = id1[j];
                    if (right_id != -1 && right_id != i) {
                        ret.push_back({i, right_id});
                    }
                }
            }
        }
        return ret;
    }
};
//字典树节点
class TrieNode
{
private:
    bool isEnd;//单词结束标记
    int index;//单词序号
    vector<TrieNode*> children;//子节点
public:
    //构造
    TrieNode():index(-1),isEnd(false),children(26,nullptr){}
    //析构
    ~TrieNode()
    {
        for(int i = 0;i < 26;i++)
        {
            if( children[i]) 
            {
                delete children[i];
                children[i] = nullptr;
            }
        }
    }
    //对外接口
    int getIndex() { return index;}
    void setIndex( int i) { index = i;}
    bool isWordEnd() { return isEnd;}
    void SetEnd(){ isEnd = true ;}
    //插入一个字符到子节点
    TrieNode * insertNode(char c)
    {
        if( !( 'a' <= c <= 'z')) return nullptr;
        int id = c-'a';
        if( children[id] == nullptr)
        {
            children[id] = new TrieNode();
            
        }
        return children[id];
    }
    //在子节点中查找一个字符
    TrieNode * getNode(char c)
    {
         if( !( 'a' <= c <= 'z')) return nullptr;
         int id = c-'a';
         return children[id] ;
    }
};
//字典树
class Trie
{
private:
    TrieNode * root;//根节点
public:
    Trie():root(new TrieNode()){}
    ~Trie()  { delete root;}  
    //插入一个单词及序号
    void insert( string word,int index)
    {
        TrieNode * p = root;
        for( int i = 0;i<word.size();i++)
        {
            p = p->insertNode(word[i]);
        }
        p->SetEnd();
        p->setIndex(index);
    }
    //查找一个字符串
    TrieNode *getNode(string word)
    {
        TrieNode * p = root;
        for(int i = 0;i < word.size();i++ )
        {
            p = p->getNode(word[i]) ;
            if( p == NULL ) return NULL;
        }
        return p;
    }
    //查找一个单词，返回序号
    bool  search(string word,int  &index)
    {
      
        TrieNode * p = getNode(word);
        if( p )
        {
            index = p->getIndex();
            return  p->isWordEnd();
        }
        return false;
    }
    

};
class Solution2 {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        //构建字典树
        Trie * trieTree = new Trie();
        for(int i = 0;i < words.size();i++)
        {
            trieTree->insert(words[i],i);
        }
        for(int i = 0;i < words.size();i++)
        {
            for(int j = 0;j < words[i].size();j++ )
            {
                bool flag = check(words[i],0,j);
                if(flag)//前半截是回文
                {
                    string temp = words[i].substr(j+1);
                    reverse(temp.begin(),temp.end());
                    int index = -1;
                    if( trieTree->search(temp,index) )
                    {
                        if( i != index  )
                        {
                             res.push_back({index,i});
                             if( temp == "")
                             {
                                 res.push_back({i,index});
                             }
                        }
                           
                    }
                }
                flag = check(words[i],j+1,words[i].size()-1);
                if(flag)//后半截是回文
                {
                        string temp = words[i].substr(0,j+1);
                        reverse(temp.begin(),temp.end());
                        int index = -1;
                        if( trieTree->search(temp,index) )
                        {
                            if( i != index  )
                                res.push_back({i,index});
                        }
                }    
            }
        }
        return res;
    }
    bool check(string &vec,int left,int right)
    {
        int i = left;
        int j = right;
        while(i <= j)
        {
            if( vec[i] != vec[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};