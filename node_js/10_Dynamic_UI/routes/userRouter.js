//Core module
const path = require('path');

//External module
const express = require('express');

//Local Module
const { registeredHomes } = require('./hostRouter.js');

const userRouter = express.Router();


userRouter.get('/',(req,res,next)=>{
    console.log(registeredHomes);
    res.render('home',{registeredHomes: registeredHomes,pageTitle: 'airbnb'});
});

module.exports = userRouter;