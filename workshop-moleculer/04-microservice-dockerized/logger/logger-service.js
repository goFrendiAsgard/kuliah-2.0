const { ServiceBroker } = require("moleculer");

const broker = new ServiceBroker({
    transporter: process.env.NATS_URL || "nats://0.0.0.0:4222",
});

broker.createService({
    name: "log",
    events: {
        "hit": {
            handler(payload) {
                console.log(payload);
            }
        }
    }
});

broker.start();
