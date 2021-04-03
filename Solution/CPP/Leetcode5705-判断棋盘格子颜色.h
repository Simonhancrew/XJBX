#include <unordered_set>
using namespace std;
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        unordered_set<char> f{'a','c','e','g'};
        unordered_set<char> s{'1','3','5','7'};
        if(f.count(coordinates[0])){
            if(s.count(coordinates[1])){
                return false;
            }else{
                return true;
            }
        }else{
            if(s.count(coordinates[1])){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] - 'a' + coordinates[1] - '1') % 2;
    }
};