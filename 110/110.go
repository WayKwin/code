package main

import (
	. "comm"
)

/*
 * @lc app=leetcode.cn id=110 lang=golang
 *
 * [110] 平衡二叉树
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
func core(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := core(root.Left)
	if left == -1 {
		return -1
	}
	right := core(root.Right)
	if right == -1 {
		return -1
	}
	deepth := left - right
	if deepth < 0 {
		deepth = -deepth
	}
	if deepth > 1 {
		return -1
	}
	if left > right {
		return left + 1
	}
	return right + 1
}
func isBalanced(root *TreeNode) bool {
	return core(root) >= 0
}

// @lc code=end
