//External Module
const express = require('express');

//Local Module
const rootDir = require('../utils/pathUtils');
const controller = require('../controller/all');

const homeRouter = express.Router();

homeRouter.get('/',controller.getHome);


module.exports = homeRouter;

