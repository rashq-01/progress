const amqp = require("amqplib");

async function setup(){
    try{
        const connection = await amqp.connect("amqp://localhost");
        const channel = await connection.createChannel();

        // Create a direct Exchange
        await channel.assertExchange('nexuschat','direct',{durable : true});

        // Create a Queue
        await channel.assertQueue('emailQueue' , {durable : true});

        // Bind queue with routing key
        await channel.bindQueue('emailQueue' , 'nexuschat' , 'user.email');

        console.log("Exchange, Queue and Binding created!");

        await connection.close();
    }
    catch(err){
        console.log(err);
    }
}

setup();