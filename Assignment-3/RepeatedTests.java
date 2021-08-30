import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;

import org.junit.jupiter.api.RepeatedTest;

public class RepeatedTests {
	private ArrayList<Contact>list = new ArrayList<Contact>();
	
	@RepeatedTest(5)
	public void shouldTestContactCreationRepeatedly() {
		long phonenumber = ThreadLocalRandom.current().nextLong(1000000001L, 9999999999L);
		list.add(new Contact("John", String.valueOf(phonenumber)));
        
		assertFalse(list.isEmpty());
        assertEquals(1, list.size());
        assertNotNull(list.get(0).getPhoneNumber());
        System.out.println("The value of phone Number is: "+list.get(0).getPhoneNumber());
	}
}