#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//如何枚举一个二进制子集？
/*
    do{
        sub = (sub - 1) & mask;
    }while(sub != mask)
*/
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> freq;

        for(auto &str:words){
            int mask = 0;
            for(auto &chr:str){
                mask |= (1 << (chr - 'a'));
            }
            ++freq[mask];
        }

        vector<int> ans;
        for(auto &puzzle:puzzles){
            int total = 0;
            int mask = 0;
            for(int i = 1;i < 7;i++){
                mask |= (1 << (puzzle[i] - 'a'));
            }
            int subset = mask;
            do {
                int s = subset | (1 << puzzle[0] - 'a');
                if(freq.count(s)){
                    total += freq[s];
                }
                subset = (subset - 1) & mask;
            }while(subset != mask);
            ans.push_back(total);
        }
        return ans;
    }
};