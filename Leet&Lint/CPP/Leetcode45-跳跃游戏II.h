class jumpgame{
/* 对于数组 [2,3,1,2,4,2,3]，初始位置是下标 0，从下标 0 出发，最远可到达下标 2。
下标 0 可到达的位置中，下标 1 的值是 3，从下标 1 出发可以达到更远的位置，因此第一步到达下标 1。
从下标 1 出发，最远可到达下标 4。下标 1 可到达的位置中，下标 4 的值是 4 ，
从下标 4 出发可以达到更远的位置，因此第二步到达下标 4。
只要找出边接维护就可以了。不要访问数组最后的一个值（因为在到达数组最后一个值之前边界肯定是大于或等于最后的地址的）
*/
public:
    int jump (vector &nums){
        int length = num.size();
        int end = 0;
        int maxPosition = 0;
        int steps = 0;
        for(auto i = 0;i<length -1;i++){
            maxPosition = max(maxPosition,i+nums[i]);
            if(i == end){
                end = maxPosition;
                steps++
            }
        }
        return steps;
    }
};