class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // edge case
        int k = 2; // first two elements are always allowed

        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[k-2]) {
                nums[k++] = nums[i];
            }
        }
        
        return k;
    }
};

/* ignore duplicate elements, check for k-2 only. dont need to check for element right before because we need to check for maximum 2 occurances only.
so if the same element exists at k-2, just ignore it and move forward because we dont need more than 2 occurances */

// time complexity = O(n)
// space complexity = (1) , not using any additional space