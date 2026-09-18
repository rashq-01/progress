//Core Module
const path = require('path');

//External Module
const express = require('express');

//Local module
const rootDir = require('../utils/pahtUtils.js');

const user = express.Router();

user.get('/',(req,res,next)=>{
    res.sendFile(path.join(rootDir,'views','home.html'));
});

user.get('/contact-us',(req,res,next)=>{
    res.sendFile(path.join(rootDir,'views','contact-us.html'));
});
user.post('/contact-us',(req,res,next)=>{
    console.log(req.body)
    res.sendFile(path.join(rootDir,'views','successfull.html'));
});



module.exports = user;