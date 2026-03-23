class Solution { 
public: 
    string frequencySort(string s) {
       map<char, int> m;
        for(char c : s){
            m[c]++;
        }
        
        // Step 2: Store in vector
        vector<pair<char, int>> v;
        for(auto it : m){
            v.push_back({it.first, it.second});
        }
        
        // Step 3: Sort based on frequency (descending)
        sort(v.begin(), v.end(), [](pair<char,int> &a, pair<char,int> &b){
            return a.second > b.second;
        });
        
        // Step 4: Build result
        string ans = "";
        for(auto it : v){
            ans += string(it.second, it.first);
        }
        
        return ans;
    
        
    }
};