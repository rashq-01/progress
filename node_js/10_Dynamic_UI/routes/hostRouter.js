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

const registeredHomes = [];

hostRouter.post('/add-home',(req,res,next)=>{
    console.log('Home registration successful for: ',req.body,req.body.houseName);
    registeredHomes.push({houseName: req.body.houseName});
    res.sendFile(path.join(rootDir,'','views','homeAdded.html'))
});

exports.hostRouter = hostRouter;
exports.registeredHomes = registeredHomes;