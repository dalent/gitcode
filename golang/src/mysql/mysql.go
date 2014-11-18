package main
import(
   _ "github.com/go-sql-driver/mysql"
   "database/sql"
   "fmt"
   "time"
   "runtime"
)
func init(){
    fmt.Print("i'm inited")
}

func main(){
  //db,err := sql.Open("mysql", "root:@/home?charset=utf8")
  //if  err != nil {
  //  return
  //}
  fmt.Print("begin\n")

  defer func (){
      if x := recover(); x != nil{
          main()
      }
  }()

  //defer func(){
  //    fmt.Print("end\n")
  //    db.Close()
  //}()

  //test := 1- 1
  //test1 := 1/test
  // fmt.Print(test1)
  fmt.Print(time.Now())
  runtime.GOMAXPROCS(2)
  closed1 := make(chan int)
  closed2 := make(chan int)
//  go func(){
//      db,err := sql.Open("mysql", "root:@/home?charset=utf8")
//      if  err != nil {
//          return
//      }
//
//      defer func(){
//          fmt.Print("end\n")
//          db.Close()
//      }()
//
//
//      for i :=0; i< 1000000;i++{
//          if( i % 100 == 0){
//              fmt.Printf("go1 %v start \n", time.Now())
//          }
//          stmt,_ := db.Prepare("insert userinfo(username) values('hah')")
//          _,_ = stmt.Exec()
//
//          if( i % 100 == 0){
//              fmt.Printf("go1 %v end \n", time.Now())
//          }
//      }
//
//      closed1 <- 0
//
//  }()
//
  go func(){
      db,err := sql.Open("mysql", "root:@/home?charset=utf8")
      if  err != nil {
          return
      }

      defer func(){
          fmt.Print("end\n")
          db.Close()
      }()


      for i :=0; i< 1000000;i++{
          if( i % 100 == 0){
              fmt.Printf("go2 %v start \n", time.Now())
          }
          stmt,_ := db.Prepare("insert userinfo(username) values(?)")
          _,_ = stmt.Exec("';delete from userinfo;")

          if( i % 100 == 0){
              fmt.Printf("go2 %v end \n", time.Now())
          }
      }

      closed2 <- 0
  }()


  select {
  case <-closed1:
      println("go1 closed")
  case <- closed2:
      println("go2 closed")
  //default:
  //    time.Sleep(5 * time.Second)
  //    println("5 second passed")
  }
  fmt.Print(time.Now())
}
