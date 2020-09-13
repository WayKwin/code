package main

/*
 * @lc app=leetcode.cn id=33 lang=golang
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
func search(nums []int, target int) int {
	if nums == nil {
		return -1
	}
	lo := 0
	hi := len(nums) - 1
	for lo <= hi {
		mid := lo + (hi-lo)/2
		if target == nums[mid] {
			return mid
		}
		if nums[lo] <= nums[hi] { // in order
			if target < nums[lo] || target > nums[hi] { // not in range
				return -1
			}
			if target < nums[mid] {
				hi = mid - 1
			} else {
				lo = mid + 1
			}
		} else { // 旋转情况
			if target == nums[lo] {
				return lo
			}
			if target == nums[hi] {
				return hi
			}
			if nums[lo] <= nums[mid] { // 左边有序
				if target < nums[mid] && target > nums[lo] { //
					hi = mid - 1
				} else if target < nums[mid] && target < nums[lo] {
					lo = mid + 1
				} else if target > nums[mid] {
					lo = mid + 1
				}
			} else if nums[mid] < nums[hi] { //
				if target < nums[mid] {
					hi = mid - 1
				} else if target > nums[mid] && target > nums[hi] {
					hi = mid - 1
				} else if target > nums[mid] && target < nums[hi] {
					lo = mid + 1
				}
			}
		}
	}
	return -1
}

// @lc code=end
func main() {
	a := []int{4, 5, 6, 7, 0, 1, 2}
	search(a, 0)

}
