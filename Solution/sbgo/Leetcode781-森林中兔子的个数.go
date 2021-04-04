package sbgo

func numRabbits(answers []int) int {
	if len(answers) == 0 {
		return 0
	}
	dic := make([]int, 1000)
	for i := range dic {
		dic[i] = 0x3f3f3f3f
	}
	dic[answers[0]] = 1
	res := answers[0] + 1
	for i := 1; i < len(answers); i++ {
		if dic[answers[i]] == 0x3f3f3f3f {
			dic[answers[i]] = 1
			res += answers[i] + 1
		} else {
			if answers[i] == 0 {
				res++
			} else if answers[i]+1 > dic[answers[i]] {
				dic[answers[i]]++
			} else {
				dic[answers[i]] = 1
				res += answers[i] + 1
			}
		}
	}
	return res
}
