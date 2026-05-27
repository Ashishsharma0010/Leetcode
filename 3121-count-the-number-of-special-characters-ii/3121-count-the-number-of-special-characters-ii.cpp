class Solution {
public:
    int numberOfSpecialChars(string word) {

        int n = word.length();

        int count = 0;

        vector<int> lastsmall(26, -1);
        vector<int> firstcap(26, -1);

        for(int i = 0; i < n; i++) {

            char ch = word[i];

            if(islower(ch)) {

                lastsmall[ch - 'a'] = i;

            }
            else {

                if(firstcap[ch - 'A'] == -1) {

                    firstcap[ch - 'A'] = i;
                }
            }
        }

        for(int i = 0; i < 26; i++) {

            if(lastsmall[i] != -1 &&
               firstcap[i] != -1 &&
               lastsmall[i] < firstcap[i]) {

                count++;
            }
        }

        return count;
    }
};