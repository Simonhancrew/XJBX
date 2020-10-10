//计算给定日期之间的天数
//计算公元元年到该日期分别多少天，然后相减
#include <cmath>
const int days = 365;
const int s[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

//闰年
bool isLeap(int y){
    if(y%400 == 0 || y%100 == 0|| y%4 == 0){
        return 0;
    }
}

int leap(int y){
    if(!y) return 0;
    return y/4-y/100+y/400;
}

int calcu(int day,int mon,int year){
    int res = (year -1)*days+leap(year-1);
    for(int i = 1;i<mon;++i){
        res += s[i];
    }
    if(isLeap(year)&&mon>2){
        res++;
    }
    res += day;
    return res;
}

int count_day(int da,int ma,int ya,int db,int mb,int yb){
    int resa = calcu(da,ma,ya);
    int resb = calcu(db,mb,yb);
    return abs(resa-resb);
}