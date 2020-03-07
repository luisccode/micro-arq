const express = require("express");
const app = express();
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use((req, res, next) => {
  res.header("Access-Control-Allow-Origin", "*");
  res.header(
    "Access-Control-Allow-Headers",
    "Origin, X-Requested-With, Content-Type, Accept, x-access-token"
  );
  next();
});

app.listen();

app.get('/', function(req, res){
  res.sendFile('index.html', { root: '.' })
});

app.get("/transform-file", (req, res) => {
  const fs = require("fs");
  try {
    // const data = fs.readFileSync("file.txt", "utf8");
    const data = fs.readFileSync("BRAIN/main/places.txt", "utf8");
    return res.send(data.toString());
  } catch (e) {
    return res.send(e.stack);
  }
});

app.listen(9090, function() {
  console.log("Example app listening on port 9090!");
});
app.use('/public',express.static('public'));


