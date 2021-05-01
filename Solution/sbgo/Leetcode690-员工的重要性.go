package sbgo

func getImportance(employees []*Employee, id int) int {
	res := 0
	var dfs func(*Employee)
	dfs = func(ep *Employee) {
		res += ep.Importance
		if len(ep.Subordinates) == 0 {
			return
		}
		for _, idx := range ep.Subordinates {
			for _, epl := range employees {
				if idx == epl.Id {
					dfs(epl)
				}
			}
		}
		return
	}
	for i := range employees {
		if employees[i].Id == id {
			dfs(employees[i])
		}
	}
	return res
}
