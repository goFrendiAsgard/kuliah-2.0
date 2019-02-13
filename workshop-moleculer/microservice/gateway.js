const { ServiceBroker } = require("moleculer");
const ApiService = require("moleculer-web");

const broker = new ServiceBroker({
    transporter: "nats://0.0.0.0:4222",
});

broker.createService({
    mixins: [ApiService],
    settings: {
        port: 3000,
    },
    name: "api",
    actions: {
        async hello(ctx) {
            return await broker.call("greet.hello", {name: ctx.params.name});
        }
    }
});

broker.start();
