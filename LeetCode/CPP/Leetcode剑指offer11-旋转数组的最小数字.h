#include <vector>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        for(int i = 1;i<numbers.size();i++){
            if(numbers[i-1]>numbers[i]){
                return numbers[i];
            }
        }
        return numbers[0];
    }
};