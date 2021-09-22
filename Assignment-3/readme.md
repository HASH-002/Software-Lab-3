# JAVA TESTING
## Installation

Step 1: Download the JUnit jar file\
Step 2: Add external JUnit jar files and JUnit libraries to the project on Eclipse

## Documentation

* #### Question 1. Unit Testing
    Unit Testing  is a type of software testing where individual units or components of a software are tested. Unit test is a piece of code which tests behavious of a function or a class. The purpose is to validate that each unit of the software code performs as expected. Unit Testing is done during the development (coding phase) of an application by the developers. Unit Tests isolate a section of code and verify its correctness. A unit may be an individual function, method, procedure, module, or object.
    * Unit tests help to fix bugs early in the development cycle and save costs.
    * It helps the developers to understand the testing code base and enables them to make changes quickly
    * Good unit tests serve as project documentation
    * Unit tests help with code re-use. Migrate both your code and your tests to your new project. Tweak the code until the tests run again.

    In order to do Unit Testing, developers write a section of code to test a specific function in software application. Developers can also isolate this function to test more rigorously which reveals unnecessary dependencies between function being tested and other units so the dependencies can be eliminated. Developers generally use UnitTest framework to develop automated test cases for unit testing.
    Unit Testing is of two types
    * Manual Testing
    * Automatic Testing

* #### Question 2. Test Driven Development

    Test-Driven Development (TDD) is a software development process which includes test-first development. It is a  practice that focuses on creating unit test cases before developing the actual code. It is an iterative approach that combines programming, the creation of unit tests, and refactoring. It means that the developer first writes a fully automated test case before writing the production code to fulfil that test and refactoring. Steps for the same are given below -
    Step 1: Firstly, add a test.
    Step 2: Run all the tests and see if any new test fails.
    Step 3: Update the code to make it pass the new tests.
    Step 4: Run the test again and if they fail then refactor again and repeat.

    Test-Driven development is a process of developing and running automated test before actual development of the application. Hence, TDD sometimes also called as Test First Development.
    
    Test-Driven Development starts with designing and developing tests for every small functionality of an application. TDD framework instructs developers to write new code only if an automated test has failed. This avoids duplication of code.

* #### Question 3. Implementing assertions

    Test annotation (@Test):
    The public void method to which it is attached is run as a test case.

    JUnitClass runs 2 test methods:
    ```bash
    public void checkAssertNull()
    public void checkAssertTrue()
    ```

    The above methods implement 2 assertions: assertNull and assertTrue
    * assertNull : Checks whether the object passed is null
    * assertTrue : Checks whether the condition passed is true

    In Main class, run the JUnitClass:
    ```bash
    Result result = JUnitCore.runClasses(JUnitClass.class);
    ```

    Check for failure:
    ```bash
    Failure failure : result.getFailures()
    ```

    Print the failure or check if the Test is successful:
    ```bash
    System.out.println(failure.toString());
    System.out.println("Result=="+result.wasSuccessful());
    ```

    Import packages in Main.java:
    ```bash
    import org.junit.runner.JUnitCore;
    import org.junit.runner.Result;
    import org.junit.runner.notification.Failure;
    ```

    Import packages in JUnitClass.java
    ```bash
    import static org.junit.Assert.assertNull;
    import static org.junit.Assert.assertTrue;
    import org.junit.Test;
    ```

* #### Question 4. Test exception thrown using assertThrows

    Class Password has private String data member : password\
    Member method : public void setPassword(String pw)

    The method throws error if String pw is null or if the pw length is less than 8:
    ```bash
    throw new IllegalArgumentException("Password cannot be blank");
    throw new IllegalArgumentException("Password too short");
    ```

    Class PasswordTest with 2 methods :
    ```bash
    public void testPasswordIsNull()
    public void testPasswordTooShort()
    ```

    In the above methods, object of class Password is made and setPassword method is called.\
    The exception thrown is caught by:
    ```bash
    Throwable exception = assertThrows(
	            IllegalArgumentException.class, () -> {
	                Password pw = new Password();
	                pw.setPassword(null);
	            }
	    );
    ```

    The exceptions caught is checked whether the correct exception is thrown using assertEquals:
    ```bash
    assertEquals("Password cannot be blank", exception.getMessage());
    assertEquals("Password too short", exception.getMessage());
    ```

