package comm

import (
	"container/list"
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}
type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}
type ListNode struct {
	Val  int
	Next *ListNode
}

func SliceToList(s []int) *ListNode {
	dummpyNode := &ListNode{0, nil}
	cur := dummpyNode
	for _, val := range s {
		cur.Next = &ListNode{val, nil}
		cur = cur.Next
	}
	return dummpyNode.Next
}

func SliceToTree(s []interface{}) *TreeNode {
	queue := list.New()
	num, _ := s[0].(int)
	root := &TreeNode{num, nil, nil}
	queue.PushBack(root)
	cur := 1
	for cur < len(s) {
		l := queue.Len()
		for i := 0; i < l; i++ {
			front := queue.Front().Value.(*TreeNode)
			queue.Remove(queue.Front())
			if s[cur] == nil {
				front.Left = nil
			} else {
				num, _ = s[cur].(int)
				front.Left = &TreeNode{num, nil, nil}
				queue.PushBack(front.Left)
			}
			cur++
			if cur >= len(s) {
				break
			}
			if s[cur] == nil {
				front.Right = nil
			} else {
				num, _ = s[cur].(int)
				front.Right = &TreeNode{num, nil, nil}
				queue.PushBack(front.Right)
			}
			cur++
			// if front.Left == nil && front.Right == nil && cur < len(s) {
			// 	fmt.Println("input error")
			// 	break LOOP
			// }
		}
	}

	return root
}
func PreOrder(root *TreeNode) {
	if root == nil {
		return
	}
	fmt.Println(root.Val)
	PreOrder(root.Left)
	PreOrder(root.Right)
}

func InOrder(root *TreeNode) {
	if root == nil {
		return
	}
	InOrder(root.Left)
	fmt.Println(root.Val)
	InOrder(root.Right)
}
func Abs(a int) int {
	if a > 0 {
		return a
	}
	return -a
}
