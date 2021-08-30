import java.util.Scanner;
public class student{

    private String name;
    private String university;
    private String branch;

    public student(String name, String university, String branch){
        this.name = name;
        this.university = university;
        this.branch = branch;
    }

    public void objectMethod(){
        System.out.println("Name: "+ name);
        System.out.println("University: "+ university);
        System.out.println("Branch: "+ branch);
    }


    public native void nativeMethod(String name, String university, String branch);

    static {
        System.loadLibrary("helloWorld");
    }

    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        String name_input,university_input,branch_input;
        
        System.out.print("Enter your name: ");  
        name_input = sc.nextLine();
        System.out.print("Enter your University: ");  
        university_input = sc.nextLine();
        System.out.print("Enter your Branch: ");  
        branch_input = sc.nextLine();

        student s =  new student(name_input,university_input,branch_input);
        System.out.println("Values before calling Native Method");
        s.objectMethod();

        System.out.print("Enter updated name: ");  
        name_input = sc.nextLine();
        System.out.print("Enter updated University: ");  
        university_input = sc.nextLine();
        System.out.print("Enter updated Branch: ");  
        branch_input = sc.nextLine();

        s.nativeMethod(name_input,university_input,branch_input);
        
        System.out.println("Values after calling Native Method");
        s.objectMethod();
        System.out.println();
        sc.close();
    }
}