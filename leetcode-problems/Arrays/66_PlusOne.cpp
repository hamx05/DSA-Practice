class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the last digit and handle the carry
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                // No carry needed, increment and return
                digits[i]++;
                return digits;
            }
            // Set current digit to 0 and propagate carry
            digits[i] = 0;
        }

        // If all digits were 9, we need an extra leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
