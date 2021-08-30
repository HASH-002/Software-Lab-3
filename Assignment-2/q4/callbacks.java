import java.util.Scanner;
public class callbacks{
    private static String city;
    private static int pincode;

    private String name;
    private String university;
    private String branch;

    public static void staticMethod(){
        System.out.println("The city is: "+city);
        System.out.println("Pincode of the area is: "+ pincode);
    }

    public void objectMethod(){
        System.out.println("Name: "+ name);
        System.out.println("University: "+ university);
        System.out.println("Branch: "+ branch);
    }

    public void callmethod(){
        Scanner sc= new Scanner(System.in);
        
        System.out.print("Enter your city: ");  
        city = sc.nextLine();

        System.out.print("Enter your pincode: ");  
        pincode = sc.nextInt();
        sc.nextLine();
        
        System.out.print("Enter your name: ");  
        name = sc.nextLine();
        
        System.out.print("Enter your University: ");  
        university = sc.nextLine();

        System.out.print("Enter your Branch: ");  
        branch = sc.nextLine();

        System.out.println();
        sc.close();
    }

    public native void nativeMethod();

    static {
        System.loadLibrary("helloWorld");
    }

    public static void main(String[] args) {
        callbacks obj =  new callbacks();
        obj.callmethod();
        obj.nativeMethod();
    }
}