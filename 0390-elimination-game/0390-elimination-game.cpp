
class Solution {
public:
    int lastRemaining(int n) {

        int head = 1;
        int step = 1;
        int remaining = n;

        bool leftToRight = true;

        while (remaining > 1) {

            // Update head
            if (leftToRight || remaining % 2 == 1) {
                head += step;
            }

            // Half of the elements remain
            remaining /= 2;

            // Distance between elements doubles
            step *= 2;

            // Change direction
            leftToRight = !leftToRight;
        }

        return head;
    }
};
