package main

import "container/list"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	queue := list.New()
	queue.PushBack(root)
	reverseSwitch := false
	res := [][]int{}
	for queue.Len() > 0 {
		curSize := queue.Len()
		v := []int{}
		for i := 0; i < curSize; i++ {
			frontNode := queue.Front().Value.(*TreeNode)
			v = append(v, frontNode.Val)
			queue.Remove(queue.Front())
			// if reverseSwitch {
			if frontNode.Left != nil {
				queue.PushBack(frontNode.Left)
			}
			if frontNode.Right != nil {
				queue.PushBack(frontNode.Right)
			}
		}
		if reverseSwitch {
			for i, j := 0, len(v)-1; i < j; i, j = i+1, j-1 {
				v[i], v[j] = v[j], v[i]
			}
		}
		res = append(res, v)
		reverseSwitch = !reverseSwitch
	}
	return res
}
