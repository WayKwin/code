package skiplist

import (
	"fmt"
	"math/rand"
	"testing"
	"time"
)

func (s *SkipList) AddToLv(key int, value interface{}, k int) {
	if s.hasKey(key) {
		return
	}
	//新的层数
	if k >= s.level {
		dummpyHead := &ListNode{0, nil, nil, nil}
		if k >= 1 {
			dummpyHead.down = s.JumpLevel[k-1]
		}
		s.JumpLevel = append(s.JumpLevel, dummpyHead)
		s.level++
	}
	s.addWithinLevel(key, value, k)
}

func TestInsert(t *testing.T) {
	skl := NewSkiplist()
	for _, data := range []struct {
		key   int
		inter interface{}
	}{
		{1, "2"},
		{4, "3"},
		{5, "3"},
		{6, "3"},
		{11, "3"},
		{9, "3"},
		{7, "3"},
		{10, "3"},
		{12, "3"},
		{2, "2"},
		{3, "3"},
	} {
		skl.Add(data.key, data.inter)
	}
	skl.Remove(3)
	printSkipList(skl)
	fmt.Println("XXXXXXXXXX")
	skl.Remove(4)
	printSkipList(skl)
	fmt.Println("XXXXXXXXXX")
	skl.Remove(1)
	printSkipList(skl)
	fmt.Println("XXXXXXXXXX")
	skl.Remove(12)
	printSkipList(skl)
}
func TestRandomInsert(t *testing.T) {
	skl := New
	r := rand.New(rand.NewSource(time.Now().Unix()))
	for i = 0; i < 100; i++ {
		r := r.Intn(100)

	}
}
