//最大回文串
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> charmap(128,0);
        int maxlen=0,flag =0;
        for(int i = 0;i<s.size();i++){
            charmap[s[i]]++;
        }
        for (int i = 0;i<128;i++){
            if(charmap[i]%2==0){
                maxlen+=charmap[i];
            }
            else{
                maxlen+=(charmap[i]-1);
                flag =1;
            }
        }
        maxlen = maxlen+flag;
        return maxlen;

    }
};