class Solution {
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
                int n = potions.size();
                        sort(potions.begin(), potions.end());
                                vector<int> ans;
                                        ans.reserve(spells.size());
                                                
                                                        for (long long s : spells) {
                                                                    // minimum potion value required so that s * p >= success
                                                                                // required = ceil(success / s)
                                                                                            long long required = (success + s - 1) / s;
                                                                                                        auto it = lower_bound(potions.begin(), potions.end(), required);
                                                                                                                    ans.push_back((int)(potions.end() - it));
                                                                                                                            }
                                                                                                                                    return ans;
                                                                                                                                        }
                                                                                                                                        };

