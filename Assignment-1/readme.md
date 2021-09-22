[//]: <> (Question 1)
# Portfolio Website
Website made using LAMP Stack

## Installation
Step 1: Open Linux terminal and Install 
apache, mysql servers and php using following commands:

```bash
sudo apt install apache2
sudo apt install mysql-server
sudo apt install php libapache2-mod-php
```
Step 2: Set up mysql root user with password using:
```bash
sudo mysql_secure_installation utility 
```
Step 3: Set the bridge adapter. 

Step 4: Give permission to delete the apache 2 ubuntu default 
page using:
```bash
sudo chown -R 'whoami' /var/www/html
rm index.html 
```
Step 5: Inside the folder /var/www/html make a project folder. 
Inside the folder make 2 files index.php and style.css

Step 6: Using the following commands download Mysql drivers 
(which are necessary for connection).
```bash
sudo apt-add-repository ppa:ondrej/php
sudo apt-get install php7.0
apt-get install php7.4-mysql
service apache2 restart
```
Step 7: Start the apache and mysql server
```bash
sudo service apache2 start 
sudo service mysql start
```

## Setting files and Database
### Database Setup
Create mysql user and grant privileges to the user
```bash
CREATE USER 'user'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON * . * TO 'user'@'localhost';
FLUSH PRIVILEGES; 
```
Login to the mysql user made:
```bash
mysql -u user -p 
```
Create database and table:
```bash
CREATE DATABASE form;
USE form;
CREATE TABLE form 
    (id INT NOT NULL AUTO_INCREMENT, 
    name VARCHAR(50) NOT NULL, 
    email VARCHAR(50) NOT NULL, 
    message VARCHAR(100) NOT NULL,
    PRIMARY KEY (id)
    );
```
### PHP File Description
PHP and HTML code written in index.php made in assign folder in /var/www/html. 
The website contains a static plain html part where details of the authors and the assignment is given
Website also contains a html form where PHP is used to connect to the database and send the submitted form details to insert into the mysql database.

Create connection to database using: \
$con = new mysqli($server, $username, $password, $database);

Get the values from teh submitted form using: \
$name = $_POST["name"]; \
$email = $_POST["email"]; \
$message = $_POST["message"];

SQL Query to insert the values into the database: \
$sql = "INSERT INTO data (name, email, message) VALUES ('$name', '$email', '$message');";

Execute the query: \
$con->query($sql)

After form is submitted, Thank you message is shown on the website. \
For this a variable is maintained ($insert)
Initially : $insert=false;

After sql query is executed successfully:
$insert=true;\
In the html if($insert == true) show thank you message.

Styling of the website is done using css in style.css

**Check if the submitted values inserted successfully using the command on sql command line:
SELECT * FROM form;**
  
## Deployment
To run this website go to web browser and open the following link
```bash
  localhost/assign/index.php
```
## Tech Stack
**Front-end:** HTML5, CSS3 \
**Back-end:** Php \
**Database:** Mysql
  
## Authors
- BT19CSE035 (Harshini Pillarisetti)
- BT19CSE036 (Hasan Koser)

[//]: <> (Question 2)
# Load balancing
Configure load balancing in apache web server using proxy mode.

## Installation
* Download and install XAMPP
* In Apache httpd.conf filem edit configurations
* To configure apache in proxy mode, enable some modules in the httpd.conf file

In Browse Apache open conf/extra/httpd-vhosts.conf file \
Add the following code in this file:
```bash
<VirtualHost :>
    <Proxy "balancer://mycluster">
        BalancerMember "http://localhost:8081"
        BalancerMember "http://localhost:8082"
    </Proxy>
    ProxyPass "/web" "balancer://mycluster"
    ProxyPassReverse "/web" "balancer://mycluster"
</VirtualHost>
```
* Restart the Apache server
* Run 2 servers on localhost:8081 and localhost:8082
Both these server will be balanced on the webpage:
```bash
localhost/web
```
All requests coming to **localhost/web** will be distributed across the balancemembers mentioned above.
This helps in efficiently utilising the resources and also ensures that no single server is overworked.

## Authors
- BT19CSE035 (Harshini Pillarisetti)
- BT19CSE036 (Hasan Koser)

[//]: <> (Question 3)
# Replication in Mysql
Configure MySql in master slave mode using student database.

## Installation
Used 2 ubuntu os as we need 2 servers running from different ip addresses.
One of the server will be the master and other server will be the slave.

### CONFIGURE MASTER 
Step 1: First we need to open the mysql configuration file using:
```bash
sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf
```
In the configuration file replace
* bind address with 0.0.0.0
* Uncomment server-id and give unique id.
* Uncomment log_bin directive to enable binary logging 
* Uuncomment binlog_do_db directive and mention the database name which you want to replicate.

Step 2: Run mysql server now using:
```bash
sudo service mysql start
```
Step 3: Open mysql terminal for root user using:
```bash
sudo mysql -u root -p
```
Step 4: Create database and a table and Insert rows into the table using :

```bash
CREATE DATABASE students;
USE students;
CREATE TABLE stud (name VARCHAR(20), rollno VARCHAR(10), email VARCHAR(25), branch VARCHAR(25));
INSERT INTO stud VALUES ('Ravi', 'BT19ECE78', 'ravishankar@gmail.com', 'Electronics Engineering');
INSERT INTO stud VALUES ('Usha', 'BT19CME24', 'ptusha@gmail.com', 'Chemical Engineering');
```

Step 5: Create another mysql slave user using:
```bash
CREATE USER 'slave_user'@'%' IDENTIFIED WITH mysql_native_password BY 'password'
```
Grant replication slave for that user by using the below command:
```bash
GRANT REPLICATION SLAVE ON . to `slave_user`@`%` IDENTIFIED BY `password`;
FLUSH PRIVILEGES;
FLUSH TABLES WITH READ LOCK;
```
Check the status of master server's binary log file by using the command:
```bash
SHOW master status;
```
Save Filename and position which is going to be used later on.
Shifted to the second Ubuntu OS which is used to run the slave server.

### CONFIGURE SLAVE

Open the mysql configuration file using the below command
```bash
sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf
```

* Uncomment server-id and give unique id(2)
* Uncomment log_bin directive to enable binary logging and uncomment binlog_do_db directive and mention the database name which you want to replicate.
* Add relay_log path

Run Mysql server now
```bash
sudo service mysql start
```
Open mysql terminal for root user using:
```bash
sudo mysql -u root -p
```
Create same database  which created in the master server and insert the same data
```bash
CREATE DATABASE students;
USE students;
CREATE TABLE stud (name VARCHAR(20), rollno VARCHAR(10), email VARCHAR(25), branch VARCHAR(25));
INSERT INTO stud VALUES ('Ravi', 'BT19ECE78', 'ravishankar@gmail.com', 'Electronics Engineering');
INSERT INTO stud VALUES ('Usha', 'BT19CME24', 'ptusha@gmail.com', 'Chemical Engineering');
```
To start replication used the following command in the slave mysql shell:
```bash
CHANGE REPLICATION SOURCE TO
SOURCE_HOST='master_server_ip',
SOURCE_USER='slave_user',
SOURCE_PASSWORD='password',
SOURCE_LOG_FILE= saved_filename,
SOURCE_LOG_POS= previously_saved_postion;
```     
Start replication by using :
```bash
START REPLICA;
```
*TESTING REPLICATION PROCESS*

* In the master mysql server shell, insert data into the table using : 
```bash 
INSERT INTO stud VALUES ('Neeraj', 'BT19CIV01', 'neerajchopara@greatest.co', 'Civil Engineering');
```
* Display the table in the slave mysql server shell using:
```bash 
SELECT * FROM stud;
```
Data added in the master table in the master database will be also added in the slave table in the slave database.
Replication in master slave databases of mysql is done successfully.

## Authors
- BT19CSE035 (Harshini Pillarisetti)
- BT19CSE036 (Hasan Koser)

[//]: <> (Question 4)
# JDBC to fetch data from Mysql DB
Java program to get students details from MySQL database.
## Installation
* Download and install Mysql, java
* Download mysql-connector-java-8.0.26
* Add the jar file in your project structure module

## Setting files and Database
### Database Setup
After downloading Mysql in Windows, run thr following
commands to create the database of students
```bash
CREATE DATABASE students;
use students
create table stud (name VARCHAR(20), rollno VARCHAR(10), email VARCHAR(25), branch VARCHAR(25));

INSERT INTO stud
VALUES ('Ravi', 'BT19ECE78', 'ravishankar@gmail.com', 'Electronics Engineering');
INSERT INTO stud
VALUES ('Usha', 'BT19CME24', 'ptusha@gmail.com', 'Chemical Engineering');
INSERT INTO stud
VALUES ('Neeraj', 'BT19CIV01', 'neerajchopara@greatest.co', 'Civil Engineering');
quit
```
### Java File Description
In the given Java Code

For importing useful packages
```bash
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
```
Create connection to database using:- \
Connection con =DriverManager.getConnection(DB_URL, USER, PASSWORD);

To run the Query in the database:- \
Statement stmt = con.createStatement();\
ResultSet rs = stmt.executeQuery(QUERY);

Variable rs points to a row in the table and hence used in printing 
data from each column of the table
```bash
System.out.print("Name: " + rs.getString("name"));
System.out.print(", Roll_no: " + rs.getString("rollno"));
System.out.print(", Email: " + rs.getString("email"));
System.out.println(", Branch: " + rs.getString("branch"));
```
**Run the program and you will get the required result**
  
## Authors
- [@Hasan Koser](https://www.github.com/HASH-002)
- [@Harshini Pillarisetti](https://github.com/Harshi194)