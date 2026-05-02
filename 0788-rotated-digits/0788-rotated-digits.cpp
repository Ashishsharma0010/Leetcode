class Solution {
public:
    int rotatedDigits(int n) {
        int rotate[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        
        int count = 0;
        for (int x = 1; x <= n; x++) {
            bool valid = true;
            bool different = false;
            
            int num = x;
            while (num > 0) {
                int d = num % 10;
                if (rotate[d] == -1) {
                    valid = false;
                    break;
                }
                if (rotate[d] != d) {
                    different = true;
                }
                num /= 10;
            }
            
            if (valid && different) count++;
        }
        
        return count;
    }
};