class Solution {
public:
    int numberOfSubstrings(string s) {
  int n = s.size();
          vector<int> prefZero(n+1, 0);
                  for (int i = 0; i < n; ++i)
                              prefZero[i+1] = prefZero[i] + (s[i] == '0');

                                      // Map prefix-zero value -> list of indices where prefZero == value
                                              unordered_map<int, vector<int>> pos;
                                                      pos.reserve(n*2);
                                                              for (int idx = 0; idx <= n; ++idx) {
                                                                          pos[prefZero[idx]].push_back(idx);
                                                                                  }

                                                                                          // compute safe LIMIT for z such that z*z + z <= n
                                                                                                  int LIMIT = 0;
                                                                                                          while ((long long)LIMIT * LIMIT + LIMIT <= n) ++LIMIT;
                                                                                                                  LIMIT = max(0, LIMIT - 1);

                                                                                                                          long long ans = 0;
                                                                                                                                  for (int i = 0; i < n; ++i) {
                                                                                                                                              for (int z = 0; z <= LIMIT; ++z) {
                                                                                                                                                              long long needLen = 1LL*z*z + z;   // minimum substring length
                                                                                                                                                                              long long L = (long long)i + needLen; // minimal ending index + 1 (pos = j+1)
                                                                                                                                                                                              if (L > n) break; // no valid j for larger z

                                                                                                                                                                                                              int target = prefZero[i] + z;
                                                                                                                                                                                                                              auto itmap = pos.find(target);
                                                                                                                                                                                                                                              if (itmap == pos.end()) continue;
                                                                                                                                                                                                                                                              const vector<int> &vec = itmap->second;

                                                                                                                                                                                                                                                                              int needPos = (int)max((long long)(i+1), L); // pos = j+1 must be >= this
                                                                                                                                                                                                                                                                                              auto it = lower_bound(vec.begin(), vec.end(), needPos);
                                                                                                                                                                                                                                                                                                              ans += (vec.end() - it);
                                                                                                                                                                                                                                                                                                                          }
                                                                                                                                                                                                                                                                                                                                  }

                                                                                                                                                                                                                                                                                                                                          return (int)ans;
        
    }
};