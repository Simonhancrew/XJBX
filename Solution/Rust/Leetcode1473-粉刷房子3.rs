impl Solution {
    pub fn min_cost(houses: Vec<i32>, cost: Vec<Vec<i32>>, m: i32, n: i32, target: i32) -> i32 {
        let INF = 0x3f3f3f3f;
        let (m,n) = (m as usize ,n as usize);
        let target = target as usize;
        let mut dp = vec![vec![vec![INF;n + 1];target  + 1];m];

        if houses[0] != 0 {
            dp[0][1][houses[0] as usize] = 0
        }else{
            for i in 1..=n{
                dp[0][1][i ] = cost[0][i  - 1];
            }
        }
        for i in 1..m{
            for j in 1..=target{
                if houses[i] != 0{
                    let k = houses[i] as usize;
                    for u in 1..=n{
                        if u == k{
                            dp[i][j][k] = dp[i][j][k].min(dp[i - 1][j][u]);
                        }else{
                            dp[i][j][k] = dp[i][j][k ].min(dp[i - 1][j - 1][u]);
                        }
                    }
                }else{
                    for k in 1..=n{
                        for u in 1..=n{
                            if u == k{
                                dp[i][j][k] = dp[i][j][k ].min(dp[i - 1][j][u] + cost[i][k - 1]);
                            }else{
                                dp[i][j][k] = dp[i][j][k].min(dp[i - 1][j - 1][u] + cost[i][k - 1]);
                            }
                        }
                    }
                }
            }
        }
        let &res = dp[m - 1][target ].iter().min().unwrap();
        if res == INF{
            return -1;
        }
        res 
    }
}