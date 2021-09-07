# Assignment 4 - Open Source Cloud Platform 

## Documentation

* #### Question 1. Integration of Gmail with Google calendar 

    Send email to different gmail IDs.
    
    From Gmail sent, create new event which will redirect to Google Calendar.

    Select the date and time for the event.

    Add the location, GMeet link, colour visible on the calendar and other options for the event.

    The recepients of the mail will automatically be added as guests.
    
    Save the event, which will send invite mails to all the guests.

    The mail sent to the guests will contain all the details of the event.
    The event will also be added onto the calendars of all the guests.

    Hence integration of Gmail with Google Calendar was successful.

* #### Question 2. Creating Google Form and analysis of the survey

    Google Form made to take survey on Mobile Usage by different age groups.
    https://forms.gle/2FhzE1eJNMrt4Qan6

    The answers to the questions are taken using different types of input methods namely:
    * Short Answer
    * Multiple Choice
    * Dropdown
    * Checkboxes

    Responses are analysed in the form of pie charts and bar graphs.

    A spreadsheet is also created which automatically gets updated with every response.\
    Each row features the responses from each respondent, and each column features a question from the form.

    In the tools of the spreadsheet, add a function myFunction() using script editor.

    ```bash
    Get the active spreadsheet :
    var spreadsheet = SpreadsheetApp.getActiveSpreadsheet();
    var sheet = spreadsheet.getSheets()[0];

    The range of the excel sheet where you want to sort:
    var range = sheet.getRange("A2:E100");

    Sort according to 2nd column in the excel sheet:
    range.sort(2);
    ```
* #### Question 3.  Accessing Google-map via Google-map API 
    Different File Description are as follows:-

    * index.html\
        A simple html structure is declared at the start with required styling and linking Libraries.

        Inside body tag in script API key was added with api and call has been made to initMap() function.
        ```bash
        <script async defer
        src="https://maps.googleapis.com/maps/api/js?key=AIzaSyApx6pFCY0XlU4mSWReK9AOs8BdMhLoLco&callback=initMap">
        </script>
        ```
        Inside function initMap() we first set the centered location to vnit. When our script will open it will get centered in this location. As declared in html the id of our container is map, so we will use that id to alter element in html.
        ```bash
            function initMap() {
            var location = {
                zoom: 8,
                center: { lat: 21.1232, lng: 79.0515 },

            }
            var map = new google.maps.Map(document.getElementById("map"), location);
        ```
        Now as asked in question we will create a marker and point it to VNIT with the help of our addMarker function. We will also send image and caption for the marker.

        ```bash
        addmarkers({
            coords: { lat: 21.1232, lng: 79.0515 },
            iconImage: "https://developers.google.com/maps/documentation/javascript/examples/full/images/beachflag.png",
            content: '<h2>VNIT</h2>'
        });
        ```
        Get all the previously saved marker locations from the database using an axios get request to "/getMarkers" route and call addmarkers function for every marker:
        ```bash
        axios.get("/getMarkers").then((res) => {
            let locations = res.data;
            locations.forEach(element => {
                const pos = { lat: element.lat, lng: element.lng };
                addmarkers({ coords: pos });
            });
        }).catch((err) => {
            console.log(err);
        });
        ```
        Our last task is to add markers dynamically when user clicks it and finally saving it to database.

        With the help of `addlistner` function in javascript we will record the location(in terms of latitude and longitude) when user clicks. We will save that location in our database too by doing a post request to "/addMarker" route.
        ```bash
        google.maps.event.addListener(map, 'click',
            function (event) {
                addmarkers({ coords: event.latLng });
                const loc = { lat: event.latLng.lat(), lng: event.latLng.lng() };

                //Post request to add the newly clicked marker into the database
                axios.post("/addMarker", loc).error((err) => {
                    console.log(err);
                });
            });
        ```
        Finally the `addmarkers` function helps us in adding all markers in our map. We will take the take coordinates and set our marker variable by creating a Google maps marker. At the end with the help of listener we will add marker in our map.
        ```bash
        function addmarkers(props) {
            var marker = new google.maps.Marker({
                position: props.coords,
                map: map,
            });

            if (props.iconImage) {
                marker.setIcon(props.iconImage);
            }

            if (props.content) {
                var caption = new google.maps.InfoWindow({
                    content: props.content
                });

                marker.addListener('click', function () {
                    caption.open(map, marker);
                });
            }
        }
        ```

    * MongoDB Connection in app.js

        Install packages express, body-parser, mongoose using:
        ```bash
            npm install express body-parser mongoose
        ```

        Require the packages in app.js:
        ```bash
            const express = require("express");
            const bodyParser = require("body-parser");
            const mongoose = require('mongoose');
        ```

        Create and connect to a mongoose database namely markersDB:
        ```bash
            mongoose.connect("mongodb://localhost:27017/markersDB", {useNewUrlParser: true});
        ```
        Create a markerSchema with lat and lng with Number data types and create the mongoose model
        ```bash
            const markerSchema = new mongoose.Schema({
                lat : Number,
                lng : Number
            });

            const Marker = mongoose.model("Marker", markerSchema);
        ```

        Get request to "/" route renders the html file:
        ```bash
            res.sendFile(__dirname+"/index.html");
        ```

        Get request to the API "/getMarkers" sends all the markers from the database and sends it as response:
        ```bash
            app.get("/getMarkers",function(req,res){
                Marker.find(function(err,data){
                res.send(data);
            });
            });
        ```

        Post request to the API "/addMarker" adds the new marker received in request.body into the database:
        ```bash
            app.post("/addMarker",function(req,res){
                const newMarker=new Marker(req.body);
                newMarker.save();
            });
        ```

        Run the website of port 3000 and check if the website is running successfully by consoling a message:
        ```bash
            app.listen(3000,function(){
                console.log("Connected to port 3000");
            });
        ```

        Run the server on the terminal using:
        ```bash
            node app.js
        ```
    
