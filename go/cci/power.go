package main

import (
	"flag"
	"fmt"
)

var (
	a = flag.Int("a", 0, "base")
	b = flag.Int("b", 0, "exp")
)

func main() {
	flag.Parse()
	fmt.Println(power(*a, *b))
}

func power(a, b int) int {
	if b < 0 {
		return 0 // error
	} else if b == 0 {
		return 1
	} else {
		return a * power(a, b-1)
	}
}
