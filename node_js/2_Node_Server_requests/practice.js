<<<<<<< HEAD
const http = require('http');

const server = http.createServer((req,res)=>{
    if(req.url === '/'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<a href="/home">Home</a><br>')
        res.write('<a href="/men">Men</a><br>')
        res.write('<a href="/women">Women</a><br>')
        res.write('<a href="/kids">Kids</a><br>')
        res.write('<a href="/cart">Cart</a><br>')
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/home'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to Home Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/men'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to Men Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/women'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to Women Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/kids'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to Kids Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/cart'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to cart Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else{
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Error 404 Not Found');
        res.write('</body>');
        res.write('</html');
        return res.end(); 
    }

})
server.listen(2000,()=>{
    console.log('Server running on address http://localhost:2000');
});
=======
const http = require('http');

const server = http.createServer((req,res)=>{
    if(req.url === '/'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<a href="/home">Home</a><br>')
        res.write('<a href="/men">Men</a><br>')
        res.write('<a href="/women">Women</a><br>')
        res.write('<a href="/kids">Kids</a><br>')
        res.write('<a href="/cart">Cart</a><br>')
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/home'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to Home Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/men'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to Men Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/women'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to Women Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/kids'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to Kids Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else if(req.url.toLowerCase() === '/cart'){
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Welcome to cart Page');
        res.write('</body>');
        res.write('</html');
        return res.end();
    }
    else{
        res.setHeader('Content-Type',"text/html");
        res.write('<html>');
        res.write('<head><title>Myntra</title></head>');
        res.write('<body>');
        res.write('<h1>Error 404 Not Found');
        res.write('</body>');
        res.write('</html');
        return res.end(); 
    }

})
server.listen(2000,()=>{
    console.log('Server running on address http://localhost:2000');
});
>>>>>>> 5862931 (a)
