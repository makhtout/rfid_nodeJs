var http = require('http');
var server = http.createServer(function(req, res) {
  res.writeHead(200);
  res.end(' Okeey ');
});
server.listen(8080);
console.log("Server Ok");