/*
 * @lc app=leetcode.cn id=93 lang=golang
 *
 * [93] 复原IP地址
 */
package main

import (
	"fmt"
	"strconv"
)

// @lc code=start
var oneResult []string
var result []string

func parse() (str string) {
	str = ""
	for index, val := range oneResult {
		if index != len(oneResult)-1 {
			str += val + "."
		} else {
			str += val
		}
	}
	return
}
func dfs(s string, curIndex int, charNum int, curLevel int) {
	for i := 0; i < 3; i++ {
		if curLevel == 4 {
			if curIndex >= len(s) {
				//check oneREsu
				result = append(result, parse())
			} else {
				return
			}
		}
		if curIndex >= len(s) || curIndex+i+1 > len(s) {
			return
		}
		//不能以0开头
		if s[curIndex] == '0' && i >= 1 {
			return
		}
		//判断是否 0 < x <= 255
		num, _ := strconv.Atoi(s[curIndex : curIndex+i+1])
		if num > 255 {
			continue
		}
		oneResult = append(oneResult, s[curIndex:curIndex+i+1])
		dfs(s, curIndex+i+1, i, curLevel+1)
		oneResult = oneResult[:len(oneResult)-1]
	}
	return
}

// 255.255.111.35
func restoreIpAddresses(s string) []string {
	result = result[:0]
	dfs(s, 0, 0, 0)
	return result
}

// @lc code=end
func main() {
	str := "010010"
	restoreIpAddresses(str)
	fmt.Println(result)
}
