<?php
$insert = false;
if(isset($_POST['name'])){

    // Set connection variables
    $server = "localhost";
    $username = "coder";
    $password = "hasan786";
    $db = "form";

    // Create a database connection
    $con = new mysqli($server, $username, $password, $db);

    // Check for connection success
    if ($con->connect_error) {
        die("Connection failed: " . $con->connect_error);
    }

    $name = $_POST["name"];
    $email = $_POST["email"];
    $message = $_POST["message"];

    // database name (form) and then table name (data)
    $sql = "INSERT INTO data (name, email, message) VALUES ('$name', '$email', '$message');";

    // Execute the query
    if($con->query($sql) == true){
        // Flag for successful insertion
        $insert = true;
    }
    else {
        echo "Error: " . $sql . "<br>" . $con->error;
    }

    // Close the database connection
    $con->close();
}
?>

<!DOCTYPE html>
<html lang="en" dir="ltr">

<head>
    <meta charset="utf-8">
    <link rel="preconnect" href="https://fonts.googleapis.com">     
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Style+Script&display=swap" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css2?family=Comfortaa&display=swap" rel="stylesheet">

    <link rel="stylesheet" href="./style.css">
    <title>H&H</title>

</head>

<body>

    <div class="blue">
        <h1>Harshini & Hasan</h1>
        <h3>BT19CSE035 & BT19CSE036</h3>
        <p>Students of Visvesvaraya National Institute of Technology</p>
        <p>Pre Final year students pursuing Computer Science and Engineering</p>
        <hr>
        <h4>Skills</h4>
        <p>Coding Languages : C, C++</p>
        <p>Basics of HTML, CSS, PHP, MySQL</p>
    </div>
    <div class="mid">
        <h3 class="midhead">About the assignment</h3>
        <p class="midpara">We are using LAMP Stack (Linux, Apache Server, MySql, PHP) for this assignment. <br>We are using PHP and
            MySql in the Contact Form given below.<br> Website is running on Apache Server on Linux Operating System.
        </p>
    </div>
    <?php
        if($insert == true){
            echo "Thanks for submitting your form. We will connect with you soon";
        }
    ?>
    <div class="blue">
        <h3>Contact Form</h3>
        <form action="index.php" method="post">

            <input type="text" name="name" id="name" placeholder="Enter your Name"><br><br>
            <input type="email" name="email" id="email" placeholder="Enter your Email"><br><br>
            <textarea name="message" id="message" placeholder="Enter your Message" rows="10" cols="30"></textarea><br><br>
            
            <input class="btn" type="submit" value="Send a message to us"><br><br>
        </form>
    </div>
</body>

</html>