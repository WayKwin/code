package main

import (
	. "comm"
)

/*
 * @lc app=leetcode.cn id=111 lang=golang
 *
 * [111]
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := minDepth(root.Left)
	right := minDepth(root.Right)
	if left == 0 && right == 0 {
		return 1
	}
	//跟节点不是叶子结点
	if left == 0 || right == 0 {
		if left == 0 {
			return right + 1
		}
		return left + 1
	}
	if left > right {
		return right + 1
	}
	return left + 1
}

// @lc code=end
