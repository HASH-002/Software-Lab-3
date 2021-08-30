public class exception{

    public native void NativeExceptionThrow();

    public void divideMethod(){
        int a=5, b=0;
        System.out.println(a/b);
    }
    public void nullMethod(){
        String s=null;
        System.out.println(s.length());
    }

    static {
        System.loadLibrary("helloWorld");
    }

    public static void main(String[] args) {
        exception obj =  new exception();
        try{
            obj.NativeExceptionThrow();
        }catch(ArithmeticException e){
            System.out.println("Divide by zero operation cannot possible");
        }catch(NullPointerException e){
            System.out.println("NullPointException caught");
        }
    }
}