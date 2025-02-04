const express = require('express');
const parseBody = require('body-parser');
const bodyParser = require('body-parser');
const app = express();

app.use((req,res,next)=>{
    console.log('First Dummy MiddleWare',req.url,req.method);
    next();
})

app.use((req,res,next)=>{
    console.log('Second Dummy MiddleWare',req.url,req.method);
    next();
})

app.get('/',(req,res,next)=>{
    console.log('Handling / for Get: ',req.url,req.method);
    res.send(`<body><h1>Welcome to Form Page</h1><br><br> <a href="/contact-us">Click here to fill the form</a></body>`);
})

app.get('/contact-us',(req,res,next)=>{
    console.log('Handling for /contact-us Get ',req.url,req.method);
    res.send(`<body><form action="contact-us" method="POST"><input type="text" placeholder="username" name="username"><br><br> <input type="password" placeholder="password" name="password"><br><br><input type="submit"></form></body>`)
})

app.post('/contact-us',(req,res,next)=>{
    console.log('Handling for /contact-us POST ',req.url,req.method,req.body);
    next();
})

app.use(bodyParser.urlencoded());

app.post('/contact-us',(req,res,next)=>{
    console.log('Handling for /contact-us POST ',req.url,req.method,req.body);
    res.send(`<h1>Your entry Successfull</h1><br><br><h2>username: ${req.body.username}</h2><br><h2>password: ${req.body.password}`);
})


const PORT = 3000;
app.listen(PORT,()=>{
    console.log(`Server address: http://localhost:${PORT}`);
});
