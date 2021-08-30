import static org.junit.Assert.assertEquals;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;


public class LifeCycleTest {
	private static LifeCycle lifecycle;
	@BeforeAll
	static void start() {
		System.out.println("Testing Started");
		lifecycle=new LifeCycle();
	}
	
	@BeforeEach
	void beforeEach()
	{
		System.out.println("@BeforeEach executed");
	}

	@Test
	public void factorialTest()
	{
		System.out.println("Factorial Test");
		assertEquals(120,lifecycle.factorial(5));
	}
	
	@Test
	public void gcdTest()
	{
		System.out.println("GCD Test");
		assertEquals(2,lifecycle.gcd(6, 2));
	}

	@AfterEach
	void afterEach()
	{
		System.out.println("@AfterEach executed");
	}
		
	@AfterAll
	static void afterAll()
	{
		lifecycle=null;
		System.out.println("Testing done");
	}
}