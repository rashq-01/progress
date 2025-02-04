//Core module
const path = require('path');
//External module
const express = require('express');

//Local Module
const userRouter = require("./routes/userRouter");
const hostRouter = require('./routes/hostRouter');
const rootDir = require('./utils/pathUtils.js');

const app = express();

app.use((req,res,next)=>{
    console.log(req.url,req.method);
    next();
});

app.use(express.urlencoded());
//userRouter
app.use(userRouter);
//hostRouter
app.use('/host',hostRouter);

app.use((req,res,next)=>{
    res.status(404).sendFile(path.join(rootDir,'','views','404.html'));
})




const PORT = 4000;
app.listen(PORT,()=>{
    console.log(`Server started on http://localhost:${PORT}`);
});