package main

/*
 * @lc app=leetcode.cn id=120 lang=golang
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
func minimumTotal(triangle [][]int) int {
	path := make([]int, len(triangle))
	for i := 0; i < len(triangle); i++ {
		path[i] = triangle[len(triangle)-1][i]
	}
	for i := len(triangle) - 2; i >= 0; i-- {
		for j := 0; j < len(triangle[i]); j++ {
			path[j] = triangle[i][j] + min(path[j], path[j+1])
		}

	}
	return path[0]
}
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// @lc code=end
