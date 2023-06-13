package main

import (
	"fmt"
	"strings"
)

// func Disemvowel(comment string) string {
// 	vovels := "aeuioAEUIO"
// 	var result string
// 	for _, v := range comment {
// 		if strings.Contains(vovels, string(v)) {
// 			continue
// 		}
// 		result += string(v)
// 	}
// 	return result
// }

// gptver
func Disemvowel(comment string) string {
	vowels := "aeiouAEIOU"
	var result strings.Builder
	for _, char := range comment {
		if !strings.ContainsRune(vowels, char) {
			result.WriteRune(char)
		}
	}
	return result.String()
}

func main() {
	fmt.Println(Disemvowel("This website is for losers LOL!"))
}
