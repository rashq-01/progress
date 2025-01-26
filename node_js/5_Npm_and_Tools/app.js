const http = require("http");

const server = http.createServer((req,res)=>{
  console.log(req);
});
const PORT = 3000;
server.listen(PORT,()=>{
  console.log("Server stated on http://localhost:3000");
})