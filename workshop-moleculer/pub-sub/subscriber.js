const NATS = require('nats');
const nats = NATS.connect("nats://0.0.0.0:4222");
 
// Simple Subscriber
nats.subscribe('foo', function(msg) {
  console.log('Received a message: ' + msg);
});
