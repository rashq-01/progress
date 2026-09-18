const express = require('express');

const app = express();

app.use((req,res,next)=>{
    console.log(req.url);
    next();
});

app.use((req,res,next)=>{
    console.log(req.method);
    next();
});

app.use((req,res,next)=>{
    // res.send("<h1>Response Sent by third Middleware");
    next();
});

app.get('/',(req,res,next)=>{
    console.log('HomePage');
    next();
});

app.get('/contact-us',(req,res,next)=>{
    console.log('Get-ContactUs  Page');
    res.send(`<html>
    <head>
        <title>Form</title>
    </head>
    <body>
        <form action="contact-us" method="post">
            <input type="text" placeholder="Username">
            <br>
            <input type="password" placeholder="password">
            <br>
            <button type="submit">Submit</button>
        </form>
    </body>
</html>`);
});
app.post('/contact-us',(req,res,next)=>{
    console.log('POST-ContactUs Page');
    res.send('<h1>You entered.......</h1>');
    next();
});

const PORT = 3000;
app.listen(PORT,()=>{
    console.log(`Server started on http://localhost:${PORT}`);
})