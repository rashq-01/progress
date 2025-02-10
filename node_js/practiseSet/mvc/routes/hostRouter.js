//Core module
const path = require('path');

//External module
const express = require('express');

//Local Module
const rootDir = require('../utils/pathUtils');

const hostRouter = express.Router();

const details = [];

hostRouter.get('/listing',(req,res,next)=>{
    res.render('listing.ejs',{details});
});

hostRouter.post('/',(req,res,next)=>{
    details.push(req.body);
    console.log(req.body);
    res.sendFile(path.join(rootDir,'views','done.html'));
})

exports.hostRouter = hostRouter;
exports.detail = details;
