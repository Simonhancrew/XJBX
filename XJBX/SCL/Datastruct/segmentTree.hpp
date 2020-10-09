#include <vector>
#include <iostream>
using namespace std;
//线段树的每个子结点的left和right刚好就是原数组中的位置
//树的递归构造都有模板
/*{
    if(终止条件){
        do something
        return;
    }
    递归构造左树
    递归构造右树
    当前节点值？
}
更理想自己stack
*/
class segmentTree{
public:
    //构造一哈
    segmentTree(const vector<int> &nums){
        if(nums.size()==0) return;
        //线段树的values数组一般都开4倍原数组大小
        _values.resize(4*nums.size());
        _mostRight = nums.size()-1;
        buildSegmentTree(_values,nums,0,0,_mostRight);
    }
    //更新线段树
    void update(int i,int newValues){
        updateSegmentTree(_values,0,0,_mostRight,i,newValues);
    }
    //求和
    int Sum(int i,int j){
        //
        return sumRangeSegmentTree(_values,0,0,_mostRight,i,j);
    }
    
private:
    vector<int> _values;
    //记录一下原数组右端点，更新的时候会用到
    int _mostRight;
    //构建一颗线段树，其中nums是原数组，values是线段树数组，pos是当前节点在线段树中的下标
    void buildSegmentTree(vector<int>&values,const vector<int> &nums,int pos,int left,int right){
        //从当前的pos开始
        if(left == right){
            //这是一个叶节点，随便赋值为左右都可以.到达子叶节点之后就没必要往下走了
            values[pos] = nums[right];
            return;
        }
        //递归的构建左右子树
        int mid = (left+right)/2;
        buildSegmentTree(values,nums,2*pos+1,left,mid);
        buildSegmentTree(values,nums,2*pos+2,left,mid);
        //父节点的值就是两个已经构建的子结点的和
        //手法像个憨批
        values[pos] = values[2*pos+1] + values[2*pos+2];
    }
    //打印出整个树
    void printWholeTree(const vector<int> &values,int pos,int left,int right,int layer){
        for(int i = 0;i<layer;i++){
            cout<<'-';
        }
        cout<< "[left,right][pos]:"<<values[pos];
        if(left == right) return;
        int mid = (left+right)/2;
        //递归的打印左子树和右子树
        printWholeTree(values,2*pos+1,left,mid,layer+1);
        printWholeTree(values,2*pos+2,mid+1,right,layer+1);
    }
    //线段树的求和
    int sumRangeSegmentTree(const vector<int> &values,int pos,int left,int right,int realLeft,int realRight){
        //就三种情况，无交集，有交集，全包含，优化的时候可以把交集和包含写到一起
        //无交集
        if(realLeft>right||realRight<left){
            return 0;
        }
        //整个包含在[realLeft,realRight]
        else if(realLeft<=left&&realRight>=right){
            //只要进入交集直接返回
            return values[pos];
        }
        //返回覆盖区域交集的和
        else{
            int mid = (left+right)/2;
            int subLeft = sumRangeSegmentTree(values,2*pos+1,left,mid,realLeft,realRight);
            int subRight = sumRangeSegmentTree(values,2*pos+2,mid+1,right,realLeft,realRight);
            return subLeft+subRight;
        }
    }
    //index是需要更新的位置（在原nums数组中的的位置），newValues是需要更新的值
    void updateSegmentTree(vector<int> &values,int pos,int left,int right,int index,int newValues){
        //到达子叶节点，且节点的坐标刚刚好是index
        if(right == left && index == right){
            values[index] = newValues;
            return;//出栈，往上更新之前的的递归函数
        }
        int mid = (left+right)/2;
        //index在那边？？？？？，只去递归的更新需要更新的子树！！！！！！！！！！！！
        if(index<=mid){
            updateSegmentTree(values,2*pos+1,left,mid,index,newValues);
        }else
        {
            updateSegmentTree(values,2*pos+2,mid+1,right,index,newValues); /* code */
        }    
        //更新当前节点的值，同样的手法
        values[pos] = values[2*pos+1]+values[2*pos+2];    
    }
};