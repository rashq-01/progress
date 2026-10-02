const {Pool} = require('pg');

const pool = new Pool({
    user : 'postgres',
    host : 'localhost',
    database : 'postgres',
    password : 'postgres',
    port : 5432,
    max : 10
});

module.exports = pool;