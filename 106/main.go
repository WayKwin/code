package main

import (
	. "comm"
)

func buildTree(inorder []int, postorder []int) *TreeNode {
	return core(inorder,postorder,0,len(inorder),0,len(postorder))
}
func core(inorder,postorder []int, inorderBegin,inorderEnd,postorderBegin,postorderEnd int) *TreeNode{
	if inorderBegin >= inorderEnd || postorderBegin >=postorderEnd{
		return nil
	}
	rootVal := postorder[postorderEnd - 1]
	leftLen := 0
	for i := inorderBegin; i < inorderEnd; i++{
		if inorder[i] == rootVal{
			leftLen = i - inorderBegin
			break;
		}
	}
	root := &TreeNode{rootVal, nil, nil}
	root.Left = core(inorder, postorder, inorderBegin,inorderBegin + leftLen,postorderBegin,postorderBegin+leftLen)
	root.Right = core(inorder,postorder,inorderBegin+leftLen+1,inorderEnd,postorderBegin+leftLen,postorderEnd - 1)
	return root
}
