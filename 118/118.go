package main

/*
 * @lc app=leetcode.cn id=118 lang=golang
 *
 * [118]
 */

// @lc code=start
func generate(numRows int) [][]int {
	if numRows < 1 {
		return [][]int{}
	}
	retSli := [][]int{{1}}
	for i := 1; i < numRows; i++ {
		sli := make([]int, i+1)
		sli[0] = 1
		sli[len(sli)-1] = 1
		for j := 1; j < len(sli)-1; j++ {
			prevSli := retSli[i-1]
			if j-1 >= 0 && j < len(prevSli) {
				sli[j] = prevSli[j-1] + prevSli[j]
			}
		}
		retSli = append(retSli, sli)
	}
	return retSli

}

// @lc code=end
