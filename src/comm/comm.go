package comm

import (
	"container/list"
	"fmt"
	"strconv"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func SliceToTree(s []string) *TreeNode {
	queue := list.New()
	num, _ := strconv.Atoi(s[0])
	root := &TreeNode{num, nil, nil}
	queue.PushBack(root)
	cur := 1
LOOP:
	for cur < len(s) {
		l := queue.Len()
		for i := 0; i < l; i++ {
			front := queue.Front().Value.(*TreeNode)
			queue.Remove(queue.Front())
			if s[cur] == "null" {
				front.Left = nil
			} else {
				num, _ = strconv.Atoi(s[cur])
				front.Left = &TreeNode{num, nil, nil}
				queue.PushBack(front.Left)
			}
			cur++
			if cur >= len(s) {
				break
			}
			if s[cur] == "null" {
				front.Right = nil
			} else {
				num, _ = strconv.Atoi(s[cur])
				front.Right = &TreeNode{num, nil, nil}
				queue.PushBack(front.Right)
			}
			cur++
			if front.Left == nil && front.Right == nil && cur < len(s) {
				fmt.Println("input error")
				break LOOP
			}
		}
	}

	return root
}
func preOrder(root *TreeNode) {
	if root == nil {
		return
	}
	fmt.Println(root.Val)
	preOrder(root.Left)
	preOrder(root.Right)
}
