import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.EnumSet;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.jupiter.params.provider.EmptySource;
import org.junit.jupiter.params.provider.EnumSource;
import org.junit.jupiter.params.provider.MethodSource;
import org.junit.jupiter.params.provider.NullAndEmptySource;
import org.junit.jupiter.params.provider.NullSource;
import org.junit.jupiter.params.provider.ValueSource;

public class ParametrizedTest {
	
	/* -----------------ValueSource Test----------------- */
	@ParameterizedTest
	@ValueSource(strings = {"mom","dad","level"})
	void palindromesTest(String inputText) {
		assertTrue(MyUtils.isPalindrome(inputText));
	}
	
	
	/* ------NullSource, EmptySource and NullAndEmptySource Test----------- */
	@ParameterizedTest
	@NullSource
	@EmptySource
	@ValueSource(strings = { " ", "   ", "\t", "\n", "" })
	void nullEmptyAndBlankStringsTest(String inputText) {
	    assertTrue(inputText == null || inputText.trim().isEmpty());
	}
	
	@ParameterizedTest
	@NullAndEmptySource
	@ValueSource(strings = { " ", "   ", "\t", "\n", "" })
	void nullAndEmptySourceStringsTest(String inputText) {
	    assertTrue(inputText == null || inputText.trim().isEmpty());
	}
	
	
	/* -----------------EnumSource Test----------------- */
	@ParameterizedTest
	@EnumSource(Month.class) // passing all 12 months
	void getValueForAMonth_IsAlwaysBetweenOneAndTwelve(Month month) {
	    int monthNumber = month.getValue();
	    assertTrue(monthNumber >= 1 && monthNumber <= 12);
	}
	
	@ParameterizedTest
	@EnumSource(value = Month.class, names = {"April", "June", "September", "November"})
	void someMonths_Are30DaysLong(Month month) {
	    assertEquals(30, month.getLength());
	}
	
	@ParameterizedTest
	@EnumSource(value = Month.class, names = ".+ber", mode = EnumSource.Mode.MATCH_ANY)
	void fourMonths_AreEndingWithBer(Month month) {
	    EnumSet<Month> months =
	      EnumSet.of(Month.September, Month.October, Month.November, Month.December);
	    assertTrue(months.contains(month));
	}
	
	
	/* -----------------MethodSource Test----------------- */
	private static String[] fruits() {
		return new String[] {"apple","banana","cherry"};
	}
	
	@ParameterizedTest
	@MethodSource("fruits")
	void methodSourceTest(String fruitName) {
	    assertNotNull(fruitName);
	}
	
	@ParameterizedTest
	@MethodSource("JUnitAssign.MyUtils#fruitsExtClass")
	void testWithExternalMethodSource(String fruitName) {
	    assertNotNull(fruitName);
	}
	
	
	/* -----------------CsvSource Test----------------- */
	@ParameterizedTest
	@CsvSource({"test,TEST", "tEst,TEST", "Java,JAVA"})
	void csvSourceTest(String input, String expected) {
	    String actualValue = input.toUpperCase();
	    assertEquals(expected, actualValue);
	}
}