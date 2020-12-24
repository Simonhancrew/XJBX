//探讨一下递归的时间复杂度
//本质上讲，递归就是一个系统给你压栈的过程
//求x的n次方，用递归求解，试着探讨不同的递归下不同的复杂度

//首先，最简单的循环，时间复杂度是n
int function(int x,int n) {
    int res = 1;
    for (int i = 0;i < n;i++){
        res = res * x;
    }
    return res;
}

//考虑递归，第一个版本.
//递归的复杂度分析，看他递归了多少次，每一次干了什么
//这里递归了n次，每次执行一个乘法
//所以时间复杂度还是n
int function2(int x,int n){
    if(n == 0){
        return 1;
    }
    return function2(x,n - 1)*x;
}


//尝试优化一下，这里面其实做了很多不必要运算
//此时的复杂度就难分析了很多，思考我在回溯问题里的回溯树，他其实就是一颗递归树
//一个求n次方，变成求两个n/2次方相乘
//我们画出递归树，他其实就是一个满二叉树，这里情况下，他其实还是n的复杂度
int function3(int x,int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 1){
        return function3(x,n/2)*function3(x,n/2)*x;
    }
    return function3(x,n/2)*function3(x,n/2);
}

//不如我去掉另一半的递归树？这里信息熵还可以减小
int function4(int x,int n){
    if(n == 0){
        return 1;
    }
    int cur = function4(x,n/2);
    if(n % 2 == 1){   
        return cur * cur * x;
    }
    return cur * cur;
}
