package main

import (
	"fmt"
	"math"
	"sort"
)

// passing one function to another function as parameter
func diff(a int, b int) int {
	return a * b
}
func cal(f func(int, int) int) {
	fmt.Println(f(10, 20))
}

// create struct
type User struct {
	Name      string
	Age       int32
	Promotion bool
}

// methods for this struct -> call it like, mystr.GetName()
// its pass by value, so it will not change the original value of struct
// if you want to change the original value, use pointer receiver
// func (user *User) GetName() string {}
func (user User) GetName() string {
	return user.Name
}

// defer -> what it does is, it will execute "defer 3" at the end of the function,
// after all other statements are executed
func deferFunc() {
	fmt.Println("defer 1")
	fmt.Println("defer 2")
	defer fmt.Println("defer 3")
	fmt.Println("Hello World")
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
