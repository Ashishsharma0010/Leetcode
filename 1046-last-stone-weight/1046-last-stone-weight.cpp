
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        // Insert all stones into max heap
        for (int x : stones) {
            pq.push(x);
        }

        // Smash the two heaviest stones
        while (pq.size() > 1) {

            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if (x != y) {
                pq.push(x - y);
            }
        }

        // Return remaining stone
        if (pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};
