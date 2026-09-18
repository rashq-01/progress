const http = require('http');

const server = http.createServer((req,res)=>{
  console.log(req.url,req.method,req.headers);
  // process.exit();
  if(req.url === '/'){
    res.setHeader('Content-Type',"text/html");
    res.write('<html>')
    res.write('<head><title>Testing</title></head>');
    res.write('<body><h1>This is Main Page</h1></body>');
    res.write('</html>');
    return res.end();
  }
  else if(req.url.toLowerCase() === '/products'){
    res.setHeader('Content-Type',"text/html");
    res.write('<html>')
    res.write('<head><title>Testing</title></head>');
    res.write('<body><h1>This is Product Page</h1></body>');
    res.write('</html>');
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