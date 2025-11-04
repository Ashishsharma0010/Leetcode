class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
 int n = nums.size();
         vector<int> ans;
                 for (int i = 0; i <= n - k; i++) {
                             vector<int> window(nums.begin() + i, nums.begin() + i + k);
                                         unordered_map<int, int> freq;
                                                     for (int num : window) freq[num]++;
                                                                 vector<pair<int, int>> freqList(freq.begin(), freq.end());
                                                                             sort(freqList.begin(), freqList.end(), [](auto &a, auto &b) {
                                                                                             if (a.second == b.second) return a.first > b.first;
                                                                                                             return a.second > b.second;
                                                                                                                         });
                                                                                                                                     unordered_set<int> topX;
                                                                                                                                                 for (int j = 0; j < x && j < freqList.size(); j++) topX.insert(freqList[j].first);
                                                                                                                                                             int total = 0;
                                                                                                                                                                         for (int num : window) if (topX.count(num)) total += num;
                                                                                                                                                                                     ans.push_back(total);
                                                                                                                                                                                             }
                                                                                                                                                                                                     return ans;       
    }
};