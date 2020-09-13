/*
 * @lc app=leetcode.cn id=121 lang=golang
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
func maxProfit(prices []int) int {
	sellIdx, buyIdx := 0, 0
	res := 0
	for i := 1; i < len(prices); i++ {
		if prices[i] < prices[buyIdx] {
			buyIdx = i
		}
		sellIdx = i
		if sellIdx > buyIdx {
			curVal := prices[sellIdx] - prices[buyIdx]
			if curVal > res {
				res = curVal
			}
		}
	}
	return res
}

// @lc code=end

