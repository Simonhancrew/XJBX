package sbgo

func findNumOfValidWords(words []string, puzzles []string) []int {
	freq := make(map[int]int)
	for _, word := range words {
		mask := 0
		for _, char := range word {
			mask |= (1 << (char - 'a'))
		}
		freq[mask]++
	}

	ans := []int{}

	for _, puzzle := range puzzles {
		mask := 0
		for _, char := range puzzle {
			mask |= (1 << (char - 'a'))
		}
		total := 0
		subset := mask
		for subset != 0 {
			if 1<<(puzzle[0]-'a')&subset != 0 {
				total += freq[subset]
			}
			subset = (subset - 1) & mask
		}
		ans = append(ans, total)
	}
	return ans
}
