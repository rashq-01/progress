const amqp = require("amqplib");

async function recMail(){
    try{
        const connection = await amqp.connect("amqp://localhost");
        
        const channel = await connection.createChannel();

        await channel.assertQueue("subscribed_users_mail_queue",{durable : true});

        channel.consume("subscribed_users_mail_queue", (message)=>{
            if(message != null){
                console.log("Rec message for subscribed Users : ", JSON.parse(message.content));

                channel.ack(message);
            }
        })
    }
    catch(err){
        console.err(err);
    }
}


recMail();