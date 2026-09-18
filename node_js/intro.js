console.log("First node program");
const fs = require("fs");
fs.writeFile("Example.txt","Writting to the file",(err)=>{
  if(err){
    console.log("Error occured");
  }
  else{
    console.log("Dataa written to the file successfully...");
  }
})