package main

import . "comm"

func buildTree(preorder []int, inorder []int) *TreeNode {
	index := 0
	return core(preorder, inorder, 0, len(inorder), &index)
}
func core(preorder []int, inorder []int, inorderStart, inorderEnd int, index *int) *TreeNode {
	if inorderStart >= inorderEnd {
		return nil
	}
	rootIdex := inorderStart
	for i := inorderStart; i < inorderEnd; i++ {
		if inorder[i] == preorder[*index] {
			rootIdex = i
			break
		}
	}
	if rootIdex == inorderEnd {
		return nil // not find
	}
	root := &TreeNode{preorder[*index], nil, nil}
	*index++
	root.Left = core(preorder, inorder, inorderStart, rootIdex, index)
	root.Right = core(preorder, inorder, rootIdex+1, inorderEnd, index)
	return root
}
func main() {

}
