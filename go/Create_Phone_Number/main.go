package main

import (
	"fmt"
	// "strconv"
)

// func CreatePhoneNumber(numbers [10]uint) string {
// 	numStr := make([]string, 10)
// 	for i, v := range numbers {
// 		numStr[i] = strconv.FormatUint(uint64(v), 10)
// 	}
// 	res := "(" + numStr[0] + numStr[1] + numStr[2] + ") " + numStr[3] + numStr[4] + numStr[5] + "-" + numStr[6] + numStr[7] + numStr[8] + numStr[9]
// 	return res
// }

// gptver
func CreatePhoneNumber(numbers [10]uint) string {
	numStr := make([]interface{}, 10)
	for i, v := range numbers {
		numStr[i] = v
	}
	return fmt.Sprintf("(%d%d%d) %d%d%d-%d%d%d%d", numStr...)
}

func main() {
	numbers := [10]uint{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}
	fmt.Println(CreatePhoneNumber(numbers)) //(123) 456-7890
}
