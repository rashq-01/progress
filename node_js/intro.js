<<<<<<< HEAD
console.log("First node program");
const fs = require("fs");
fs.writeFile("Example.txt","Writting to the file",(err)=>{
  if(err){
    console.log("Error occured");
  }
  else{
    console.log("Data written to the file successfully...");
  }
})
=======
const http = require('http');
const server = http.createServer((req,res)=>{
  console.log("Someone clicked On this");
})

const PORT = 2000;
server.listen(PORT,()=>{
  console.log("Server stated");
})

>>>>>>> 5862931 (a)
