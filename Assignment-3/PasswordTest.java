import static org.junit.Assert.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import org.junit.Test;

public class PasswordTest {
	
	@Test
	public void testPasswordIsNull() {
	 
	    Throwable exception = assertThrows(
	            IllegalArgumentException.class, () -> {
	                Password pw = new Password();
	                pw.setPassword(null);
	            }
	    );
	    assertEquals("Password cannot be blank", exception.getMessage());
	}
	@Test
	public void testPasswordTooShort() {
	 
	    Throwable exception = assertThrows(
	            IllegalArgumentException.class, () -> {
	                Password pw = new Password();
	                pw.setPassword("abcde");
	            }
	    );
	    assertEquals("Password too short", exception.getMessage());
	}

}