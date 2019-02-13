const { ServiceBroker } = require("moleculer");

const broker = new ServiceBroker({
    transporter: "nats://0.0.0.0:4222",
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
