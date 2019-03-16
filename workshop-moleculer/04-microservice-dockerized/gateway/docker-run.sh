docker run --name my-moleculer-gateway --net=host -e NATS_PORT="nats://0.0.0.0:4222" -e HTTP_PORT_GATEWAY=3000  -p 3000:3000 -d my-moleculer-gateway
