const http = require('http');
const server = http.createServer((req,res)=>{
    if(req.url === '/'){
        res.setHeader('Content-Type','text/html');
        res.write(`<html>
    <head><title>Calculator</title></head>
    <body>
        <h1>Welcome To Calculator</h1>
        <a href="calculator">Click here to use Calculator</a>
    </body>
</html>`)
        res.end();
    }
    else if(req.url.toLowerCase() === '/calculator'){
        res.setHeader('Content-Type','text/html');
        res.write(`<html>
    <head><title>Calculator</title></head>
    <body>
        <h1>Welcome To Calculator</h1>
        <form action="submition" method="POST">
            <input type="number" placeholder="num1" name="num1">
            <select name="operation" id="operation">
                <option value="+">+</option>
                <option value="-">-</option>
                <option value="*">*</option>
                <option value="/">/</option>
            </select>
            <input type="number" placeholder="num2" name="num2">
            <br><br>
            <button type="submit">Calculate</button>
        </form>
    </body>
</html>`)
        res.end();
    }
    else if(req.url.toLocaleLowerCase() === '/submition' && req.method === 'POST'){
        const chunksArray = [];
        req.on('data',(chunks)=>{
            chunksArray.push(chunks);
        })
        req.on('end',()=>{
            const bufferData = Buffer.concat(chunksArray).toString();
            const param = new URLSearchParams(bufferData);
            console.log(param);
            const obj = Object.fromEntries(param);
            console.log(obj);
            
            const n1 = parseInt(obj['num1']);
            const n2 = parseInt(obj['num2']);
            var opr = obj['operation'];
            var result;
            if(opr == '+'){
                result = n1 + n2;
            }
            else if(opr == '-'){
                result = n1 - n2;
            }
            else if(opr == '*'){
                result = n1 * n2;
            }
            else{
                result = n1 / n2;
            }

            res.setHeader('Content-Type','text/html');
            res.write(`<html>
    <head><title>Calculator</title></head>
    <body>
        <h1>The result is ${result}</h1>
        <br><br><a href="/calculator">Click here to got back</a>
    </body>
</html>`)
res.end();
            
        })

    }


})

server.listen(3000,()=>{
    console.log('Server started on http://localhost:3000');
})