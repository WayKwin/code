/*
 * @lc app=leetcode.cn id=122 lang=golang
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
func maxProfit(prices []int) int {
	sellIdx, buyIdx := 0, 0
	res := 0
	for i := 1; i < len(prices); i++ {
		if prices[i] <= prices[buyIdx] {
			buyIdx = i
		}
		sellIdx = i
		if sellIdx > buyIdx {
			res += prices[sellIdx] - prices[buyIdx]
			buyIdx = sellIdx
		}
	}
	return res
}

// @lc code=end

