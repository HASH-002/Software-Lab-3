import java.util.Scanner;

class palindrome {
    public native boolean checkpalindrome(String s);

    static {
        System.loadLibrary("helloWorld");
    }
   
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);

        System.out.print("Enter a string: ");  
        String str= sc.nextLine();              
        
        boolean flag = new palindrome().checkpalindrome(str);

        if(flag==true)
            System.out.print(str + " is a Palindrome");
        else
            System.out.print(str + " is not a Palindrome");
        
        System.out.println();
        sc.close();
    }
}