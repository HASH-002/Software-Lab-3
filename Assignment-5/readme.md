# Assignment 5 - Try to understand the working of SSL 

## Documentation

* #### Question 1. Create a Self-Signed SSL Certificate for Apache in Ubuntu

    Creating the SSL Certificate
    Now that Apache is ready to use encryption, we can move on to generating a new SSL certificate. The certificate will store some basic information about your site, and will be accompanied by a key file that allows the server to securely handle encrypted data.\
    We can create the SSL key and certificate files with the openssl command:
    ```bash
    sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/apache-selfsigned.key -out /etc/ssl/certs/apache-selfsigned.crt
    ```
    After you enter the command, you will be taken to a prompt where you can enter information about your website. Fill out the prompts appropriately.\
    openssl: This is the command line tool for creating and managing OpenSSL certificates, keys, and other files.\
    req -x509: This specifies that we want to use X.509 certificate signing request (CSR) management. X.509 is a public key infrastructure standard that SSL and TLS adhere to for key and certificate management.\
    -nodes: This tells OpenSSL to skip the option to secure our certificate with a passphrase. We need Apache to be able to read the file, without user intervention, when the server starts up. A passphrase would prevent this from happening, since we would have to enter it after every restart.\
    -days 365: This option sets the length of time that the certificate will be considered valid. We set it for one year here. Many modern browsers will reject any certificates that are valid for longer than one year.\
    -newkey rsa:2048: This specifies that we want to generate a new certificate and a new key at the same time. We did not create the key that is required to sign the certificate in a previous step, so we need to create it along with the certificate. The rsa:2048 portion tells it to make an RSA key that is 2048 bits long.\
    -keyout: This line tells OpenSSL where to place the generated private key file that we are creating.\
    -out: This tells OpenSSL where to place the certificate that we are creating.

    Open a new file in the /etc/apache2/sites-available directory:

    ```bash
    sudo nano /etc/apache2/sites-available/your_domain_or_ip.conf
    ```
    Paste in the following minimal VirtualHost configuration:
    ```bash
    /etc/apache2/sites-available/your_domain_or_ip.conf
    ```
    ```bash
    <VirtualHost *:443>
    ServerName your_domain_or_ip
    DocumentRoot /var/www/your_domain_or_ip

    SSLEngine on
    SSLCertificateFile /etc/ssl/certs/apache-selfsigned.crt
    SSLCertificateKeyFile /etc/ssl/private/apache-selfsigned.key
    </VirtualHost>
    ```

    We can enable `mod_ssl`, the Apache SSL module, and `mod_headers`, needed by some of the settings in our SSL snippet, with the `a2enmod` command:
    ```bash
    sudo a2enmod ssl
    sudo a2enmod headers
    ```
    Next, we can enable our SSL Virtual Host with the a2ensite command:
    ```bash
    sudo a2ensite default-ssl
    ```
    We will also need to enable our ssl-params.conf file, to read in the values we set:
    ```bash
    sudo a2enconf ssl-params
    ```
    At this point, our site and the necessary modules are enabled. We should check to make sure that there are no syntax errors in our files. We can do this by typing:
    ```bash
    sudo apache2ctl configtest
    ```
    If your output has Syntax OK in it, your configuration file has no syntax errors. We can safely restart Apache to implement our changes:
    ```bash
    sudo systemctl restart apache2
    ```

    **1. Decoding of the certificate with the help of any online tool.**\
    Now go to the following directory
    ```bash
    cd /etc/ssl/certs
    ```
    Run the following command
    ```bash
    cat apache-selfsigned.crt
    ```
    Then copy the certificate in SSL shopper website and decode it. The cerficate will be displayed completing our first Task.

    **2. Show the certificate from the web browser.**\
    Go to your server and click on icon near http.\
    It will show not safe click on it.\
    Go to advance option and view Certificate and your certificate will get displayed.

    **3. Create a Self-Signed certificate with java keytool and export it and then decode it.**\
    For generating certificate using Java keytool use the following command.
    ```bash
    sudo keytool -genkey -keyalg RSA -alias tomcat -keystore selfsigned.jks -validity 2 -keysize 2048
    ```
    It will ask for password. Create new password there this will help you when you will ask for the certificate. Finally run the following commands to get your certificate.
    ```bash
    sudo keytool -export -alias tomcat -keystore selfsigned.jks -rfc -file certificate.cer
    cat certificate.cer
    ```
    To decode follow the steps as in our first Task.

