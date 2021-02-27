package sbgo

func longestSubstring(s string, k int) int {
	ret, n := 0, len(s)

	for i := 0; i <= 26; i++ {
		l, r := 0, 0
		less, total := 0, 0
		cnt := make([]int, 26)
		for r < n {
			cnt[s[r]-'a']++
			if cnt[s[r]-'a'] == 1 {
				less++
				total++
			}
			if cnt[s[r]-'a'] == k {
				less--
			}

			for total > i {
				cnt[s[l]-'a']--
				if cnt[s[l]-'a'] == k-1 {
					less++
				}
				if cnt[s[l]-'a'] == 0 {
					total--
					less--
				}
				l++
			}
			if less == 0 {
				ret = max(ret, r-l+1)
			}
			r++
		}
	}
	return ret
}
