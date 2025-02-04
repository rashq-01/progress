//Core module
const path = require('path');

//External module
const express = require('express');

//Local Module
const rootDir = require('../utils/pathUtils.js');

const userRouter = express.Router();


userRouter.get('/',(req,res,next)=>{
    res.sendFile(path.join(rootDir, 'views', 'home.html'))
});

module.exports = userRouter;