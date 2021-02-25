//自底向上的过程
//利用归并的思想去处理逆序对
//首先处理两边的逆序对，之后处理跨区间的逆序对
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N],temp[N];

//输入10w，最差情况是完全递减序，会爆int，大概是5 * (1e11)
typedef long long LL;

LL mergeSort(int l,int r){
    //递归的结束
	if(l >= r){
		return 0;
	}
	int mid = l + r >> 1;
	//自底向上，先递归去处理最底层的，然后一层层传递到递归树的顶部
	//此时之前的res都被记录返回
	LL res = mergeSort(l,mid) + mergeSort(mid + 1,r);
	int i = l,j = mid + 1,k = 0;
	while(i <= mid && j <= r){
		if(q[i] <= q[j]) temp[k++] = q[i++];
		else {
			temp[k++] = q[j++];
			res += mid - i + 1;
		}
	}
	//将缓存的数组放回原数组
	while(i <= mid) temp[k++] = q[i++];
	while(j <= r) temp[k++] = q[j++];
	for(int i =  l,j = 0;i <= r;i++,j++){
		q[i] = temp[j];
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> q[i];
	}
	cout << mergeSort(0,n-1)<< endl;
	
	return 0;
}