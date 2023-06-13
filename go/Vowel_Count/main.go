package main

import (
	"fmt"
	"strings"
)

func GetCount(str string) (count int) {
	var vovels string = "aeiou"
	for _, v := range str {
		if strings.Contains(vovels, string(v)) {
			count++
		}
	}
	return count
}

func main() {
	fmt.Println(GetCount("abracadabra"))
}
