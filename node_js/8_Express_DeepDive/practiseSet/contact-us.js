//Core Module
const path = require('path');

//External Module
const express = require('express');
const bodyParser = require('body-parser');

//Local Module
const userRouter = require('./routes/userRouter.js');
const hostRouter = require('./routes/hostRouter.js');
const rootDir = require('./utils/pahtUtils.js');

const app = express();

app.use((req,res,next)=>{
    console.log(req.url,req.method);
    next();
});

app.use(express.urlencoded());

app.use(userRouter);

app.use((req,res,next)=>{
    res.status(404).sendFile(path.join(rootDir,'','views','404.html'));
})


const PORT = 3000;
app.listen(PORT,()=>{
    console.log(`Server address: http://localhost:${PORT}`);
});
