// run node index.js to catch the esp8266 http post requests
var express = require('express')
var app = express()
var bodyParser = require('body-parser');

// for parsing application/x-www-form-urlencoded
app.use(bodyParser.raw());
app.get('/', function(req, res) {
  res.send('Hello <3')
})

app.use(function(req, res, next){
   var data = "";
   req.on('data', function(chunk){ data += chunk})
   req.on('end', function(){
     req.rawBody = data;
     next();
   })
})

app.post('/hello', function (req, res) {
  console.log('/POST')
  console.log(req.rawBody, req.body)
  res.send('POST request received from Arduino')
})

app.listen(8000, function () {
  console.log('Listening on port 8000!')
})
