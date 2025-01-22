const userRequest = require("./user.js");
const http = require("http");

const server = http.createServer(userRequest);
const PORT = 3000;
server.listen(PORT,()=>{
  console.log("Server stated on http://localhost:3000");
})