class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k==0){
            return vector<int> ();
        }
        if(shorter == longer){
            return vector<int> {shorter*k};
        }
        vector<int> length(k+1);
        for(int i=0;i<=k;i++){
            length[i] = shorter*(k-i)+longer*(i);
        }
        return length;
    }
};