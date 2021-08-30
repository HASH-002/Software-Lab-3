# Assignment 2 - JAVA NATIVE INTERFACE
## Installation
.java and .cpp files are made for every question.\
The following commands were executed for every question to run the code written:-

Step 1: Compile the java file using the command:
```bash
javac filename.java
```
This generates a .class file 

Step 2: Generate the .h file using the command:
```bash
javac -h . filename.java
```

Step 3: Compile the cpp file (abc.cpp) using the command:
```bash
-I/usr/lib/jvm/java-11-openjdk-amd64/include/ -I/usr/lib/jvm/java-11-openjdk-amd64/include/linux/ -fPIC -shared abc.cpp -o libhelloWorld.so
```

Step 4: Set the environment variable for LD_LIBRARY_PATH using the command :
```bash
export LD_LIBRARY_PATH=.
```
This provides a list of additional directories to search for dynamically linkable libraries.

Step 5: Run the java file using the command:
```bash
java filename
```
## Documentation

* #### Question 1. Check whether the string it receives is a palindrome or not
    Class palindrome is defined.\
    In the main function, string is inputted from the user using an object of java.util.Scanner.\
    The inputted string is sent as argument to a native function:
    ```bash
    public native boolean checkpalindrome(String s);
    ```
    In the native function, string received as parameter is accessed using :
    ```bash
    const char *s = env->GetStringUTFChars(str,0);
    ```
    The length of the string is found using:
    ```bash
    int len = env->GetStringUTFLength(str);
    ```
    It is checked if the string is a palindrome and a 'jboolean' value is returned by the native method.\
    true : if the string is a palindrome\
    false : if the string is not a palindrome\
    The returned value is checked in the java main function and suitable output is printed.

* #### Question 2,3. Sort the array and send it result back to mainan prints the sorted array
    Class sortarray is defined.\
    In the main function, an array is inputted from the user using an object of java.util.Scanner.\
    The inputted array is sent as argument to a native function:
    ```bash
    public native int[] displaysortarray(int[] arr);
    ```
    In the native function, the array received as parameter is accessed using:
    ```bash
    jint* arr = (env)->GetIntArrayElements(array, NULL);
    ```
    The length of the array is found using:
    ```bash
    jintArray result = (env)->NewIntArray(n);
    ```
    This array is then sorted using Bubble Sort.\
    A new 'jintArray' is made and the sorted array is copied into this new array using:
    ```bash
    jintArray result = (env)->NewIntArray(n);
    env->SetIntArrayRegion(result,0,n,arr);
    ```
    This sorted jintArray is returned from the native method.\
    The returned sorted array received in the java main method is then printed.

* #### Question 4. Calling a Java Method from Native Code 
    Class callbacks is defined.\
    Class contains 5 String data members:
    * 2 private static Strings: city, pincode
    * 3 private Strings: name, university, branch

    Class also contains:
    * Static member method: staticMethod() -> prints static data members city and pincode.
    * Member methods: 
        * objectMethod() -> print data members name, university, branch
        * callmethod() -> to input and set values to the data members

    In the main function, object of class callbacks is made.\
    callmethod() is called using the object.\
    The native method is then called using the object:
    ```bash
    public native void nativeMethod();
    ```
    In the native function, the object is accessed using :
    ```bash
    jclass cls = env->GetObjectClass(obj);
    ```
    The function accesses the static and normal member methods of the class using:
    ```bash
    jmethodID sid = env->GetStaticMethodID(cls, "staticMethod", "()V");
    jmethodID nid = env->GetMethodID(cls, "objectMethod", "()V");
    ```
    The member methods are then called using:
    ```bash
    env->CallStaticVoidMethod(cls, sid);
    env->CallVoidMethod(obj, nid);
    ```
    This prints out the values of the data members.

* #### Question 5. Accessing Java Member Variables and change the value of member variables in native method.
    Class student is defined.\
    Class contains 3 String data members:
    * name
    * university
    * branch

    The class also contains:
    * Constructor (parameterized constructor) that sets values to the data members.
        ```bash
        public student(String name, String university, String branch)
        ```
    * Member method that prints the values in the data members.
        ```bash
        public void objectMethod()
        ```
    In the main function, the user inputs values for the data members.\
    Object of class student is created by calling the parameterised constructor:
    ```bash
    student s =  new student(name_input,university_input,branch_input)
    ```
    The user then inputs new updated values for the data members.\
    Native method are called sending the updated inputs as arguments.
    ```bash
    s.nativeMethod(name_input,university_input,branch_input);
    ```
    In the native function, the object is accessed using :
    ```bash
    jclass cls = env->GetObjectClass(obj);
    ```
    The values sent in parameters are accessed using:
    ```bash
    jfieldID name_ID = env->GetFieldID(cls,"name","Ljava/lang/String;");
    jfieldID university_ID = env->GetFieldID(cls,"university","Ljava/lang/String;");
    jfieldID branch_ID = env->GetFieldID(cls,"branch","Ljava/lang/String;");
    ```
    The values in the data members are then changed/updated to the values sent as parameters using:
    ```bash
    env->SetObjectField(obj,name_ID,name);
    env->SetObjectField(obj,university_ID,university);
    env->SetObjectField(obj,branch_ID,branch); 
    ```
    The values of the updated data members are then printed in the java main function by calling the method: objectMethod().

* #### Question 6. Catching & Throwing Exceptions Code should handle Divide by Zero Exception & NULL pointer exception
    Class exception is defined.\
    Class contains 2 member methods:
    * public void divideMethod():- causes divide exception
    * public void nullMethod():- causes null pointer exception
    In the main function, call the native method in the try block using object of exception class:
    ```bash
    obj.NativeExceptionThrow();
    ```
    In the native function, the object is accessed using :
    ```bash
    jclass cls = env->GetObjectClass(obj);
    ```
    Get the method ID of both the java member methods using:
    ```bash
    jmethodID mid1 = env->GetMethodID(cls, "divideMethod", "()V");
    jmethodID mid2 = env->GetMethodID(cls, "nullMethod", "()V");
    ```
    Using rand(), randomly call either the divideMethod() or the nullMethod() using:
    ```bash
    env->CallVoidMethod(obj, mid1);
    env->CallVoidMethod(obj, mid2);
    ```
    Check if an exception has occured in the method called:
    ```bash
    jthrowable exc = (env)->ExceptionOccurred();
    ```
    If exception has occured, find the type of excpetion that occured:
    ```bash
    jclass excClass = (env)->FindClass("java/lang/ArithmeticException");
    jclass excClass = (env)->FindClass("java/lang/NullPointerException");
    ```
    Throw the exception by:
    ```bash
    (env)->ThrowNew(excClass, "Divide by zero thrown from C++ code");
    (env)->ThrowNew(excClass, "Null Pointer Exception thrown from C++ code");
    ```
    The exception thrown is caught in java main in the catch block:
    ```bash
    catch(ArithmeticException e){
        System.out.println("Divide by zero operation cannot possible");
    }catch(NullPointerException e){
            System.out.println("NullPointException caught");
    }
    ```

## Authors
- BT19CSE035 (Harshini Pillarisetti)
- BT19CSE036 (Hasan Koser)