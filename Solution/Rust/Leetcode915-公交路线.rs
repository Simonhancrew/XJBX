use std::collections::HashMap;
impl Solution {
    pub fn num_buses_to_destination(routes: Vec<Vec<i32>>, source: i32, target: i32) -> i32 {
        if target == source{
            return 0;
        }
        let n = routes.len();
        let mut que = Vec::new();
        let mut g = HashMap::new();
        let mut dist = vec![1e8 as i32;n];
        for i in 0..n{
            for &j in routes[i].iter(){
                if j == source{
                    que.push(i);
                    dist[i] = 1;
                }
                g.entry(j).or_insert(vec![]).push(i as i32);
            }
        }

        while que.len() > 0{
            let t = que[0];
            que.remove(0);
            for &x in routes[t as usize].iter(){
                if x == target{
                    return dist[t as usize]; 
                }
                if g.contains_key(&x){
                    for &y in g[&x].iter(){
                        if dist[y as usize] > dist[t as usize] + 1{
                            dist[y as usize] = dist[t as usize] + 1;
                            que.push(y as usize);
                        }
                    }
                    g.remove_entry(&x);
                }
            }
        }
        -1
    }
}