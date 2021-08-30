import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;
import org.junit.Test;

public class JUnitClass {
	@Test
	public void checkAssertNull() {
		String str=null;
		assertNull(str);
	}
	@Test
	public void checkAssertTrue() {
		int num=5;
		assertTrue(num==5);
	}
}