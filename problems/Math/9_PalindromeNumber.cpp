class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        vector<int> num;
        int temp = x;

        while (temp > 0) {
            num.push_back(temp % 10);
            temp /= 10;
        }

        // two pointers approach
        int left = 0, right = num.size() - 1;
        while (left < right) {
            if (num[left] != num[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
