package main

import (
	"fmt"
)

// func getsum(n int) int {
// 	sum := 0
// 	for i := n; i != 0; {
// 		sum += i % 10
// 		i /= 10
// 	}
// 	return sum
// }

// func DigitalRoot(n int) int {
// 	sum := 0
// 	for i := n; i > 9; {
// 		i = getsum(i)
// 		sum = i
// 	}
// 	return sum
// }

// gptver
func DigitalRoot(n int) int {
	sum := n
	for sum > 9 {
		var digitSum int
		for sum > 0 {
			digitSum += sum % 10
			sum /= 10
		}
		sum = digitSum
	}
	return sum
}

func main() {
	// n0 := []int{20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5}
	// n1 := []int{1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5}
	fmt.Println(DigitalRoot(16))     //7
	fmt.Println(DigitalRoot(132189)) //6
	fmt.Println(DigitalRoot(493193)) //2
	// fmt.Println(getsum(1624))
}
