const NATS = require('nats');
const nats = NATS.connect("nats://0.0.0.0:4222");
 
// Simple Publisher
nats.publish('foo', 'Hello World!');
