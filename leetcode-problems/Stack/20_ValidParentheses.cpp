class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        // Go through each character in the string
        for (char c : s) {
            // If it's an opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            }
            // If it's a closing bracket, check for a match
            else {
                if (stk.empty()) return false; // Nothing to match with

                char top = stk.top();
                stk.pop();

                // Check if it matches the correct opening bracket
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is empty at the end, it's valid
        return stk.empty();
    }
};
