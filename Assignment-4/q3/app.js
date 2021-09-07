const express = require("express");
const bodyParser = require("body-parser");
const mongoose = require('mongoose');

const app = express();
app.use(express.json());

app.use(bodyParser.urlencoded({ extended: true }));

mongoose.connect("mongodb://localhost:27017/abcDB", { useNewUrlParser: true });

const markerSchema = new mongoose.Schema({
    lat: Number,
    lng: Number
});

const Marker = mongoose.model("Marker", markerSchema);

//Get request to render the html file
app.get("/", function (req, res) {
    res.sendFile(__dirname + "/index.html");
});

//Post request -> adding newly clicked marker into the database
app.post("/addMarker", function (req, res) {
    const newMarker = new Marker(req.body);
    newMarker.save();
});

//Get request to get all the markers in the database
app.get("/getMarkers", function (req, res) {
    Marker.find(function (err, data) {
        res.send(data);
    });
});

//Website runs ar localhost:3000
app.listen(3000, function () {
    console.log("Connected to port 3000");
});