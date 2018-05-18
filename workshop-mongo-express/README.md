# MongoDB

MongoDB is a free and open-source cross-platform document-oriented database program. Classified as a NoSQL database program, MongoDB uses JSON-like documents with schemas. MongoDB is developed by MongoDB Inc., and is published under a combination of the GNU Affero General Public License and the Apache 

## Interactive Terminal

You can start interactive terminal by invoking `mongo`

```
gofrendi@asgard:~/Projects$ mongo
MongoDB shell version v3.6.3
connecting to: mongodb://127.0.0.1:27017
MongoDB server version: 3.6.3
>
```

## Show Databases

```
show databases;
```

## Create / Use Database 

```
use example;
```

## Terminology

```
Table       --> Collection
Row/Record  --> Document
Field       --> Attribute
```

## Show Collection

```
show collections
```

## Create Collection and Insert Document

```
// INSERT INTO persons (name, rank) VALUES ('Kakashi', 'Jonin')
db.persons.insert({name: 'Kakashi', rank: 'Jonin'})

// INSERT INTO persons (name, rank) VALUES ('Iruka', 'Genin')
db.persons.insert({name: 'Iruka', rank: 'Genin'})
```

## Show Documents

```
// SELECT * FROM persons
db.persons.find({});

// SELECT * FROM persons WHERE name='Kakashi'
db.persions.find({name: 'Kakashi'})
```

## Update Document

```
// UPDATE persons SET rank='Chunin' WHERE name='Iruka'
db.persons.update({name: 'Iruka'}, {rank: 'Chunin'})
```

## Delete Document

```
// DELETE FROM persons WHERE name = 'Iruka'
db.persons.delete({name: 'Iruka'})
```

## Further Reading

* [TutorialsPoint](https://www.tutorialspoint.com/mongodb/index.htm)

# Node.Js

Node.js is an open-source, cross-platform JavaScript run-time environment that executes JavaScript code server-side. Historically, JavaScript was used primarily for client-side scripting, in which scripts written in JavaScript are embedded in a webpage's HTML and run client-side by a JavaScript engine in the user's web browser.

## Interactive Session

```bash
node
```

## Run File

```bash
node filename.js
```

## Hello world

```JavaScript
// filename: hello-world.js
// run: node hello-world.js

console.log('Hello World')
```

# npm

npm is a package manager for the JavaScript programming language. It is the default package manager for the JavaScript runtime environment Node.js. It consists of a command line client, also called npm, and an online database of public and paid-for private packages, called the npm registry.

## Init package

```bash
mkdir learn
cd learn
npm init
```

__Note:__ On Windows, use `md` instead of `mkdir`

## Install dependencies

```bash
npm install --save express
npm install --save mongodb
```

# Node.Js + MongoDB

```
const MongoClient = require('mongodb').MongoClient;
const assert = require('assert');
 
// Connection URL
const url = 'mongodb://localhost:27017';
 
// Database Name
const dbName = 'myproject';
 
// Use connect method to connect to the server
MongoClient.connect(url, function(err, client) {
  assert.equal(null, err);
  console.log("Connected successfully to server");
 
  const db = client.db(dbName);
  const collection = db.collection('persons');
  collection.find({}).toArray(function(err, docs) {
    assert.equal(err, null);
    console.log("Found the following records");
    console.log(docs)
    callback(docs);
  });
 
  client.close();
});
```

__Further Reading:__ [MongoDB Driver](https://www.npmjs.com/package/mongodb)

## Node.Js + Express

```
const express = require('express');
const app = express();

app.get('/', function (req, res) {
    res.send('Hello World!');
})

app.listen(3000, function () {
    console.log('Example app listening on port 3000!');
})
```

__Further Reading:__ [Express](https://www.npmjs.com/package/express)

## Node.Js + Express + MongoDB

```
Your turn :)
```
