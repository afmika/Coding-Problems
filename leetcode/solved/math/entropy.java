class Solution {
    public double calculateEntropy(int[] input) {
        Map<Integer, Double> P = new HashMap<> ();
        
        for (int in : input) {
            P.put(in, P.getOrDefault(in, 0.) + 1.);
        }
        
        double total = input.length, s = 0;
        
        Set<Integer> values = P.keySet ();
        for (Integer k : values) {
            double pi = P.get(k) / total;
            s += pi * Math.log(pi) / Math.log(2.);
        }
        
        // fix : rehefa C++
        // double d = Math.abs(s);
        // if (d <= 10e-6) return 0;
        return -s;
    }
}