package main

import (
	"fmt"
	"strings"
)

// func FindShort(s string) int {
// 	slice := strings.Split(s, " ")
// 	minLength := 1000
// 	for _, word := range slice {
// 		if len(word) < minLength {
// 			minLength = len(word)
// 		}
// 	}
// 	return minLength
// }

// gptver
func FindShort(s string) int {
	words := strings.Fields(s)
	shortest := len(s)
	for _, word := range words {
		if len(word) < shortest {
			shortest = len(word)
		}
	}
	return shortest
}

func main() {
	fmt.Println(FindShort("bitcoin take over the world maybe who knows perhaps"))                //3
	fmt.Println(FindShort("turns out random test cases are easier than writing out basic ones")) //3
	fmt.Println(FindShort("Let's travel abroad shall we"))                                       //2
}
