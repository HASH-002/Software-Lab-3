# Assignment 6 - Hadoop Try working on concept of map-reduce 

## Documentation

* #### Question 1. Installation of Hadoop in the system. 

    1 - Installing Java\
        Hadoop is written in Java and supports only Java version 8. Hadoop version 3.3 and latest also support Java 11 runtime as well as Java 8.\
        You can install OpenJDK 11 from the default apt repositories:
    ```bash
    sudo apt update 
    sudo apt install openjdk-11-jdk
    ```

    2 - Create a Hadoop User\
        Run the following command to create a new user with name hadoop
    ```bash
    sudo adduser hadoop
    ``` 
    Provide and confirm the new password.

    3 – Configure SSH Key-based Authentication\
    First, change the user to hadoop with the following command:
    ```bash
    su - hadoop
    ``` 
    Next, run the following command to generate Public and Private Key Pairs:
    ```bash
    ssh-keygen -t rsa
    ``` 
    You will be asked to enter the filename. Just press Enter to complete the process:

    Next, append the generated public keys from id_rsa.pub to authorized_keys and set proper permission:
    ```bash
    cat ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys 
    chmod 640 ~/.ssh/authorized_keys 
    ```
    Next, verify the passwordless SSH authentication with the following command:
    ```bash
    ssh localhost
    exit
    ```
    Step 4 – Installing Hadoop\
    First, change the user to hadoop with the following command:
    ```bash
    su - hadoop
    ``` 
    Next, download the latest version of Hadoop using the wget command:
    ```bash
    wget https://downloads.apache.org/hadoop/common/hadoop-3.3.0/hadoop-3.3.0.tar.gz 
    ```
    Once downloaded, extract the downloaded file:
    ```bash
    tar -xvzf hadoop-3.3.0.tar.gz
    ``` 
    Next, rename the extracted directory to hadoop:
    ```bash
    mv hadoop-3.3.0 hadoop
    ``` 
    Next, you will need to configure Hadoop and Java Environment Variables on your system.
    Open the ~/.bashrc file in your favorite text editor:
    ```bash
    nano ~/.bashrc
    ``` 
    Append the below lines to file. You can find JAVA_HOME location by running dirname $(dirname $(readlink -f $(which java))) command on terminal.
    
    `export JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64
    export HADOOP_HOME=/home/hadoop/hadoop
    export HADOOP_INSTALL=$HADOOP_HOME
    export HADOOP_MAPRED_HOME=$HADOOP_HOME
    export HADOOP_COMMON_HOME=$HADOOP_HOME
    export HADOOP_HDFS_HOME=$HADOOP_HOME
    export HADOOP_YARN_HOME=$HADOOP_HOME
    export HADOOP_COMMON_LIB_NATIVE_DIR=$HADOOP_HOME/lib/native
    export PATH=$PATH:$HADOOP_HOME/sbin:$HADOOP_HOME/bin
    export HADOOP_OPTS="-Djava.library.path=$HADOOP_HOME/lib/native"`
    
    Save and close the file. Then, activate the environment variables with the following command:
    ```bash
    source ~/.bashrc
    ```
    Next, open the Hadoop environment variable file:

    `nano $HADOOP_HOME/etc/hadoop/hadoop-env.sh`  
    Again set the JAVA_HOME in hadoop environemnt.

    `export JAVA_HOME=/usr/lib/jvm
    java-11-openjdk-amd64` 
    Save and close the file when you are finished.

    Step 5 - Configuring Hadoop\
    First, you will need to create the namenode and datanode directories inside Hadoop home directory:

    Run the following command to create both directories:
    ```bash
    mkdir -p ~/hadoopdata/hdfs/namenode 
    mkdir -p ~/hadoopdata/hdfs/datanode
    ``` 
    Next, edit the core-site.xml file and update with your system hostname:

    ```bash
    nano $HADOOP_HOME/etc/hadoop/core-site.xml 
    ```
    Change the following name as per your system hostname:
    XHTML
    ```bash
    <configuration>
            <property>
                    <name>fs.defaultFS</name>
                    <value>hdfs://coder-VirtualBox:9000</value>
            </property>
    </configuration>
    ```
    Save and close the file. Then, edit the hdfs-site.xml file:
    ```bash
    nano $HADOOP_HOME/etc/hadoop/hdfs-site.xml 
    ```
    Change the NameNode and DataNode directory path as shown below:
    ```bash
    XHTML
    <configuration>

            <property>
                    <name>dfs.replication</name>
                    <value>1</value>
            </property>

            <property>
                    <name>dfs.name.dir</name>
                    <value>file:///home/hadoop/hadoopdata/hdfs/namenode</value>
            </property>

            <property>
                    <name>dfs.data.dir</name>
                    <value>file:///home/hadoop/hadoopdata/hdfs/datanode</value>
            </property>
    </configuration>
    ```
    Save and close the file. Then, edit the mapred-site.xml file:
    ```bash
    nano $HADOOP_HOME/etc/hadoop/mapred-site.xml 
    ```
    Make the following changes:

    XHTML
    ```bash
    <configuration>
            <property>
                    <name>mapreduce.framework.name</name>
                    <value>yarn</value>
            </property>
    </configuration>
    ```
    Save and close the file. Then, edit the yarn-site.xml file:
    ```bash
    nano $HADOOP_HOME/etc/hadoop/yarn-site.xml 
    ```
    Make the following changes:

    XHTML
    ```bash
    <configuration>
            <property>
                    <name>yarn.nodemanager.aux-services</name>
                    <value>mapreduce_shuffle</value>
            </property>
    </configuration>
    ```
    Save and close the file when you are finished.

    Step 6 - Start Hadoop Cluster\
    Before starting the Hadoop cluster. You will need to format the Namenode as a hadoop user.

    Run the following command to format the hadoop Namenode:
    ```bash
    hdfs namenode -format
    ``` 
    
    After formatting the Namenode, run the following command to start the hadoop cluster:
    ```bash
    start-dfs.sh 
    ```
    Once the HDFS started successfully, run this

    ```bash
    start-yarn.sh
    ``` 
    and then
    ```bash
    jps 
    ```
    Step 7 - Adjust Firewall
    Hadoop is now started and listening on port 9870 and 8088. Next, you will need to allow these ports through the firewall.

    Run the following command to allow Hadoop connections through the firewall:
    ```bash
    firewall-cmd --permanent --add-port=9870/tcp 
    firewall-cmd --permanent --add-port=8088/tcp 
    ```
    Next, reload the firewalld service to apply the changes:
    ```bash
    firewall-cmd --reload 
    ```
    Step 8 - Access Hadoop Namenode and Resource Manager\
    To access the Namenode, open your web browser and visit the URL http://your-server-ip:9870. 

    To access the Resource Manage, open your web browser and visit the URL http://your-server-ip:8088. 

