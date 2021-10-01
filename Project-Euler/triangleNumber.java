import java.math.*;
import java.util.*;

public class Main {
    static int countDivisors (int n) {
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) c++;
        }
        return c;
    }
    static boolean isPrime (int n) {
        BigInteger value = BigInteger.valueOf(n);
        return value.isProbablePrime (1);
    }
    
    static int triangle (int n) {
        return n*(n + 1) / 2;
    }
    
	public static void main(String[] args) {
	    int n = 2, nax = -1;
	    while (nax < 500) {
	        nax = Math.max(nax, countDivisors (n++));
	    }
	    System.out.println(n - 1);
	}
}
