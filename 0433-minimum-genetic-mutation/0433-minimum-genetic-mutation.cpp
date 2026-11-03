
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        if (startGene == endGene) {
            return 0;
        }

        unordered_set<string> bankSet(bank.begin(), bank.end());

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        unordered_set<string> visited;
        visited.insert(startGene);

        string genes = "ACGT";

        while (!q.empty()) {

            auto [current, mutations] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {

                char original = current[i];

                for (char ch : genes) {

                    if (ch == original) {
                        continue;
                    }

                    current[i] = ch;

                    if (bankSet.count(current) &&
                        !visited.count(current)) {

                        if (current == endGene) {
                            return mutations + 1;
                        }

                        visited.insert(current);
                        q.push({current, mutations + 1});
                    }
                }

                current[i] = original;
            }
        }

        return -1;
    }
};
