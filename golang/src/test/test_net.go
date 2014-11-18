package main 
import (
    "net"
    "fmt"
    "os"
)

func main(){
    if len(os.Args) != 2{
        fmt.Fprintf(os.Stderr, "Usage: %s ip-addr\n", os.Args[0])
        os.Exit(0)
    }

    name := os.Args[1]
    addr := net.ParseIP(name)
    if addr == nil{
        fmt.Println("invalid address")
    }else{
        fmt.Println("The Address is ", addr.String())
    }

    os.Exit(0)
}

