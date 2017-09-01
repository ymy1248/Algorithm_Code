class Solution {
    public double myPow(double x, int n) {
        if (n > 1) {
            double lastX = myPow(x, n/2);
            if (n % 2 == 0) {
                return lastX * lastX;
            } else {
                return lastX * lastX * x;
            }
        }
        if (n == 1) {
            return x;
        }
        if (n == 0) {
            return 1;
        }
		// for dealing with -2147483647 and 2147483648 problem
        if (n == Integer.MIN_VALUE) {
            return 1/ (myPow(x, Integer.MAX_VALUE) * x);
        }

        return 1 / myPow(x, -n);
    }
}
