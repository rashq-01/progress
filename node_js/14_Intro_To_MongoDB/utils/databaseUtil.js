const mongo = require('mongodb');

const MongoClient = mongo.MongoClient;

const MONGO_URL = 'mongodb+srv://root:1122@rajeshpandit.bjr5n.mongodb.net/?retryWrites=true&w=majority&appName=RajeshPandit';

let _db;

const mongoConnect = (callback) => {

    MongoClient.connect(MONGO_URL).then(client => {
        callback();
        _db = client.db('airbnb');
    }).catch(err => {
        console.log('Error while connecting to Mongo: ',err);
    });
}

const getDB = () =>{
    if(!_db){
        throw new Error('Mongo not connected');
    }
    return _db;
}

exports.getDB = getDB;
exports.mongoConnect = mongoConnect;