#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//值域很大，需要的数狠稀疏
//做一下离散化
vector<int> all;//需要用到的实际坐标值
const int N = 3 * 1e5 + 10;//插入一个坐标，查找两个左边，乘数据范围然后 + 10
int a[N],s[N];//a是映射数组，存储的值是前n次输入加的值

//简单的讲就是all存的是数组的坐标，a存的是实际的值，利用实际需要的all中的数值，做离散，最后需要的就是a

typedef pair<int,int> PII;
vector<PII> add,query;//前几次的插入操作和查询操作

int find(int x){
    int l = 0,r = all.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(all[mid] >= x) r = mid;
        else l = mid + 1;
    } 
    return r + 1;//映射到1
}

int main(){
    int n,m;
    cin >> n >> m;
    //插入操作
    for(int i = 0;i < n;i++){
        int x,c;
        cin >> x >> c;
        add.push_back({x,c});
        all.push_back(x);
    }
    //储存查询操作
    for(int i = 0;i < m;i++){
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});
        all.push_back(l);
        all.push_back(r);
    }
    //排序 + 去重
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());

    //对于插入的处理
    for(auto &item : add){
        int x = find(item.first);
        a[x] += item.second;
    }
    //拿到前缀和
    for(int i = 1;i <= all.size();i++) s[i] = s[i-1] + a[i];
    //查询的处理
    for(auto &item:query){
        int l = find(item.first),r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}



vector<int>::iterator unique(vector<int> &input){
    int j = 0;
    int n = input.size();
    for(int i = 0;i < n;i++){
        if(!i || input[i] != input[i - 1]){
            input[j++] = input[i];
        }
    }
    //此时从a[0]-- a[j - 1]都是不重复的
    return input.begin() + j;
}


/*
离散化的模板

vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}

*/