package skiplist

import (
	"fmt"
	r "math/rand"
	"time"
)

const INT_MAX = int(^uint(0) >> 1)
const INT_MIN = ^INT_MAX

// type Compareable interface {
// 	Bigger()
// }
type ListNode struct {
	key   int
	value interface{}
	next  *ListNode
	down  *ListNode
}
type SkipList struct {
	level     int
	s         *r.Rand
	JumpLevel []*ListNode
	maxLevel  int
}

func (s *SkipList) randomK() int {
	level := 1
	for r.Int()%2 == 1 {
		level++
	}
	if level < s.maxLevel {
		return level
	}
	return s.maxLevel
}
func NewSkiplist() *SkipList {
	return &SkipList{0, r.New(r.NewSource(time.Hour.Microseconds())), []*ListNode{}, 1024}
}
func (s *SkipList) addWithinLevel(key int, value interface{}, idx int) {
	var prevLvNode *ListNode = nil
	prev := s.JumpLevel[idx]
	var prevDown = prev.down
	for ; idx >= 0; idx-- {
		for ; prev != nil && prev.next != nil && prev.next.key < key; prev = prev.next {
		}
		if prev == nil {
		}
		// exists, just return
		if prev.next != nil && prev.next.key == key {
			return
		}
		node := &ListNode{key, nil, nil, nil}
		if idx == 0 {
			node.value = value
		}
		if prevLvNode != nil {
			prevLvNode.down = node
		}
		prevLvNode = node
		// insert to heaed
		tmp := prev.next
		prev.next = node
		node.next = tmp

		// go to next level
		prevDown = prev.down
		if prevDown != nil {
			prev = prevDown
		}
	}
}

func (s *SkipList) hasKey(key int) bool {
	if s.level == 0 {
		return false
	}
	dummpy := s.JumpLevel[s.level-1]
	prev := dummpy.next
	k := s.level - 1
	for k >= 0 {
		for prev != nil && prev.next != nil && prev.next.key < key {
			prev = prev.next
		}
		// could not reach this jug
		if prev == nil {
			return false
		}
		if prev.next != nil && prev.next.key == key {
			return true
		}
		// (cur.next.key > key  || cur.next == nil [bigger than this level])  go down
		prev = prev.down
		k--
	}
	return false
}

func (s *SkipList) Add(key int, value interface{}) {
	if s.hasKey(key) {
		return
	}
	k := s.randomK()
	//add new level
	if k > s.level {
		fmt.Println(k, s.level, key)
		for i := s.level; i < k; i++ {
			dummpyHead := &ListNode{INT_MIN, nil, nil, nil}
			s.JumpLevel = append(s.JumpLevel, dummpyHead)
			if i >= 1 {
				dummpyHead.down = s.JumpLevel[i-1]
			}
		}
		s.level = k
	}
	s.addWithinLevel(key, value, k-1)
}
func (s *SkipList) Remove(key int) {
	k := s.level - 1
	dummpy := s.JumpLevel[k]
	prev := dummpy
	for k >= 0 {
		dummpy := s.JumpLevel[k]
		for ; prev != nil && prev.next != nil && prev.next.key < key; prev = prev.next {
		}
		// could not reach this jug
		if prev == nil {
			return
		}
		// del this key
		if prev.next != nil && prev.next.key == key {
			prev.next = prev.next.next
		}
		// (cur.next.key > key  || cur.next == nil [bigger than this level])  go down
		nextLevel := prev.down
		if dummpy.next == nil { // remove this level
			s.JumpLevel = s.JumpLevel[:k]
			s.level--
		}
		prev = nextLevel
		k--
	}
	return

}

// for debug only print list when k is non-negetive int
func printSkipList(skl *SkipList) {
	placeholder := " "
	if skl == nil || skl.level < 1 {
		return
	}
	var a [][]interface{}
	tmp := []interface{}{}

	for cur := skl.JumpLevel[0].next; cur != nil; cur = cur.next {
		tmp = append(tmp, cur.key)
	}
	a = append(a, tmp)
	for k := 1; k < skl.level; k++ {
		b := []interface{}{}
		list := skl.JumpLevel[k].next
		for i := 0; list != nil && i < list.key; i++ {
			if list != nil && list.key == tmp[i] {
				b = append(b, list.key)
				list = list.next
			} else {
				b = append(b, placeholder)
			}
		}
		a = append(a, b)
	}
	for i := len(a) - 1; i >= 0; i-- {
		fmt.Print("-")
		for j := 0; j < len(a[i]); j++ {
			if a[i][j] == placeholder {
				fmt.Print("----")
			} else {
				fmt.Printf("->%2d", a[i][j])
			}
		}
		fmt.Println()
	}
}

// func (s *SkipList) HasKey(key int) bool {

// }
