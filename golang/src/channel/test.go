package main
import "fmt"
type Hua struct{
   name string
   age uint32
}
func main(){
  defer fmt.Println("test")
  c := make(chan Hua, 2)
  c <- Hua{"test",12}
  c <-  Hua{"test", 20}
  fmt.Println(<-c)
  fmt.Println(<-c)
}
