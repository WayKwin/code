package main

import "container/list"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	queue := list.New()
	queue.PushBack(root)
	res := [][]int{}
	for queue.Len() != 0 {
		v := []int{}
		curQueueSize := queue.Len()
		for i := 0; i < curQueueSize; i++ {
			v = append(v, queue.Front().Value.(*TreeNode).Val)
			node := queue.Front().Value.(*TreeNode)
			queue.Remove(queue.Front())
			if node.Left != nil {
				queue.PushBack(node.Left)
			}
			if node.Right != nil {
				queue.PushBack(node.Right)
			}
		}
		res = append(res, v)
	}
	return res
}
func main() {
}