* #### Question 4. Website on Salesforce cloud

    Steps to follow:
    1. Register for salesforce developer
    2. In the home page, create a custom object
        Label: Product
        Plural Label: Products
        Object Name: Product
        Record Name: Product Name
        Data Type: Text
        
        Check the option to Launch New Custom Tab Wizard before saving this custom object.

        Save, select tab style and then save.
        
        Under fields and relations, select new.
        Select text, click on next
        Create a new Custom fields: Description, Price, Total Inventory:

        Data type: Number
        Label: Price
        Length: 18
        Field Name: Price

        Data type: Number
        Label: Total Inventory
        Length:  18
        Field Name: Total_Inventory

        Data type: Text
        Label: Description
        Length:  255
        Field Name: Description

    3. Create the Line Item object
        Label: Line Item
        Plural Label : Line Items
        Object Name: Line_Item
        Record Name: Line Item Name
        Data Type: Text
        
        Now, lets create custom fields for Line Item object

        1. Create a new Custom field, Invoice.
        Data type: Master-Detail
        Related To: Invoice
        Label: Invoice
        Field Name: Invoice
        Child Relationship Name: Line_Items

        2. Create a new Custom field, Product.
        Data type: Master-Detail
        Related To: Product
        Label: Product
        Field Name: Product
        Child Relationship Name: Line_Items

        3. Create a new Custom field, Units Sold.
        Data type: Number
        Label: Units Sold
        Length: 18
        Field Name: Units_Sold

        4. Create a new Custom field, Unit Price.
        Data type: Number
        Label: Unit price
        Length: 18
        Field Name: Unit_Price

        5. Create a new Custom field, Total Value.
        Data type: Formula
        Label: Total Value
        Field Name: Total_Value
        Formula Return Type: Number
        Total Value (number) = Units_Sold__c * Unit_Price__c

    4. Create the Invoice object
        Label: Invoice
        Plural Label :Invoices
        Object Name: Invoice (this is the name that will be used via API)
        Record Name: Invoice Name
        Data Type: Auto Number
        Display Format:  INV-{0} (this means that every invoice instance will have the INV prefix)

        1. Create a new Custom field, Description.
        Data type: Text
        Label: Description
        Length: 255
        Field Name: Description

        2. Create a new Custom field, Invoice Status.
        Data type: Picklist
        Label: Invoice Status
        In the text area type:
            New
            Open
            Submitted
        Field Name: Invoice_Status

        3. Create a new Custom field, Total Invoice
        Data type: Roll-up Summary
        Summarized Object: Line Items
        Select Roll-Up Type: SUM
        Field to Aggregate: Total Value


        4. Create a new Custom field, Region.
        Data type: Picklist
        Label: Invoice Status
        In the text area type:
            North
            South
            East
            West
        Field Name: Invoice_Status
    
    5. Add different product items.

    6. Add new invoice items for the different regions North, South, East, West.

    7. Add Line Item items selecting invoice region and product items.

    8. Total Value for the Line Item will automatically generated and will be added to the Total Invoice of the particular region(Invoice).

## Authors
- BT19CSE035 (Harshini Pillarisetti)
- BT19CSE036 (Hasan Koser)
- BT19CSE054 (Khanke Aditya Ajay)