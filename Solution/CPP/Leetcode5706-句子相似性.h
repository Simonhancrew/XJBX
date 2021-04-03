#include <string>
#include <vector>
#include <sstream>

using namespace std;

//c++处理空格会麻烦一点
//往两边剔，要么插在左边了，要么插在右边了，要么插在中间了
//类似一个双端队列，头尾能够匹配到外部分pattern到的话就pop，追后应该是空的
//如果期间有不等于的部分说明在中间有异常部分

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size() > sentence2.size()) return areSentencesSimilar(sentence2,sentence1);
        stringstream s1(sentence1),s2(sentence2);
        string s;
        vector<string> a,b;
        while(s1 >> s) a.push_back(s);
        while(s2 >> s) b.push_back(s);
        int i = 0,j = a.size() - 1;
        for(int k = 0; k < b.size() && i < a.size();k++){
            if(a[i] == b[k]) i++;
            else break;
        }   
        for(int k = b.size() - 1;k >= 0 && j >= 0;k--){
            if(a[j] == b[k]) j--;
            else break;
        }
        return i > j;
    }
};