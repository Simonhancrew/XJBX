#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> Ak;
        reverse(A.begin(),A.end());
        while(K != 0){
            int cur = K % 10;
            Ak.push_back(cur);
            K = K / 10;
        }
        bool carry = false;
        int lowsize = min(Ak.size(),A.size());
        vector<int> ans;
        calcu2vec(lowsize,A,Ak,ans,carry);
        if(lowsize < A.size()){
            calcuremain(lowsize,A,ans,carry);
        }else if (lowsize < Ak.size()){
            calcuremain(lowsize,Ak,ans,carry);
        }else{
            if(carry){
                ans.push_back(1);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    void calcu2vec(int lowsize,vector<int> &A,vector<int> &Ak,vector<int>& ans,bool &carry){
        for(int i = 0;i <lowsize;i++){
            int cur = Ak[i] + A[i];
            if(carry){
                cur += 1;
                carry = false;
            }
            if(cur >= 10){
                carry = true;
            }
            cur = cur % 10;
            ans.push_back(cur);
        }
    }
    void calcuremain(int lowsize,vector<int> &input,vector<int> &ans,bool &carry){
        for(int i = lowsize;i < input.size();i++){
                int cur = input[i];
                if(carry){
                    cur += 1;
                    carry = false;
                }
                if(cur >= 10){
                    carry = true;
                }
                cur = cur % 10;
                ans.push_back(cur);
            }
        if(carry){
            ans.push_back(1);
        }
    }
};