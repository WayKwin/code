package  main

import ."comm"
func sortedArrayToBST(nums []int) *TreeNode {
return core(nums,0,len(nums))
}
func core(nums []int,  begin, end int)*TreeNode{
if(begin  >= end){
return nil
}
mid := (begin + end) / 2
root := &TreeNode{nums[mid], nil, nil}
root.Left = core(nums,begin,mid)
root.Right = core(nums,mid+1,end)
return root
}