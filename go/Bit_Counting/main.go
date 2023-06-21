package main

import (
	"fmt"
	"strconv"
	"strings"
)

func CountBits(n uint) int {
	s := strconv.FormatUint(uint64(n), 2)
	return strings.Count(s, "1")
}

func main() {
	fmt.Println(CountBits(10)) //2
}
