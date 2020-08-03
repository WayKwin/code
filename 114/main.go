import . "comm"
func flatten(root *TreeNode)  {
    core(root)
}
 var last *TreeNode
func core(root* TreeNode) *TreeNode{
    if root == nil{
        return nil
    }
    root.Left = core(root.Left)
    root.Right = core(root.Right)
    if root.Left != nil{
        r := root.Right
        root.Right = root.Left
        node := root.Right
        for node.Right != nil{ // TODO 记录前驱节点
            node = node.Right
        }
        node.Right = r
    }
    root.Left = nil

    return root
}