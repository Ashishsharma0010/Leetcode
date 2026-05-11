class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;

        bool negative = (dividend > 0) ^ (divisor > 0);

        long a = dividend > 0 ? (long)dividend : -(long)dividend;
        long b = divisor > 0 ? (long)divisor : -(long)divisor;
        long result = 0;

        while (a >= b) {
            long temp = b;
            long multiple = 1;

            while (a >= (temp << 1) && (temp << 1) > 0) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        result = negative ? -result : result;

        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};