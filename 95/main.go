package main

import "comm"
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(left, right int) []*TreeNode {
	if left > right {
		return []*TreeNode{nil}
	}
	var res []*TreeNode
	for i := left; i <= right; i++ {
		root := &TreeNode{i, nil, nil}
		leftNodes := dfs(left, i-1)
		rightNodes := dfs(i+1, right)
		for _, left := range leftNodes {
			for _, right := range rightNodes {
				root.Left = left
				root.Right = right
				res = append(res, root)
			}
		}
	}
	return res
}
func generateTrees(n int) []*TreeNode {
	return dfs(1, n)
}
func main() {
}
