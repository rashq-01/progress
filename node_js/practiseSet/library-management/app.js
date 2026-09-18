//External Module
const express = require('express');

//Local module
const rootDir = require('./utils/pathUtils');
const homeRouter = require('./routes/homeRouter');
const bookRouter = require('./routes/bookRouter');
const userRouter = require('./routes/userRouter');

const app = express();

app.use(express.urlencoded({extended: true}));
app.use(express.json());
app.set('view engine', 'ejs');
app.set('views','views');

app.use('/',(req,res,next)=>{
    console.log(req.url);
    next();
});

//HomeRouter
app.use(homeRouter);

//BookRouter
app.use('/book',bookRouter);

//UserRouter
app.use('/user',userRouter)




const PORT = 5000;

app.listen(PORT,()=>{
    console.log(`Server Started on http://localhost:${PORT}`);
});