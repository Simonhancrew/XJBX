use std::collections::{HashMap, HashSet};
struct ThroneInheritance {
    king:String,
    relation:HashMap<String,Vec<String>>,
    dead:HashSet<String>
}
impl ThroneInheritance {

    fn new(kingName: String) -> Self {
        Self{
            king:kingName,
            relation:HashMap::new(),
            dead:HashSet::new()
        }
    }
    
    fn birth(&mut self, parent_name: String, child_name: String) {
        self.relation.entry(parent_name).or_insert(Vec::new()).push(child_name)
    }
    
    fn death(&mut self, name: String) {
        self.dead.insert(name);
    }
    
    fn get_inheritance_order(&self) -> Vec<String> {
        let mut ans = Vec::new();
        self.pre_order(&self.king, &mut ans);
        ans
    }
    
    fn pre_order(&self, name: &String, ans: &mut Vec<String>) {
        if !self.dead.contains(name) {
            ans.push(name.to_string());
        }
        
        self.relation.get(name).unwrap_or(&vec![]).iter().for_each(|child| self.pre_order(child, ans));
    }
}