package sbgo

type ThroneInheritance struct {
	king     string
	relation map[string][]string
	dead     map[string]bool
}

func Constructor(kingName string) ThroneInheritance {
	return ThroneInheritance{kingName, map[string][]string{}, map[string]bool{}}
}

func (t *ThroneInheritance) Birth(parentName string, childName string) {
	t.relation[parentName] = append(t.relation[parentName], childName)
}

func (t *ThroneInheritance) Death(name string) {
	t.dead[name] = true
}

func (t *ThroneInheritance) GetInheritanceOrder() []string {
	ans := []string{}
	var dfs func(string)
	dfs = func(name string) {
		if !t.dead[name] {
			ans = append(ans, name)
		}
		for _, childName := range t.relation[name] {
			dfs(childName)
		}
	}
	dfs(t.king)
	return ans
}
