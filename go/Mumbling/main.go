package main

import (
	"fmt"
	"strings"
)

// func Accum(s string) string {
// 	acc := ""
// 	for i := 0; i < len(s); i++ {
// 		acc += strings.ToUpper(string(s[i]))
// 		for j := 0; j < i; j++ {
// 			acc += strings.ToLower(string(s[i]))
// 		}
// 		if i != len(s)-1 {
// 			acc += "-"
// 		}
// 	}
// 	return acc
// }

func Accum(s string) string {
	acc := ""

	for i, c := range s {
		if i != 0 {
			acc += "-"
		}

		acc += strings.ToUpper(string(c))

		for j := 0; j < i; j++ {
			acc += strings.ToLower(string(c))
		}
	}

	return acc
}

func main() {
	fmt.Println(Accum("abcd"))    //A-Bb-Ccc-Dddd
	fmt.Println(Accum("RqaEzty")) //R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy
	fmt.Println(Accum("cwAt"))    //C-Ww-Aaa-Tttt
	fmt.Println(Accum("ZpglnRxqenU"))
}
