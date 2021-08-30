public class MyUtils {
	
	// Method to check whether the string is palindrome or not
    public static boolean isPalindrome(String s) {
    	int i=0,j=s.length()-1;
    	while(i<j) {
    		if(s.charAt(i)!=s.charAt(j))
    			return false;
    		i++;
    		j--;
    	}
		return true;
    }
    
    public static String[] fruitsExtClass() {
		return new String[] {"grapes","berry"};
	}
}