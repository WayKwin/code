package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

const (
	intMax = int(^uint(0) >> 1)  // 0111
	intMin = ^int(^uint(0) >> 1) // 1000
)

func isValidBST(root *TreeNode, min, max int) bool {
	if root == nil {
		return true
	}
	if min <= root.Val && root.Val <= max {
		if isValidBST(root.Left, min, root.Val) && isValidBST(root.Right, root.Val, max) {
			return true
		}
		return false
	}
	return false
}
func main() {
	print(intMin)
}
