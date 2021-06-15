impl Solution {
    pub fn peak_index_in_mountain_array(arr: Vec<i32>) -> i32 {
        let (mut l,mut r) = (0,arr.len() - 1);
        while l < r{
            let mid = l + (r - l) / 2;
            match arr[mid] > arr[mid + 1]{
                true => r = mid,
                false => l = mid + 1,
            }
        }
        l as i32
    }
}