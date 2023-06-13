package main

import (
	"fmt"
)

func GetMiddle(s string) string {
	l := len(s)
	if l < 3 {
		return s
	}
	if l%2 == 0 {
		return s[l/2-1 : l/2+1]
	} else {
		return s[l/2 : l/2+1]
	}
}

func main() {
	fmt.Println(GetMiddle("test"))    //es
	fmt.Println(GetMiddle("testing")) //t
	fmt.Println(GetMiddle("middle"))  //dd
	fmt.Println(GetMiddle("A"))       //A
}
