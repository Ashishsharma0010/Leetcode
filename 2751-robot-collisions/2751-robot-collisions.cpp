#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st;
        vector<bool> alive(n, true);

        for (int i : idx) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                while (!st.empty()) {
                    int top = st.top();
                    if (healths[top] > healths[i]) {
                        healths[top]--;
                        alive[i] = false;
                        break;
                    } else if (healths[top] < healths[i]) {
                        healths[i]--;
                        alive[top] = false;
                        st.pop();
                    } else {
                        alive[top] = false;
                        alive[i] = false;
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (alive[i]) result.push_back(healths[i]);
        }
        return result;
    }
};