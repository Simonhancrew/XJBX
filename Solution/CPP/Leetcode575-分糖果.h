class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> candy;
        for(auto i:candies){
            candy.insert(i);
        }
        return min(candy.size(),candies.size()/2);
    }
};