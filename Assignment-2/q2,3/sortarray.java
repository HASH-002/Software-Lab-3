import java.util.Scanner;

class sortarray {
    public native int[] displaysortarray(int[] arr);

    static {
        System.loadLibrary("helloWorld");
    }
   
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.printf("Enter size of your array : ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.printf("Enter values : ");
        for(int i=0; i< n; i++)
        {
            arr[i] = sc.nextInt();
        }
        int[] sortedarray=new sortarray().displaysortarray(arr);
        System.out.printf("Sorted array : ");
        for(int i=0;  i<n; i++){
            System.out.printf(sortedarray[i]+" ");
        }
        System.out.println();
        sc.close();
    }
}