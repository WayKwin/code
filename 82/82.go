package main

import . "comm"

/*
 * @lc app=leetcode.cn id=82 lang=golang
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	dummpyNode := &ListNode{1, nil}
	curNode := dummpyNode
	prevNode := head
	lastNode := head
	for prevNode != nil {
		for lastNode != nil && prevNode.Val == lastNode.Val {
			prevNode = prevNode.Next
		}
		prevNode = lastNode
		if prevNode.Next == lastNode {
			curNode.Next = prevNode
			curNode = prevNode
		}
	}
	return dummpyNode.Next
}

// @lc code=end
func main() {

}
