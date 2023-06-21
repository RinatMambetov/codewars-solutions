package main

import (
	"fmt"
	"sort"
)

func FindOdd(seq []int) int {
	if len(seq) == 1 {
		return seq[0]
	}
	sort.Ints(seq)
	count := 1
	for i := 1; i < len(seq); i++ {
		if seq[i] == seq[i-1] {
			count++
			continue
		}
		if seq[i] != seq[i-1] && (count%2) != 0 {
			return seq[i-1]
		}
		if seq[i] != seq[i-1] {
			count = 1
		}
	}
	return seq[len(seq)-1]
}

// gptver
// func FindOdd(seq []int) int {
// 	counts := make(map[int]int)
// 	for _, num := range seq {
// 		counts[num]++
// 	}
// 	for num, count := range counts {
// 		if count%2 != 0 {
// 			return num
// 		}
// 	}
// 	return -1
// }

func main() {
	n0 := []int{20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5}
	n1 := []int{1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5}
	fmt.Println(FindOdd(n0)) //5
	fmt.Println(FindOdd(n1)) //-1
}
