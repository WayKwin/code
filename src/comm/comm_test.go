package comm

import (
	"testing"
)

func TestComm(t *testing.T) {
	s := []interface{}{1, 2, 5, 3, 4, nil, 6}
	root := SliceToTree(s)
	PreOrder(root)
}
