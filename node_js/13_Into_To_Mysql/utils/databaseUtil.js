const mysql = require('mysql2');

const pool = mysql.createPool({
    host: 'localhost',
    user: 'root',
    password: '1122',
    database: 'airbnb',
});

module.exports = pool.promise();