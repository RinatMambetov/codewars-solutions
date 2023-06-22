package main

import (
	"fmt"
	"strings"
)

func duplicate_count(s1 string) int {
	s1 = strings.ToLower(s1)
	m := map[rune]int{}
	for _, v := range s1 {
		m[v]++
	}
	result := 0
	for _, v := range m {
		if v > 1 {
			result++
		}
	}
	return result
}

func main() {
	fmt.Println(duplicate_count("abcde"))          //0
	fmt.Println(duplicate_count("indivisibility")) //1
	fmt.Println(duplicate_count("aA11"))           //2
}
