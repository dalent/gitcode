package main

import (
	"fmt"
	"reflect"
    "os"
    "io"
)

func init() {
	println("i'm going")
}

func test_slice() {
	arr := [5]rune{1, 2, 3, 4, 5}
	sli := arr[:]
	fmt.Print(arr)
	fmt.Print("\n")
	println("change content")
	sli[0] = 3
	fmt.Println(arr)
	fmt.Print(len(sli))
	fmt.Print("\n")
	fmt.Print(cap(sli))
	fmt.Print("\n")
	sli = append(sli, 6)
    print("sli:")
	fmt.Print(sli)
    print("arr:")
	fmt.Print(arr)
	fmt.Print("\n")

}
func test_make() {
	sli := make([]rune, 2, 8)
	fmt.Printf("append nothing %v\n", sli)
	fmt.Printf("len %v\n", len(sli))
	fmt.Printf("cap %v\n", cap(sli))
	fmt.Printf("point %p\n", &sli)
	sli = append(sli, 4)
	fmt.Printf("append 4 %v\n", sli)
	fmt.Printf("point %p\n", &sli)
}

func test_if() {
	var isTrue bool = true
	if isTrue {
		fmt.Print(isTrue)
	}

	isTrue = false
	if !isTrue {
		fmt.Print(isTrue)
	}
}

func test_goto() {
	i := 0
HERE:
	println(i)
	i++
	if i == 10 {
		return
	}
	goto HERE
}

func test_for() {
	for i := 0; i < 10; i++ {
		println(i)
	}

	i := 0
	for i < 10 {
		println(i)
		i++
	}
}
func test_switch() {
	info := 0
	switch info {
	case 0:
		println(0)
	case 1:
		println(1)
	case 2:
		println(2)
	default:
		println("default")
	}
}
func test_panic() {
	defer func() {
		if x := recover(); x != nil {
			println("panic recover")
		}
	}()
	i := 1 - 1
	value := 18 / i
	println(value)
}
func test_struct() {
	type Person struct {
		name string
		age  int
	}

	var person Person
	person.name = "jok"
	person.age = 20
	person = Person{"jok", 20}
	fmt.Printf("%v\n", person)
	person = Person{name: "jok1", age: 20}
	fmt.Printf("%v\n", person)
	person = *new(Person)
	fmt.Printf("%v\n", person)
}
func test_hiding() {
	type Human struct {
		name   string
		age    int
		weight int
	}

	type Student struct {
		Human      //匿名字段
		speciality string
	}

	mark := Student{Human{"Mark", 25, 120}, "computer Science"}
	fmt.Println("he's name is ", mark.name)
	fmt.Println("he's name is ", mark.age)
}

type Rectangle struct{
    width, height float32
}

func (r Rectangle) area(){
    fmt.Println("area is ", r.width*r.height)
}

func test_method(){

    r := Rectangle{10,10}
    r.area()
}

type Base struct{
    name string
}
func (b Base) Sing(){
    println(b.name, "is sing")
}
type High struct{
    Base
    name string
}

func (h High) Sing(){
    h.Base.Sing()
    println(h.name, "is sing")
}
type Interf interface{
    Sing()
}

func test_interface(){
    b := Base{"base"}
    h := High{Base{"base"},"high"}
    var ife Interf
    ife = b
    ife.Sing()
    ife = h
    ife.Sing()
}

func test_value(){
    type Element interface{}
    type List []Element
    type Person struct{
        name string
        age rune
    }
    list := make(List,3)
    list[0] = 1
    list[1] = "hello"
    list[2] = Person{"Dennis", 19}
    for index, element := range list{
        if value,ok := element.(int);ok{
            fmt.Printf("list[%d] is an int and its value is %d\n", index,value)
        }else if value,ok := element.(string);ok{
            fmt.Printf("list[%d] is an string and its value is %s\n", index,value)
        }else if value,ok := element.(Person);ok{
            fmt.Printf("list[%d] is an Person and its value is %v\n", index, value)
        }
    }
}
func test_reflect(){
    type Person struct{
        name string
        age rune
    }

    var i rune 
    v := reflect.ValueOf(i)
    fmt.Println("type: ", v.Elem().Field(0).String())
    println("kind: ", v.Kind())
}

func test_type(){
    var x float64 = 3.4
    v := reflect.ValueOf(x)
    fmt.Println("type:", v.Type())
    fmt.Println("kind is float64:", v.Kind() == reflect.Float64)
    fmt.Println("value", v.Float())
    fmt.Println("interface", v.Interface())
    type u float64 
    te := u(x)
    k := reflect.TypeOf(te)
    fmt.Println("type of", k)
}
func test_get(){
    var x uint8 = 'x'
    v := reflect.ValueOf(x)
    fmt.Println("type:", v.Type())
    fmt.Println("kind is uint8", v.Kind() == reflect.Uint8)
    x = uint8(v.Uint())
    println(x)
}
func test_reflect_struct(){
    type T struct{
        A int
        B string
    }

    t := T{23, "skidoo"}
    s := reflect.ValueOf(&t).Elem()
    typeOfT := s.Type()
    for i := 0; i < s.NumField(); i++{
        f := s.Field(i)
        fmt.Printf("%d:%s %s=%v\n",i, typeOfT.Field(i).Name, f.Type(), f.Interface())
    }

    s.Field(0).SetInt(77)
    s.Field(1).SetString("Sunset Strip")
    fmt.Println("t is now ", t)
}

func test_equal(){
    type MyInt int
    var   i int
    var   j int 

    i = 0
    j = 0
    var ii interface{} = i
    var jj interface{} = j
    if  ii == jj{
        println(true)
    }else{
        println(false)
    }
}
func test_reflect_interface(){
    var r io.Reader
    tty,err := os.OpenFile("/dev/tty", os.O_RDWR,0)
    if err != nil{
        return
    }

    r = tty
    fmt.Fprint(tty, "hello")

    var w io.Writer
    w = r.(io.Writer)
    fmt.Println(w)
}
func main() {
    //test_make()
    //test_if()
    //test_goto()
    //test_for()
    //test_switch()
    //test_panic()

    //test_struct()
    //test_hiding()
    //test_method()
    //test_interface()
    //test_type()
    //test_reflect()
    //test_slice()
    //test_type()
    //test_get()
    //test_reflect_struct()
    //test_equal()
    test_reflect_interface()
}
