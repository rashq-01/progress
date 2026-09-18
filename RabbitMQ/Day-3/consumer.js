const amqp = require('amqplib');

async function startConsumer(){
    try{
        const connection = await amqp.connect('amqp://localhost');
        const channel = await connection.createChannel();

        const queue = 'emailQueue';

        await channel.assertQueue(queue , {durable : true});

        console.log("[*] Waiting for messages in queue : ",queue);

        await channel.consume(queue , (msg)=>{
            if(msg){
                const data = JSON.parse(msg.content.toString());
                console.log("[*] Received : ",data);
                channel.ack(msg);
            }
        });
    }
    catch(err){
        console.log(err);
    }
}

startConsumer();