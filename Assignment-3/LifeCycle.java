public class LifeCycle {
	public int factorial(int a)
	{
		int fact=1;
		for(int i=2; i<=a; i++)
			fact*=i;
		return fact;
	}

	public int gcd(int a, int b)
	{
		if (a == 0)
	        return b;
	    else if (b == 0)
	        return a;
	    while (a != b) {
	        if (a > b)
	            a = a - b;
	        else
	            b = b - a;
	    }
	    return a;
	}
}