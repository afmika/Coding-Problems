import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the fibonacciModified function below.
    static BigInteger fibonacciModified(int t1, int t2, int n) {
        BigInteger tN_2 = BigInteger.valueOf(t1);
        BigInteger tN_1 = BigInteger.valueOf(t2);
        
        if (n == 1) return tN_2;
        if (n == 2) return tN_1;

        for (int i = 3; i <= n; i++) {
            // tN = tN-1 ^ 2 + tN-2
            BigInteger prev = tN_1;
            tN_1 = tN_1.multiply(tN_1).add(tN_2);       
            tN_2 = prev; 
        }
        return tN_1;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] t1T2n = scanner.nextLine().split(" ");

        int t1 = Integer.parseInt(t1T2n[0]);

        int t2 = Integer.parseInt(t1T2n[1]);

        int n = Integer.parseInt(t1T2n[2]);

        BigInteger result = fibonacciModified(t1, t2, n);

        bufferedWriter.write(result.toString());
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
