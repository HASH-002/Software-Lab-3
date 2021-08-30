package com.company;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
public class Main {

    static final String DB_URL = "jdbc:mysql://localhost:3306/students";
    static final String USER = "root";
    static final String PASSWORD = "hasan786";
    static final String QUERY = "SELECT * FROM stud";

    public static void main(String[] args) {
        try{
            Connection con =DriverManager.getConnection(DB_URL, USER, PASSWORD);
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(QUERY);

            //Display values
            while(rs.next()){
                System.out.print("Name: " + rs.getString("name"));
                System.out.print(", Roll_no: " + rs.getString("rollno"));
                System.out.print(", Email: " + rs.getString("email"));
                System.out.println(", Branch: " + rs.getString("branch"));
            }

        } catch(Exception e){ System.out.println(e);
        }
}
}
