package main
import(
   _ "github.com/go-sql-driver/mysql"
   "database/sql"
   "fmt"
   "time"
)
func init(){
    fmt.Print("i'm inited")
}

func main(){
  db,err := sql.Open("mysql", "root:@/home?charset=utf8")
  if  err != nil {
    return
  }
  fmt.Print("begin\n")

  defer func (){
      if x := recover(); x != nil{
          main()
      }
  }()

  defer func(){
      fmt.Print("end\n")
      db.Close()
  }()

  //test := 1- 1
  //test1 := 1/test
  // fmt.Print(test1)
  fmt.Print(time.Now())
  for i :=0; i< 1000000;i++{
      if( i % 100 == 0){
          fmt.Printf("%v start \n", time.Now())
      }
      stmt,_ := db.Prepare("insert userinfo(username) values('hah')")
      _,_ = stmt.Exec()

      if( i % 100 == 0){
          fmt.Printf("%v end \n", time.Now())
      }
  }
  fmt.Print(time.Now())
}
