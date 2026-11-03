
class Solution {
public:
    string decodeString(string s) {

        stack<int> countStack;
        stack<string> stringStack;

        string curr = "";
        int num = 0;

        for (char ch : s) {

            // If character is a digit
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // If opening bracket
            else if (ch == '[') {

                countStack.push(num);
                stringStack.push(curr);

                num = 0;
                curr = "";
            }

            // If closing bracket
            else if (ch == ']') {

                int k = countStack.top();
                countStack.pop();

                string prev = stringStack.top();
                stringStack.pop();

                string temp = "";

                // Repeat current string k times
                for (int i = 0; i < k; i++) {
                    temp += curr;
                }

                curr = prev + temp;
            }

            // If alphabet
            else {
                curr += ch;
            }
        }

        return curr;
    }
};