* #### Question 2 - Word count of file using Map Reduce

    Create a directory in hadoop filesystem
    ```bash
    hdfs dfs -mkdir -p /user/hadoopusr/input
    ```
    Make test file and copy to hadoop filesystem inside input directory
    ```bash
    cd /usr/local/hadoop
    hdfs dfs -put test /user/hadoopusr/input/
    ```

    Run the wordcount mapreduce. It will read all files from input folder and process with mapreduce jar file and results will be placed on output directory.
    ```bash
    cd $HADOOP_HOME
    hadoop jar share/hadoop/mapreduce/hadoop-mapreduce-examples-3.3.0.jar wordcount input output
    ```

     Check the names of result file created in the output folder and show the content of the result file.
     ```bash
    hdfs dfs -ls /user/hadoopusr/output
    hdfs dfs -cat /user/hadoopusr/output/part-r-00000
    ```

* #### Question 3 - Creating .csv file containing sales details of each country

    New directory 'MapReduceTutorial' in hadoop user and give permissions
    ```bash
    sudo mkdir MapReduceTutorial
    sudo chmod -R 777 MapReduceTutorial
    ```
    Export classpath
    ```bash
    export CLASSPATH="$HADOOP_HOME/share/hadoop/mapreduce/hadoop-mapreduce-client-core-3.3.0.jar:$HADOOP_HOME/share/hadoop/mapreduce/hadoop-mapreduce-client-common-3.3.0.jar:$HADOOP_HOME/share/hadoop/common/hadoop-common-3.3.0.jar:~/MapReduceTutorial/SalesCountry/*:$HADOOP_HOME/lib/*"
    ```

    Create 3 java files and compile them
    ```bash
    javac -d . SalesMapper.java SalesCountryReducer.java SalesCountryDriver.java
    ```

    Create a new file Manifest.txt and add a line to it
    ```bash
    sudo nano Manifest.txt
    Main-Class: SalesCountry.SalesCountryDriver
    ```

    Create a Jar file
    ```bash
    jar cfm ProductSalePerCountry.jar Manifest.txt SalesCountry/*.class
    ```

    Start Hadoop
    ```bash
    $HADOOP_HOME/sbin/start-dfs.sh
    $HADOOP_HOME/sbin/start-yarn.sh
    ```

    Create a folder inputMapReduce and copy the .csv file to it and copy ~/inputMapReduce to HDFS.
    ```bash
    $HADOOP_HOME/bin/hdfs dfs -copyFromLocal ~/inputMapReduce /
    ```

    Verify whether a file is actually copied or not
    ```bash
    $HADOOP_HOME/bin/hdfs dfs -ls /inputMapReduce
    ```

    Run MapReduce job
    ```bash
    $HADOOP_HOME/bin/hadoop jar ProductSalePerCountry.jar /inputMapReduce /mapreduce_output_sales
    ```

    Result can be seen through command interface
    ```bash
    $HADOOP_HOME/bin/hdfs dfs -cat /mapreduce_output_sales/part-00000
    ```
    
    Open localhost:9870 on browser. 
    Select ‘Browse the filesystem’ and navigate to /mapreduce_output_sales.
    Open part-r-00000.

## Authors
- [@Hasan Koser](https://www.github.com/HASH-002)
- [@Harshini Pillarisetti](https://github.com/Harshi194)