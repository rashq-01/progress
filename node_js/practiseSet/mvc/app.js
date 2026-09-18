//Core Module
const path = require('path');

//External Modul
const express = require('express');

//Local Module
const rootDir = require('./utils/pathUtils');
const {userRouter} = require('./routes/userRouter');
const {hostRouter} = require('./routes/hostRouter');

const app = express();

app.set('view engine', 'ejs');

app.use(express.urlencoded());

app.use('/',(req,res,next)=>{
    console.log(req.method,req.url);
    next();
});

//User Router
app.use(userRouter);

//Host Router
app.use('/host',hostRouter)
app.use(hostRouter)



const PORT = 4000;

app.listen(PORT,()=>{
    console.log(`Server started on http://localhost:${PORT}`);
});