* #### Question 2. Web Service using SOAP
    1. Create a new project -> web -> Dynamic Web Project
    2. Click next. Add project name, target runtime as Tomcat and click finish.
    3. Now, we create a package named bean with a class Person and add following script.
        ```bash
        import java.io.Serializable;

        public class Person implements Serializable{

            private static final long serialVersionUID = -5577579081118070434L;
        
            private String name;
            private int age;
            private int id;

            public String getName() {
                return name;
            }

            public void setName(String name) {
                this.name = name;
            }

            public int getAge() {
                return age;
            }

            public void setAge(int age) {
                this.age = age;
            }

            public int getId() {
                return id;
            }

            public void setId(int id) {
                this.id = id;
            }
        
            @Override
            public String toString(){
                return id+"::"+name+"::"+age;
            }

        }
        ```

    4. Next, we will be creating service classes with interface as PersonServiceImp and a class Person as follows:
        ```bash
        Interface PersonServiceImp:

        import beans.Person;

        public interface PersonService {

            public boolean addPerson(Person p);
            
            public boolean deletePerson(int id);
            
            public Person getPerson(int id);
            
            public Person[] getAllPersons();
        }

        Class Person:

        import java.util.HashMap;
        import java.util.Map;
        import java.util.Set;

        import beans.Person;

        public class PersonServiceImpl implements PersonService {

            private static Map<Integer,Person> persons = new HashMap<Integer,Person>();
            
            @Override
            public boolean addPerson(Person p) {
                if(persons.get(p.getId()) != null) return false;
                persons.put(p.getId(), p);
                return true;
            }

            @Override
            public boolean deletePerson(int id) {
                if(persons.get(id) == null) return false;
                persons.remove(id);
                return true;
            }

            @Override
            public Person getPerson(int id) {
                return persons.get(id);
            }

            @Override
            public Person[] getAllPersons() {
                Set<Integer> ids = persons.keySet();
                Person[] p = new Person[ids.size()];
                int i=0;
                for(Integer id : ids){
                    p[i] = persons.get(id);
                    i++;
                }
                return p;
            }

        }
        ```
    5. Now, we will be creating a web service using SOAP
    Click new -> web services -> web service.
    For the web serevice type, we select Bottom up Java Bean Web Service, Service implementation is selected by default. If not, we put our sevice class full path. Click finish.

    6. Then we will check the client side we will get an error because normal ide of eclipse (version 2015 and above) and java jdk(8+ version) do not support these services.

    7. So will install the SoupUi and run our auto generated `PersonServiceImpl.wsdl` file. This will create `Test-my-soap-service-soapui-project.xml` and we can check the client services.
    
* #### Question 4.  Showing current load and details using Loadrunner

    LoadRunner is a software testing tool from the Micro Focus family of products.
    LoadRunner is used to test apps and websites to understand how they behave when subjected to various levels of load – before going into production. This is an important step in the process of creating new apps, as poor performance once live, can cause significant financial losses.

    LoadRunner from Micro Focus requires you to install several components before you can perform load testing. The VuGen component is essential for designing testing scripts, while you must use the controller component to define how the test will run and consult the analysis component to review all the reporting and analysis results following load testing.

    VuGen

    VuGen, also known as Virtual User Generator, is an Integrated Development Environment (IDE) used to define and simulate desired user behaviors for testing, and then generate the test scripts themselves.VuGen includes functionality to record communications between a client and server to generate test scripts in code called Vuser scripts.

    ### Controller

    The controller is the central component of the LoadRunner testing tool. It manages the test flow while also registering an app’s performance against established key performance indicators (KPIs) for use by the analysis component.

    ### Load Generators

    Load generators are the components of LoadRunner that simulate the hundreds or thousands of VUs as defined in VuGen for testing. Depending on the exact test and number of VUs required, you might need to use several load generators. LoadRunner’s controller lets you easily scale and manage load generators according to your needs.

    ### The analysis component

    Once your load scenarios have been executed, the analysis component comes into play.

    During load testing, the controller creates a repository of results as they come through. This includes a host of raw data, such as the version of LoadRunner used and the configuration parameters that were set.

    Crucially, it also records all errors that occurred during the test and puts all the error data into a database named output.mdb. The analysis component then analyzes the content of this file, displaying results in a visual, graphical format for easier identification and interpretation of trends. This helps you understand where errors and failures originated during load testing, so you can determine whether optimization of your app is necessary.

    ### STEPS TO FOLLOW TO TEST YOUR APP USING LOAD RUNNER
    1. Design test scripts using VuGen - To design a script, VuGen captures HTTP traffic from actions performed within an app and reproduces those actions to simulate the behavior of a real user on an app.
    2. Define the execution of tests - The whole purpose of load testing is to simulate different levels of activity within an app to detect where failures occur – and crucially pinpoint the load level that generated the first failure. This requires a system that can perform scenarios with several concurrent users executing tasks simultaneously
    Load levels can be increased and decreased to mimic real operating conditions so as to cause stress on the server and uncover abnormal behavior within an app.
    The results are then analyzed to identify causes of failures.
    3. Analyze results - During load testing, LoadRunner runs each scenario and records the app’s performance with varying levels of load. The analysis component then generates statistics and performs an analysis of collected data.

    ### SOME GRAPH ANALYSIS
    1. Average Response Time graph :
    This graph displays the number of hits made on the Web server by VUsers during each second of the load test. This graph helps you evaluate the amount of load VUsers generate, in terms of the number of hits.
    2.  Hits Per Second graph :
    This graph displays the number of hits made on the Web server by VUsers during each second of the load test. This graph helps you evaluate the amount of load VUsers generate, in terms of the number of hits.
    3. Running VUsers graph :
    This graph displays the number of VUsers that executed VUser scripts, and their status, during each second of a load test. This graph is useful for determining the VUser load on your server at any given moment.
    4. Throughput graph : 
    This graph displays the amount of throughput (in bytes) on the Web server during the load test. Throughput represents the amount of data that the VUsers received from the server at any given second. This graph helps you to evaluate the amount of load VUsers generate, in terms of server throughput.
    5. Transactions Per Second graph :
    This graph displays the number of completed transactions (both successful and unsuccessful) performed during each second of a load test. This graph helps you determine the actual transaction load on your system at any given moment.
    6. Transaction Summary graph :
    This graph displays the number of transactions that passed, failed, stopped, or ended with errors.

## Authors
- [@Hasan Koser](https://www.github.com/HASH-002)
- [@Harshini Pillarisetti](https://github.com/Harshi194)
- [@AdityaKhanke](https://github.com/adityakhanke)