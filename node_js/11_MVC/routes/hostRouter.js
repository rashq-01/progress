// External Module
const express = require('express');
const hostRouter = express.Router();

// Local Module
const homesController = require('../controllers/homes');

const registeredHomes = [];

hostRouter.get("/add-home", homesController.getAddHome)

hostRouter.post("/add-home", homesController.postAddhome)

exports.hostRouter = hostRouter;
exports.registeredHomes = registeredHomes;
