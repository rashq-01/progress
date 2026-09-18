const amqp = require("amqplib");

async function sendMail() {
    try {
        // Connect to RabbitMQ
        const connection = await amqp.connect("amqp://localhost");

        // Create channel
        const channel = await connection.createChannel();

        const exchange = "mailExchange";
        const routingKeyForSubUser = "send_mail_to_subscribed_users";
        const routingKeyForNormalUser = "send_mail_to_users";

        // Mail data
        const message = {
            to: "rajesh@gmail.com",
            from: "rkp9356@gmail.com",
            subject: "Message to Normal Users",
            body: "This is only for Normal Users"
        };

        // Create exchange
        await channel.assertExchange(exchange, "direct", {
            durable: true
        });

        // Create queue
        await channel.assertQueue("subscribed_users_mail_queue", {durable: true});
        await channel.assertQueue("users_mail_queue", {durable: true});

        // Bind queue to exchange
        await channel.bindQueue("subscribed_users_mail_queue",exchange,routingKeyForSubUser);
        await channel.bindQueue("users_mail_queue",exchange,routingKeyForNormalUser);

        // Publish message
        channel.publish(
            exchange,
            routingKeyForNormalUser,
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