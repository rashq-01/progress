const http = require("http");
// const testingSyntax = require('./syntax.js');
// const runtime = require('./runtimeError.js');
const logical = require('./logicalError.js');
const server = http.createServer((req,res)=>{
  console.log(req.url,req.method);
  // testingSyntax();
  // runtime();
  logical();
});
const PORT = 2000;
server.listen(PORT,()=>{
  console.log("Server stated on http://localhost:2000");
})