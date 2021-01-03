package sbgo

func findTheDifference(s string, t string) byte {
	var ss, st byte
	for _, chr := range s {
		ss += byte(chr)
	}
	for _, chr := range t {
		st += byte(chr)
	}
	return st - ss
}

//计数
// func findTheDifference(s, t string) byte {
//     cnt := [26]int{}
//     for _, ch := range s {
//         cnt[ch-'a']++
//     }
//     for i := 0; ; i++ {
//         ch := t[i]
//         cnt[ch-'a']--
//         if cnt[ch-'a'] < 0 {
//             return ch
//         }
//     }
// }
//找奇数次出现的chr
// func findTheDifference(s, t string) (diff byte) {
//     for i := range s {
//         diff ^= s[i] ^ t[i]
//     }
//     return diff ^ t[len(t)-1]
// }