* #### Question 5. Implementing test life cycle hook 

    The Life Cycle Hooks implemented are:
    * `@BeforeAll`: This annotation executes a method before all tests. This is analogous to JUnit 4’s @BeforeClass. The  @BeforeAll annotation is typically used to initialize various things for the tests.
    * `@BeforeEach` - The @BeforeEach annotation denotes that the annotated method should be executed before each test method, analogous to JUnit 4’s @Before.
    * `@AfterAll` - The @AfterAll annotation is used to execute the annotated method, only after all tests have been executed. This is analogous to JUnit 4’s @AfterClass. We use this annotation to tear down or terminate all processes at the end of all tests.
    * `@AfterEach` - This annotation denotes that the annotated method should be executed after each test method.For example, if the tests need to reset a property after each test, we can annotate a method with @AfterEach for that task. 

    Class LifeCycle has member methods:
    ```bash
    public int factorial(int a)
    public int gcd(int a, int b)
    ```

    Class LifeCycleTest has the following data member and  member methods:
    ```bash
    private static LifeCycle lifecycle;
    public void factorialTest()
    public void gcdTest()
    static void start()
    void beforeEach()
    void afterEach()
    static void afterAll()
    ```

    `@Test` annotation is used for the two methods which will test the methods `factorial(a)` and `gcd(a,b)` using assertEquals:
    ```bash
    assertEquals(120,lifecycle.factorial(5));
    assertEquals(2,lifecycle.gcd(6, 2));
    ```

    `@BeforeAll` annotation is used for setting up the lifecycle object in the `start()` method:
    ```bash
    lifecycle=new LifeCycle();
    ```

    `@AfterAll` annotation is used for the method `afterAll()` which will set the lifecycle object to NULL at the end of testing.

* #### Question 6. Implementing @RepeatedTest annotation

    Class Contact has private String data members : name and phoneNumber\
    Member method : public String getPhoneNumber()

    Class RepeatedTests\
    Data Member : arraylist of contact
    Member Method : public void shouldTestContactCreationRepeatedly()

    In the this method, object of class Contact is added to the list. The phoneNumber of 10 digits was made with the use of ThreadLocalRandom in java.
    ```bash
		long phonenumber = ThreadLocalRandom.current().nextLong(1000000001L, 9999999999L);
		list.add(new Contact("John", String.valueOf(phonenumber)));
    ```

    Lastly results are checked by assertion statements and results are displayed using `getPhoneNumber()` method.
    ```bash
		assertFalse(list.isEmpty());
        assertEquals(1, list.size());
        assertNotNull(list.get(0).getPhoneNumber());
        System.out.println("The value of phone Number is: "+list.get(0).getPhoneNumber());
    ```

* #### Question 7. Implementing Parameterized Tests

    Parameterized tests makes it possible to run test methods multiple times with different arguments.
    They are declared with `@ParameterizedTest` annotation.
    Additionally we must declare atleast one source that will provide arguments for each time the test is run.

    Class ParametrizedTest will have the test methods which takes the aruguments from the following sources :
    *  @ValueSource - We can use this annotation to specify a single array of literal values and can  be used for providing a single argument per parameterized test invocation.
    ```bash
    @ValueSource(strings = {"mom","dad","level"})
    ```
    * @NullSource & @EmptySource - This annotation can be used to provide single null argument or empty argument to the test method.
    ```bash
    @ValueSource(strings = { " ", "   ", "\t", "\n", "" })
    ```
    * @EnumSource - It provides enum class constants as the arguments to @ParameterizedTest method.
    A custom enum class Month to represent the months is created as follows with suitable constructors and getter methods.
    ```bash
    January(1,31),
    February(2,28),
    March(3,31),
    April(4,30),
    May(5,31),
    June(6,30),
    July(7,31),
    August(8,31),
    September(9,30),
    October(10,31),
    November(11,30),
    December(12,31);
    ```
    We can pass all the constants of the enum class as an argument to test method in each iteration by using below annotation
    ```bash
    @EnumSource(Month.class)
    ```
    The @EnumSource annotation also provides an optional mode attribute that enables fine-grained control over which constants are passed to the test method
    ```bash
    @EnumSource(value = Month.class, names = {"April", "June", "September", "November"})
    @EnumSource(value = Month.class, names = ".+ber", mode = EnumSource.Mode.MATCH_ANY)
    ```

    * @MethodSource - @MethodSource allows you to refer to one or more factory methods of the test and the Factory methods within the test class must be static.

    We have a internal method `fruits` which returns an array of literals
    ```bash
    private static String[] fruits() {
            return new String[] {"apple","banana","cherry"};
        }
    ```
    This method can be used as a source with below annotation
    ```bash
    @MethodSource("fruits")
    ```
    We can also have methods defined externally as source to the parameterized test.
    ```bash
    @MethodSource("JUnitAssign.MyUtils#fruitsExtClass")
    ```
    Here JUnitAssign is the package which contains the class MyUtils which has a fruitsExtClass() method.

    * @CsvSource - Allows you to express argument lists as comma-separated values (i.e., String literals).
    ```bash
    @CsvSource({"test,TEST", "tEst,TEST", "Java,JAVA"})
    ```

## Authors
- [@Hasan Koser](https://www.github.com/HASH-002)
- [@Harshini Pillarisetti](https://github.com/Harshi194)
