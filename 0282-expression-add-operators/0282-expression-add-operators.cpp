class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string expr;
        backtrack(num, target, 0, 0LL, 0LL, expr, result);
        return result;
    }
    
private:
    void backtrack(const string& num, int target, int index, long long currValue, long long prevOperand, string& expr, vector<string>& result) {
        int n = num.size();
        
        if (index == n) {
            if (currValue == target) {
                result.push_back(expr);
            }
            return;
        }
        
        for (int i = index; i < n; i++) {
            if (i > index && num[index] == '0') break;
            
            string numStr = num.substr(index, i - index + 1);
            long long currNum = stoll(numStr);
            
            int exprLen = expr.size();
            
            if (index == 0) {
                expr += numStr;
                backtrack(num, target, i + 1, currNum, currNum, expr, result);
                expr.resize(exprLen);
            } else {
                expr += "+";
                expr += numStr;
                backtrack(num, target, i + 1, currValue + currNum, currNum, expr, result);
                expr.resize(exprLen);
                
                expr += "-";
                expr += numStr;
                backtrack(num, target, i + 1, currValue - currNum, -currNum, expr, result);
                expr.resize(exprLen);
                
                expr += "*";
                expr += numStr;
                backtrack(num, target, i + 1, currValue - prevOperand + prevOperand * currNum, prevOperand * currNum, expr, result);
                expr.resize(exprLen);
            }
        }
    }
};