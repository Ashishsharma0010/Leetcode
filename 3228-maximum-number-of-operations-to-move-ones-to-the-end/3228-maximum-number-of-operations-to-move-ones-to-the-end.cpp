class Solution {
public:
    int maxOperations(string s) {
     long long ones = 0;
    long long ops = 0;
           int n = s.size();
 for (int i = 0; i < n; ++i) {
         if (s[i] == '1') {
                 ++ones;
   } else {
          if (i == 0 || s[i-1] == '1') {
              ops += ones;
           }
        }
          }

            return ops;
        
    }
};