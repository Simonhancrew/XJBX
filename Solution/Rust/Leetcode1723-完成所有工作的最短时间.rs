impl Solution {
    pub fn minimum_time_required(jobs: Vec<i32>, k: i32) -> i32 {
        if jobs.len()==0{
            return 0;
        }
        let mut beg = jobs.iter().max().unwrap().clone();
        let mut end:i32 = jobs.iter().sum();
        let k = k as usize;
        if jobs.len()==k{
            return beg;
        }
        let mut mid = (beg + end)>>1;
        while beg < end {
            mid = (beg + end)>>1;
            let mut work_times = vec![0;k ];
            if Self::dfs(0, &jobs[..], mid, k , &mut work_times[..]){
                end = mid;
            }else{
                beg = mid+1;
            }
        }
        beg

    }
    fn dfs(curjob_id: usize, jobs: &[i32], mid: i32, k: usize, work_times: &mut [i32]) -> bool {
        if curjob_id == jobs.len(){
            return true;
        }
        for worker in 0..k {
            if work_times[worker] + jobs[curjob_id] <= mid {
                work_times[worker] += jobs[curjob_id];
                if Self::dfs(curjob_id + 1, jobs, mid, k, work_times) {
                    return true;
                }

                work_times[worker] -= jobs[curjob_id];
            }

            if work_times[worker] == 0 {
                return false;
            }
        }
        false
    }
}