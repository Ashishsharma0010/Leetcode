#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
     unordered_map<long long, int> countSame;
     map<long long, long long> diff;
      for (long long x : nums) {
        countSame[x]++;
          diff[x - k] += 1;
          diff[x + k + 1] -= 1;
        }
   for (auto &p : countSame) diff[p.first] += 0;
    long long active = 0;
        int maxFreq = 0;
         for (auto& [val, delta] : diff) {
            active += delta;
        int already = countSame.count(val) ? countSame[val] : 0;
            int possible = (int)min(active, (long long)already +numOperations);
       maxFreq = max(maxFreq, possible);
  }
  return maxFreq;
   }
  };
