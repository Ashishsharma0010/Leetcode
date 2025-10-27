class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
int prev = 0;   // number of devices in previous non-empty row
       int result = 0;
          for (string &row : bank) {
              int curr = count(row.begin(), row.end(), '1');  // count devices in current row
           if (curr > 0) {
             result += prev * curr;  
              prev = curr;       
               }
          }

     return result;        
      
    }
};