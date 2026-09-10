package main

import (
	"fmt"
	"math"
	"sort"
)

// create struct
type User struct {
	Name      string
	Age       int32
	Promotion bool
}

func main() {

	// creating slice of variable size
	n := 1000
	arr := make([]int32, n)
	fmt.Println(arr)

	// to copy one slice to another
	arr2 := make([]int32, n)
	copy(arr2, arr) // -> copy arr elements to arr2

	// create struct object
	myuser := User{"sujal", 22, true}
	fmt.Println(myuser)

	// using floor and log2
	var_1 := 10000
	result := math.Floor(math.Log2(float64(var_1)))
	fmt.Println(result)

	// sort slice -> ascending
	vec1 := []int{1213, 11, 2, 4, 23213, 211, 1}
	sort.Slice(vec1, func(i, j int) bool {
		return vec1[i] < vec1[2]
	})

	// use lower bound to get index
	idx := sort.Search(len(vec1), func(i int) bool {
		return vec1[i] >= var_1
	})
	fmt.Println(vec1[idx])

}
