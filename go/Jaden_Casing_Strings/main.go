package main

import (
	"fmt"
	"strings"
)

func ToJadenCase(str string) string {
	result := strings.ToUpper(string(str[0]))
	for i := 1; i < len(str); i++ {
		if str[i-1] == ' ' {
			result += strings.ToUpper(string(str[i]))
		} else {
			result += string(str[i])
		}
	}
	return result
}

func main() {
	fmt.Println(ToJadenCase("How can mirrors be real if our eyes aren't real")) //"How Can Mirrors Be Real If Our Eyes Aren't Real"
}
