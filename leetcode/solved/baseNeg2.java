public class BaseNeg2 {
    public static String baseNeg2(int N) {
        StringBuilder result = new StringBuilder("");
        if(N <= 1)
            return N + "";
        int r = 0;
        while(true) {
            r = N % (-2);
            r += r < 0 ? 2 : 0;
            int q = ( -N + r ) / 2;
			result.insert(0, r);
            if(q > 0 && q < 2) {
                result.insert(0, q);
                break;
            }
            N = q;
        }
        return result.toString();
    }
	
	public static void main(String[] args) {
		System.out.println( baseNeg2(0) );
		System.out.println( baseNeg2(1) );
		System.out.println( baseNeg2(2) );
		System.out.println( baseNeg2(55) );
	}
}