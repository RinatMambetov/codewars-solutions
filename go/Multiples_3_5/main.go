package main

import (
	"fmt"
)

func Multiple3And5(number int) int {
	if number < 1 {
		return 0
	}
	sum := 0
	for i := 3; i < number; i++ {
		if i%3 == 0 || i%5 == 0 {
			sum += i
		}
	}
	return sum
}

func main() {
	fmt.Println(Multiple3And5(10)) //23
}
