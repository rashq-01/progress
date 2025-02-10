//Core module
const path = require('path');

//External module
const express = require('express');

//Local Module
const rootDir = require('../utils/pathUtils');

const userRouter = express.Router();

userRouter.get('/',(req,res,next)=>{
    res.sendFile(path.join(rootDir,'views','home.html'));
});

userRouter.get('/user/contact',(req,res,next)=>{
    res.sendFile(path.join(rootDir,'views','contact.html'));
});

exports.userRouter = userRouter;
