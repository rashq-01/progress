const express = require('express');
const pool = require("./db.js");

const app = express();

app.use(express.json());

app.post('/users' , async(req,res)=>{
    const {name , email} = req.body;

    try{
        const result = await pool.query(`INSERT INTO users (name , email) VALUES ($1 , $2) RETURNING *`,[name , email]);

        res.status(201).json(result.rows[0]);
    }catch(err){
        console.error(err);
        res.status(500).json({error : "Failed to create user",message : err.message});
    }

});

app.get('/users' , async(req,res)=>{
    try{
        const result = await pool.query(`SELECT * FROM users ORDER BY id DESC`);
        res.status(200).json(result.rows);
    }catch(err){
        res.status(500).json({error : "Failed to Fetch from the database",message : err.message});
    }
});

app.listen(3000 , ()=>{
    console.log("Server started on port 3000");
});