//External Module
const express = require('express');

//Local Module
const rootDir = require('../utils/pathUtils');
const controller = require('../controller/all');

const bookRouter = express.Router();

bookRouter.get('/book-management',controller.getBookManagement);
bookRouter.post('/book-management',controller.postBookManagement);
bookRouter.get('/view-book',controller.getAllBook);


module.exports = bookRouter;

