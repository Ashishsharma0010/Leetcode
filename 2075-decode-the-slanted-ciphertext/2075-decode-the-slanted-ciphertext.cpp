class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.length();
        int cols = n / rows;
        string result = "";
        
        for (int startCol = 0; startCol < cols; startCol++) {
            int r = 0, c = startCol;
            while (r < rows && c < cols) {
                result += encodedText[r * cols + c];
                r++;
                c++;
            }
        }
        
        // Remove trailing spaces
        int end = result.length() - 1;
        while (end >= 0 && result[end] == ' ') end--;
        
        return result.substr(0, end + 1);
    }
};