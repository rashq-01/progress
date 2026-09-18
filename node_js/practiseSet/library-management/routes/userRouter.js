//External Module
const express = require('express');

//Local Module
const rootDir = require('../utils/pathUtils');
const controller = require('../controller/all');

const userRouter = express.Router();

userRouter.get('/user-management',controller.getUserManagement);
userRouter.post('/user-management',controller.postUserManagement);
userRouter.get('/view-user',controller.getAlluser);


module.exports = userRouter;

