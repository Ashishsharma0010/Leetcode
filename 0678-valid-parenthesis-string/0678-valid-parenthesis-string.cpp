class Solution {
public:
    bool checkValidString(string s) {
        int lowOpen = 0, highOpen = 0;

        for (char ch : s) {
            if (ch == '(') {
                lowOpen++;
                highOpen++;
            } else if (ch == ')') {
                lowOpen--;
                highOpen--;
            } else {
                lowOpen--;
                highOpen++;
            }

            if (highOpen < 0) return false;
            if (lowOpen < 0) lowOpen = 0;
        }

        return lowOpen == 0;
    }
};