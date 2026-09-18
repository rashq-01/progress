const amqp = require("amqplib");

async function sendEmailMessage(){
    try{
        const connection = await amqp.connect("amqp://localhost");
        const channel = await connection.createChannel();

        const exchange = 'nexuschat';
        const routingKey = "user.email";

        const message = {
            to : 'test@email.com',
            subject : 'Welcome to Nexuschat',
            text : 'This is an email from RabbitMQ!'
        }

        channel.publish(exchange , routingKey , Buffer.from(JSON.stringify(message)) , {persistent : true});

        console.log("[*] Sent message to Exchange : ",exchange);
        await new Promise(resolve => setTimeout(resolve, 500));

        await connection.close();
    }
    catch(err){
        console.log(err);
    }
}

sendEmailMessage();