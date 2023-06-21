package main

import (
	"fmt"
	"strings"
)

func spin(s string) string {
	var res string
	for i := len(s) - 1; i >= 0; i-- {
		res += string(s[i])
	}
	return res
}

func SpinWords(str string) string {
	s := strings.Fields(str)
	var res []string
	for _, v := range s {
		if len(v) >= 5 {
			res = append(res, spin(v))
			continue
		}
		res = append(res, v)
	}
	return strings.Join(res, " ")
}

func main() {
	fmt.Println(SpinWords("Hey fellow warriors")) //Hey wollef sroirraw
}
