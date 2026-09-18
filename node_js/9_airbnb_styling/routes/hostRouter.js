//Core module
const path = require('path');

//External module
const express = require('express');
const hostRouter = express.Router();

//Local Module
const rootDir = require('../utils/pathUtils.js');


hostRouter.get('/add-home',(req,res,next)=>{
    res.sendFile(path.join(rootDir,'','views','addHome.html'));
});
hostRouter.post('/add-home',(req,res,next)=>{
    console.log(req.body);
    res.sendFile(path.join(rootDir,'','views','homeAdded.html'))
});

module.exports = hostRouter;