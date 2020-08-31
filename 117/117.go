package main

import (
	. "comm"
)

/*
 * @lc app=leetcode.cn id=117 lang=golang
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */
// 在 cur层，通过cut.next遍历完所有cur所处层的下一层所有节点,通过next将下一层节点全部连接起来
//双for循环是没有想到的
func connect(root *Node) *Node {
	n := root
	var prev, nextLevel *Node // prev是被连接这层的上一次成功连接的节点，nextLevel是这层的第一个节点。
	for n != nil {            // 来迭代吧，一直到节点世界的尽头。。。。。
		prev, nextLevel = nil, nil // 下一层目前还没有成功连接Next的节点，也找到下一层的第一个节点
		for n != nil {             // 循环到本层没节点为止
			connectNode(n.Left, &prev, &nextLevel)  // 尝试连接本层当前节点的Left child节点
			connectNode(n.Right, &prev, &nextLevel) // 尝试连接本层当前节点的Right child节点
			n = n.Next                              // 当前节点的children节点处理完，处理下一个节点
		}
		n = nextLevel // 这层的children都连接完了，那么该通过相同套路迭代刚刚连接完Next的这层了
	}
	return root
}

func connectNode(n *Node, prev, nextLevel **Node) {
	switch {
	case n == nil: // 这个节点是nil，直接返回
		return
	case *nextLevel == nil:
		*nextLevel = n // 这个节点是这层第一个不是nil的节点，也就是首节点
		*prev = n      // 因此也是第一个我们见到的活着的非nil节点
		return
	}
	(*prev).Next = n // 之前这层已经连接到了prev节点，那么prev节点的Next指向这个节点吧
	*prev = n        // 更新已经被连接完的这个节点为prev节点
}

// @lc code=end
