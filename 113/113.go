package main

import (
	. "comm"
	"fmt"
)

/*
 * @lc app=leetcode.cn id=113 lang=golang
 *
 * [113] 路径总和 II
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
func dfs(root *TreeNode, sum int, result *[][]int, path *[]int) {
	if root == nil {
		return
	}
	*path = append(*path, root.Val)

	if sum-root.Val == 0 && root.Left == nil && root.Right == nil {
		// 大坑，如果二位切片直接append []int，保存的是地址。这里[]int内容会不停变
		//所以要使用deep copy
		tmp := append([]int{}, *path...)
		*result = append(*result, tmp)
	}
	dfs(root.Left, sum-root.Val, result, path)
	dfs(root.Right, sum-root.Val, result, path)
	pathvAlue := *path
	*path = pathvAlue[:len(pathvAlue)-1]
}
func pathSum(root *TreeNode, sum int) [][]int {
	if root == nil {
		return [][]int{}
	}
	result := [][]int{}
	path := []int{}
	dfs(root, sum, &result, &path)
	return result
}

// @lc code=end
func main() {
	arr := []interface{}{5, 4, 8, 11, nil, 13, 4, 7, 2, nil, nil, 5, 1}
	root := SliceToTree(arr)
	fmt.Println(pathSum(root, 22))
}
