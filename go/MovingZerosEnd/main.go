package main

import (
	"fmt"
)

func MoveZeros(arr []int) []int {
	r := []int{}
	c := 0
	for _, v := range arr {
		if v != 0 {
			r = append(r, v)
		} else {
			c++
		}
	}
	for c > 0 {
		r = append(r, 0)
		c--
	}
	return r
}

func main() {
	v1 := []int{1, 2, 0, 1, 0, 1, 0, 3, 0, 1}
	fmt.Println(MoveZeros(v1)) //1, 2, 1, 1, 3, 1, 0, 0, 0, 0
}
