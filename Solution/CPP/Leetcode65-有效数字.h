#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        size_t eps = s.find('e');
        size_t Eps = s.find('E');
        if(eps != string::npos){
            return ispurenumber(s.substr(0,eps),false)&&ispurenumber(s.substr(eps+1),true);
        }
        if(Eps != string::npos){
            return ispurenumber(s.substr(0,Eps),false) && ispurenumber(s.substr(Eps + 1),true);
        }
        return ispurenumber(s,false);
    }

    bool ispurenumber(string s,bool must_be_int){
        if(s.empty()) return false;
        int st = int(s[0] == '+' || s[0] == '-');
        bool has_dot = false,has_digit = false;
        for(int i = st;i < s.size();i++){
            if(s[i] == '.'){
                if(must_be_int) return false;
                if(has_dot) return false;
                has_dot = true;
            }else if(isdigit(s[i])){
                has_digit = true;
            }else{
                return false;
            }
        }
        return has_digit;
    }
};