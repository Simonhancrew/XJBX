#include <iostream>
#include <cstring>
using namespace std;



//N时小于40的
const int N = 40;

int n,m;
int input[N][N];
bool nums[N];


bool check_row(){
    for(int i = 0;i < m;i++){
        memset(nums,0,sizeof(nums));
        for(int j = 0;j < m;j++){
            int tmp = input[i][j];
            if(tmp < 1 || tmp > m){
                return false;
            }
            if(nums[tmp]) return false;
            nums[tmp] = true;
        }
    }    
    return true;
}


bool check_col(){
    for(int i = 0;i < m;i++){
        memset(nums,0,sizeof(nums));
        for(int j = 0;j < m;j++){
            int tmp = input[j][i];
            if(tmp < 1 || tmp > m) return false;
            if(nums[tmp]) return false;
            nums[tmp] = true;
        }
    }    
    return true;
}

//唯一有价值的就是checkcell的操作
bool check_cell(){
    for(int i = 0;i < m;i += n){
        for(int j = 0;j < m;j += n){
            memset(nums,0,sizeof(nums));
            //choose offset
            for(int di = 0;di < n;di++){
                for(int dj = 0;dj < n;dj++){
                    int tmp = input[i + di][j + dj];
                    if(tmp < 1 || tmp > m) return false;
                    if(nums[tmp]) return false;
                    nums[tmp] = true;
                }
            }
        }
    }
    return true;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int a = 1;a <= T;a++){
        scanf("%d",&n);
        m = n * n;
        //input all the data ex
        for(int i = 0; i < m ;i++){
            for(int j = 0;j < m;j++){
                scanf("%d",&input[i][j]);
            }
        }
        if(check_row() && check_col() && check_cell()){
            cout << "Case #" << a << ": Yes\n";
        }else{
            cout << "Case #" << a << ": No\n";
        }
    }
    return 0;
}
