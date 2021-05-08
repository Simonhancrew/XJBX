#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
//最朴素的暴力
class Solution {
public:
    vector<int> ans;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<vector<int>> workers(k, vector<int>{});
        int res = 0;
        back(workers, 0, jobs, res);
        return *min_element(ans.begin(), ans.end());
    }
    void back(vector<vector<int>> &workers, int idx, vector<int>& jobs, int& res) {
        if (idx == jobs.size()) {
            int sum = 0;
            for (auto worker : workers)
                sum += worker.size();
            if(sum == jobs.size()) ans.push_back(res);
            return;
        }
        for (int i = idx; i < jobs.size(); i++) {
            for (auto &worker : workers) {
                worker.push_back(jobs[i]);
                int tmp = res;
                res = max(res, accumulate(worker.begin(), worker.end(), 0));
                back(workers, i + 1, jobs, res);
                res = tmp;
                worker.pop_back();
            }
        }
    }
};

//如果成立一个最小的值，那大于这个值的一定也成立=====一个区间，左半段都不成立，右边都chengli
//考虑二分（最大值最小问题模型）
//之后考虑剪枝的问题，某个worker的负载到达了limit或者为0的时候，继续下一个是没意义的
class Solution {
public:
    int k;
    vector<int> jobs;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        this->k = k;
        this->jobs = jobs;
        int l = *max_element(jobs.begin(),jobs.end()),r = accumulate(jobs.begin(),jobs.end(),0);
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
private:
    bool check(int limit){
        vector<int> workload(k,0);
        return back(workload,0,limit);
    }

    bool back(vector<int> &workloads,int idx,int limit){
        if(idx == jobs.size()) return true;
        int cur = jobs[idx];
        for(auto &workload:workloads){
            if(workload + cur <= limit){
                workload += cur;
                if(back(workloads,idx + 1,limit)) return true;
                workload -= cur;
            }           
            if(workload == 0 || workload + cur == limit) break;
        }
        return false;
    }
};