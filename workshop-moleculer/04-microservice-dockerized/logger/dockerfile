FROM node:lts

WORKDIR /usr/src/app

COPY . .
RUN npm install

CMD [ "node", "./logger-service.js" ]
