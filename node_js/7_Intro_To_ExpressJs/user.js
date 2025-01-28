const fs = require("fs");
const userRequestHandler = (req, res) => {
  if (req.url === "/") {
    res.setHeader("Content-Type", "text/html");
    res.write("<html>");
    res.write("<head><title>Complete Coding</title></head>");
    res.write("<body><h1>Enter Your Details:</h1>");
    res.write('<form action="/submit-details" method="POST">');
    res.write(
      '<input type="text" name="username" placeholder="Enter your name"><br>'
    );
    res.write('<label for="male">Male</label>');
    res.write('<input type="radio" id="male" name="gender" value="male" />');
    res.write('<label for="female">Female</label>');
    res.write(
      '<input type="radio" id="female" name="gender" value="female" />'
    );
    res.write('<br><input type="submit" value="Submit">');
    res.write("</form>");
    res.write("</body>");
    res.write("</html>");
    return res.end();
  } else if (
    req.url.toLowerCase() === "/submit-details" &&
    req.method == "POST"
  ) {
    const body = [];
    req.on("data", (chunk) => {
      body.push(chunk);
    });

    req.on("end", () => {
      const finaldata = Buffer.concat(body).toString();
      const param = new URLSearchParams(finaldata);
      const bodyobject = Object.fromEntries(param);
      console.log(JSON.stringify(bodyobject));
      fs.writeFile("user.txt", JSON.stringify(bodyobject),(error)=>{
        console.log('Data Written Successfully');
        res.statusCode = 302;
        res.setHeader('Location' , '/');
        return res.end();
      });
    });
  }
  else{
    res.setHeader("Content-Type", "text/html");
    res.write("<html>");
    res.write("<head><title>Complete Coding</title></head>");
    res.write("<body><h1>Like / Share / Subscribe</h1></body>");
    res.write("</html>");
    res.end();
  }
};

module.exports = userRequestHandler;
