// Core Modules
const path = require('path');

// External Module
const express = require('express');
const userRouter = express.Router();

// Local Module
const registeredHomes = require('./hostRouter');
const userContoller = require('../controllers/homes');

userRouter.get("/", userContoller.getHome);

module.exports = userRouter;