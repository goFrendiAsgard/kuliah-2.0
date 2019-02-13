# Pub-Sub Example

A simple publish-subscribe example. Using nats as messaging system

First of all, you have to run nats. If you are using docker, you can invoke

```
docker start nats
```

You can then run the subscriber by invoking:

```
npm install --save
node ./subscriber.js
```

After the subscriber runs, you can send a "foo" `event` by invoking:

```
node ./publisher.js
```

The subscriber will receive "Hello World!" `message`.

