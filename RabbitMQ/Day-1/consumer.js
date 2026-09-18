const amqp = require("amqplib");

async function recMail(){
    try{
        const connection = await amqp.connect("amqp://localhost");
        
        const channel = await connection.createChannel();

        await channel.assertQueue("mailQueue",{durable : true});

        channel.consume("mailQueue", (message)=>{
            if(message != null){
                console.log("Rec message : ", JSON.parse(message.content));

                channel.ack(message);
            }
        })
    }
    catch(err){
        console.err(err);
    }
}


recMail();