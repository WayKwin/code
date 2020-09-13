/*
 * @lc app=leetcode.cn id=119 lang=golang
 *
 * [119] 杨辉三角 II
 */
// @lc code=start
func getRow(rowIndex int) []int {
	retSli := make([]int, rowIndex+1)
	cur := 1
	for i := 0; i <= rowIndex; i++ {
		retSli[i] = cur
		cur = cur * (rowIndex - i) / (i + 1)
	}
	return retSli
}

// @lc code=end

