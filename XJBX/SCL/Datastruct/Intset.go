package datastruct

import (
	"bytes"
	"fmt"
)

type Intset struct {
	words []uint64
}

//一个bit数组的每一个2进制的bit位的0或1代表有没有这个数
//一个uint64是8字节，64个bit位，所以一个uint64数组可以看成是多个桶，每个桶可以容纳64个元素
//

func (s *Intset) Has(x int) bool {
	word, bit := x/64, x%64
	if len(s.words) > word && s.words[word]&(1<<bit) != 0 {
		return true
	} else {
		return false
	}
}

func (s *Intset) Add(x int) {
	word, bit := x/64, x%64
	for word >= len(s.words) {
		s.words = append(s.words, 0)
	}
	s.words[word] |= (1 << bit)
}

//两个bit数组的联合

func (s *Intset) Unionwith(t *Intset) {
	for i, tword := range t.words {
		if i < len(s.words) {
			s.words[i] |= tword
		} else {
			s.words = append(s.words, tword)
		}
	}
}

//string（）方法把它打印出来
func (s *IntSet) String() string {
	var buf bytes.Buffer
	buf.WriteByte('{')
	for i, word := range s.words {
		if word == 0 {
			continue
		}
		for j := 0; j < 64; j++ {
			if word&(1<<uint(j)) != 0 {
				if buf.Len() > len("{") {
					buf.WriteByte(' ')
				}
				fmt.Fprintf(&buf, "%d", 64*i+j)
			}
		}
	}
	buf.WriteByte('}')
	return buf.String()
}
