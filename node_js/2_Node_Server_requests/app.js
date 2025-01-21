<<<<<<< HEAD
const http = require('http');

const server = http.createServer((req,res)=>{
  console.log(req.url,req.method,req.headers);
  // process.exit();

})
const PORT = 3000;
server.listen(PORT,()=>{
  console.log(`Server running on address http://localhost:${PORT}`)
});
=======
const http = require('http');

const server = http.createServer((req,res)=>{
  console.log(req.url,req.method,req.headers);
  // process.exit();

})
const PORT = 3000;
server.listen(PORT,()=>{
  console.log(`Server running on address http://localhost:${PORT}`)
});
>>>>>>> 5862931 (a)
