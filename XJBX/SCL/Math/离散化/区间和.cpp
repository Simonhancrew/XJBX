#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*

首先，离散话的实质就是我用all数组（这里我写的是idx）收集到所有可能用到的下标，这些下标满足在x的范围内。

之后这些下标可能是有重复的，将其去重就完了，这里存在第一个疑惑，为什么要去重呢？

之后，我开了一个数组a，我会把all数组中的位置映射到a中。

因为我更改和查询的所有点都是确定的，我把更改的点和需要查询的点映射到a中就可以实现一个缩放的操作。

比如我操作了200这个位置，在200这个位置+10，200这个数在all中是存在的，我找到all[idx] == 200,然后a[idx]就实际标识了200这位置的状态，a[idx] == 10就代表我在200这个位置加了10

再下面就可以处理前缀和了,实际处理的时候find函数返回+1是为了前缀和的方便处理，可以不用去考虑边界问题

之后思考那个疑惑的问题，不去重可以吗？可以的，至少能够ac，为什么？

因为all中所有的数都是实际用到的，虽然重复了，但是实际二分的时候还是只能找到端点的数。做+操作的时候我们只会给端点做操作，在查的时候其实是没有问题的。

去重带来了什么？

更小的all.size(),更少的遍历。

*/



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