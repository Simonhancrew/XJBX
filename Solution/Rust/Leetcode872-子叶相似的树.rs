use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn leaf_similar(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut vec1:Vec<i32> = Vec::new();
        let mut vec2:Vec<i32> = Vec::new();
        Self::get_node(root1, &mut vec1);
        Self::get_node(root2, &mut vec2);
        vec1 == vec2
    }
    pub fn get_node(root: Option<Rc<RefCell<TreeNode>>>,vec:&mut Vec<i32>){
        if let Some(mut node) = root{
            if node.borrow().left == None && node.borrow().right == None{
                vec.push(node.borrow().val);
            }
            Self::get_node(node.borrow_mut().left.take(),vec);
            Self::get_node(node.borrow_mut().right.take(),vec);
        }
    }
}