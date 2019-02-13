const { ServiceBroker } = require("moleculer");

const broker = new ServiceBroker({
    transporter: "nats://0.0.0.0:4222",
});

broker.createService({
    name: "greet",
    actions: {
        hello(ctx) {
            broker.emit("hit", {
                service: "greet",
                action: "hello",
                name: ctx.params.name,
            });
            return "Hello " + ctx.params.name;
        }
    }
});

broker.start();
