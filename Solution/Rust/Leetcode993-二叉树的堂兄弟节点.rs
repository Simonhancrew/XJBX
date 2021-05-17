use std::rc::Rc;
use std::cell::RefCell;
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn is_cousins(root: Option<Rc<RefCell<TreeNode>>>, x: i32, y: i32) -> bool {
        type Tree = Option<Rc<RefCell<TreeNode>>>;
        fn find(root: Tree, x: i32, p: Tree, l: i32) -> Option<(Tree, i32)> {
            let l1 = l + 1;
            if let Some(node) = &root {
                let node = node.borrow();
                if node.val == x {
                    return Some((p, l1)); 
                } else {
                    if let Some(r) = find(node.left.clone(), x, root.clone(), l1) {
                        return Some(r);
                    }
                    if let Some(r) = find(node.right.clone(), x, root.clone(), l1) {
                        return Some(r);
                    }
                }
            }
            None
        }

        let (f1, l1) = find(root.clone(), x, None, 0).unwrap();
        let (f2, l2) = find(root.clone(), y, None, 0).unwrap();
        f1 != f2 && l1 == l2
    }
}