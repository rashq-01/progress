const amqp = require("amqplib");

async function sendMail() {
    try {
        // Connect to RabbitMQ
        const connection = await amqp.connect("amqp://localhost");

        // Create channel
        const channel = await connection.createChannel();

        const exchange = "mailExchange";
        const queue = "mailQueue";
        const routingKey = "sendMail";

        // Mail data
        const message = {
            to: "rajesh@gmail.com",
            from: "rkp9356@gmail.com",
            subject: "Thank for hello",
            body: "This is null"
        };

        // Create exchange
        await channel.assertExchange(exchange, "direct", {
            durable: true
        });

        // Create queue
        await channel.assertQueue(queue, {
            durable: true
        });

        // Bind queue to exchange
        await channel.bindQueue(
            queue,
            exchange,
            routingKey
        );

        // Publish message
        channel.publish(
            exchange,
            routingKey,
            Buffer.from(JSON.stringify(message)),
            {
                persistent: true,
                contentType: "application/json"
            }
        );

        console.log("Mail data sent:");
        console.log(message);

        // Close connection
        await channel.close();
        await connection.close();

    } catch (error) {
        console.error("Producer Error:", error);
    }
}

sendMail(); 