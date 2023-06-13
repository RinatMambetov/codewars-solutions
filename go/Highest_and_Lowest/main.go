package main

import (
	"fmt"
	// "sort"
	"strconv"
	"strings"
)

// func HighAndLow(in string) string {
// 	strArray := strings.Split(in, " ")
// 	var intArray []int
// 	for _, v := range strArray {
// 		i, err := strconv.Atoi(v)
// 		if err != nil {
// 			continue
// 		}
// 		intArray = append(intArray, i)
// 	}
// 	sort.Ints(intArray)
// 	return strconv.Itoa(intArray[len(intArray)-1]) + " " + strconv.Itoa(intArray[0])
// }

// gptver
func HighAndLow(numbers string) string {
	nums := strings.Fields(numbers)
	if len(nums) == 0 {
		return ""
	}
	max, min := atoi(nums[0]), atoi(nums[0])
	for _, n := range nums {
		if num := atoi(n); num > max {
			max = num
		} else if num < min {
			min = num
		}
	}
	return strconv.Itoa(max) + " " + strconv.Itoa(min)
}

func atoi(s string) int {
	n, _ := strconv.Atoi(s)
	return n
}

func main() {
	fmt.Println(HighAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4")) //42 -9
}
