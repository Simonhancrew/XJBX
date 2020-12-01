#include <string>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nameptr,typeptr;
        nameptr = 0,typeptr = 0;
        int len1 = name.size(),len2 = typed.size();
        while(nameptr < len1 && typeptr < len2){
            if(name[nameptr] == typed[typeptr]){
                ++nameptr;
                ++typeptr;
            }else{
                if(typeptr > 0 && typed[typeptr-1] == typed[typeptr]){
                    ++typeptr;
                }else{
                    return false;
                }
            }
        }
        if(nameptr == len1 && typeptr == len2){
            return true;
        }else if(nameptr == len1){
            while(typeptr < len2){
                if(typeptr > 0 && typed[typeptr-1] == typed[typeptr]){
                    typeptr++;
                }else{
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

//双指针
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.length()) {
            if (i < name.length() && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == name.length();
    }
};