class Solution {
public:
    int waviness(int n) {
        string s = to_string(n);
        if (s.size() < 3) return 0;
        int count = 0;
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] > s[i-1] && s[i] > s[i+1]) count++; // peak
            else if (s[i] < s[i-1] && s[i] < s[i+1]) count++; // valley
        }
        return count;
    }

    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int i = num1; i <= num2; i++)
            total += waviness(i);
        return total;
    }
};