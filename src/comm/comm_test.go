package comm

import (
	"testing"
)

func TestComm(t testing.T) {
	s := []string{"1", "2", "5", "3", "4", "null", "6"}
	root := SliceToTree(s)
	t.Log("123")
	preOrder(root)
}
