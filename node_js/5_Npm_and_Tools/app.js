const http = require("http");

const server = http.createServer((req,res)=>{
  console.log(req);
});
const PORT = 2000;
server.listen(PORT,()=>{
  console.log("Server stated on http://localhost:3000");
})