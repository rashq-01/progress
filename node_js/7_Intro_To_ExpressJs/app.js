//Local module
const userRequestHandler = require('./user.js');

// External Module
const express = require('express');

const app = express();

app.get('/',(req,res,next)=>{
  console.log('came in first middleWare', req.url, req.method);
  // res.send('<p>came from first MiddleWare</p>');
  next();
});


app.post('/submit-details',(req,res,next)=>{
  console.log('Came in second middleWare', req.url, req.method);
  res.send('<p>Welcome to Complete Coding NodeJS series');
});


app.use('/',(req,res,next)=>{
  console.log(req.url, req.method);
  console.log('Came in another middleWare');
  res.send('<p>Came from another Middleware</p>');
});

const PORT = 2000;
app.listen(PORT,()=>{
  console.log(`Server stated on http://localhost:${PORT}`);
});