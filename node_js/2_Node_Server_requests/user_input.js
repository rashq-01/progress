<<<<<<< HEAD
const http = require('http');
const fs = require('fs');
const server = http.createServer((req,res)=>{
  console.log(req.url,req.method,req.headers);
  // process.exit();
  if(req.url === '/'){
    res.setHeader('Content-Type',"text/html");
    res.write('<html>')
    res.write('<head><title>Testing</title></head>');
    res.write('<body><h1>Enter your details</h1>');
    res.write('<form action="/submit-details" method="POST">');
    res.write('<input type="text" id="name" name="name" placeholder="Enter Your Name"><br><br>');
    res.write('<lebel for="gender">Gender</lebel>');
    res.write('<input type="radio" name="gender" id="male" value="male">');
    res.write('<lebel for="male">Male</lebel>');
    res.write('<input type="radio" name="gender" id="female" value="female">');
    res.write('<lebel for="female">Female</lebel>');
    res.write('<button type="submit">Submit</button>');
    res.write('</form>')
    res.write('</body>');
    res.write('</html>');
    return res.end();
  }
  else if(req.url ==="/submit-details" && req.method==="POST"){
    fs.writeFileSync('example.txt','Rajesh Pandit');
    res.statusCode = 302;
    res.setHeader('location','/');
    return res.end();

  }

  else{
    res.setHeader('Content-Type',"text/html");
    res.write('<html>')
    res.write('<head><title>Testing</title></head>');
    res.write('<body><h1>This is Default Page</h1></body>');
    res.write('</html>');
  }
});

const PORT = 3000;
server.listen(PORT,()=>{
  console.log(`Server running on address http://localhost:${PORT}`)
});
=======
const http = require('http');
const fs = require('fs');
const server = http.createServer((req,res)=>{
  console.log(req.url,req.method,req.headers);
  // process.exit();
  if(req.url === '/'){
    res.setHeader('Content-Type',"text/html");
    res.write('<html>')
    res.write('<head><title>Testing</title></head>');
    res.write('<body><h1>Enter your details</h1>');
    res.write('<form action="/submit-details" method="POST">');
    res.write('<input type="text" id="name" name="name" placeholder="Enter Your Name"><br><br>');
    res.write('<lebel for="gender">Gender</lebel>');
    res.write('<input type="radio" name="gender" id="male" value="male">');
    res.write('<lebel for="male">Male</lebel>');
    res.write('<input type="radio" name="gender" id="female" value="female">');
    res.write('<lebel for="female">Female</lebel>');
    res.write('<button type="submit">Submit</button>');
    res.write('</form>')
    res.write('</body>');
    res.write('</html>');
    return res.end();
  }
  else if(req.url ==="/submit-details" && req.method==="POST"){
    fs.writeFileSync('example.txt','Rajesh Pandit');
    res.statusCode = 302;
    res.setHeader('location','/');
    return res.end();

  }

  else{
    res.setHeader('Content-Type',"text/html");
    res.write('<html>')
    res.write('<head><title>Testing</title></head>');
    res.write('<body><h1>This is Default Page</h1></body>');
    res.write('</html>');
  }
});

const PORT = 3000;
server.listen(PORT,()=>{
  console.log(`Server running on address http://localhost:${PORT}`)
});
>>>>>>> 5862931 (a)
