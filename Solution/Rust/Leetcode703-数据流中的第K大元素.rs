use std::collections::BinaryHeap;
use std::cmp::Reverse;

struct KthLargest {
    min_heap:BinaryHeap<Reverse<i32>>,
    min_heap_size: usize,
}


impl KthLargest {

    fn new(k: i32, nums: Vec<i32>) -> Self {
        let mut r = KthLargest{
            min_heap:BinaryHeap::new(),
            min_heap_size:k as usize,
        };
        nums.into_iter().for_each(|n| {KthLargest::add(&mut r,n);});
        r
    }
    
    fn add(&mut self, val: i32) -> i32 {
        if self.min_heap.len() < self.min_heap_size{
            self.min_heap.push(Reverse(val));
        }else if self.min_heap.peek().unwrap().0 <val{
            self.min_heap.pop();
            self.min_heap.push(Reverse(val));
        }
        self.min_heap.peek().unwrap().0
    }
}