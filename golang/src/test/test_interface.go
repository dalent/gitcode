package test

import (
	"fmt"
)

type Human struct {
	Name string
}

func (p Human) Sing() {
	fmt.Println("Human sing")
}

type Higher struct {
	Human
}

func (p Higher) Sing() {
	fmt.Println("Higher Sing")
}

type MySing interface {
	Sing()
}

func main() {
	var inter MySing
	test1 := Human{"Sing"}
	inter = test1
	inter.Sing()
	test2 := Higher{Human{"Sing"}}
	inter = test2
	inter.Sing()

}
