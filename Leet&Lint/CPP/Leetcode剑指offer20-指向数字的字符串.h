#include <string>
#include <unordered_map>
using namespace std;
//有限状态机
class Solution {
public:
    //字符中所有可能出现的状态
    enum State{
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,//e和前缀
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END//最后的空格
    };
    //所有的char的类型
    enum CHARTYPE{
        CHAR_SPACE,
        CHAR_SIGN,
        CHAR_INT,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_ILLEGAL
    };
    //字符到chartype转换
    CHARTYPE toCharType(char ch){
        if(ch == ' '){
            return CHAR_SPACE;
        }else if(ch == '+' || ch == '-'){
            return CHAR_SIGN;
        }else if(ch >= '0' && ch <= '9'){
            return CHAR_INT;
        }else if(ch == 'e' || ch == 'E'){
            return CHAR_EXP;
        }else if(ch == '.'){
            return CHAR_POINT;
        }else{
            return CHAR_ILLEGAL;
        }
    }
    //一个状态转换映射
    unordered_map<State,unordered_map<CHARTYPE,State>> transfer {
        {
            STATE_INITIAL,{
                {CHAR_SPACE,STATE_INITIAL},
                {CHAR_SIGN,STATE_INT_SIGN},
                {CHAR_INT,STATE_INTEGER},
                {CHAR_POINT,STATE_POINT_WITHOUT_INT}
            }
        },{
            //leetcode上 +- 符号之后不能有空格
            STATE_INT_SIGN,{
                {CHAR_INT,STATE_INTEGER},
                {CHAR_POINT,STATE_POINT_WITHOUT_INT}
            }
        },{
            STATE_INTEGER,{
                {CHAR_INT,STATE_INTEGER},
                {CHAR_EXP,STATE_EXP},
                {CHAR_POINT,STATE_POINT},
                {CHAR_SPACE,STATE_END}
            }
        },{
            STATE_POINT,{
                {CHAR_INT,STATE_FRACTION},
                {CHAR_EXP,STATE_EXP},
                {CHAR_SPACE,STATE_END}
            }
        },{
            STATE_POINT_WITHOUT_INT,{
                {CHAR_INT,STATE_FRACTION},
            }
        },{
            STATE_FRACTION,{
                {CHAR_INT,STATE_FRACTION},
                {CHAR_EXP,STATE_EXP},
                {CHAR_SPACE,STATE_END}
            }
        },{
            STATE_EXP,{
                {CHAR_SIGN,STATE_EXP_SIGN},
                {CHAR_INT,STATE_EXP_NUMBER},
            }
        },{
            STATE_EXP_SIGN,{
                {CHAR_INT,STATE_EXP_NUMBER}
            }
        },{
            STATE_EXP_NUMBER,{
                {CHAR_INT,STATE_EXP_NUMBER},
                {CHAR_SPACE,STATE_END}
            }
        },{
            STATE_END,{
                {CHAR_SPACE,STATE_END}
            }
        }
    };
    bool isNumber(const string &s){
        int len = s.size();
        State st = STATE_INITIAL;
        for(int i =0;i<len;i++){
            CHARTYPE type = toCharType(s[i]);
            if(transfer[st].find(type) == transfer[st].end()){
                return false;
            }else{
                st = transfer[st][type];
            }         
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};