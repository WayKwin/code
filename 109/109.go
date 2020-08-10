package main

import (
	. "comm"
)

/*
 * @lc app=leetcode.cn id=109 lang=golang
 *
 */

// @lc code=start
var Head *ListNode

func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	Head = head
	cur := head
	l := 0
	for ; cur != nil; cur = cur.Next {
		l++
	}
	return inorder(0, l)
}
func inorder(l, r int) *TreeNode {
	if l < 0 || l >= r {
		return nil
	}
	node := &TreeNode{1, nil, nil}
	node.Left = inorder(l, l+(r-l)/2)
	node.Val = Head.Val
	Head = Head.Next
	node.Right = inorder((l+(r-l)/2)+1, r)
	return node
}

// @lc code=end
func main() {
	array := []int{0, 1, 2, 3, 4, 5}
	list := SliceToList(array)
	a := sortedListToBST(list)
	InOrder(a)
}
