// Solution for LeetCode problem: 3Sum
// Problem number: 15

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // sort the array for two-pointer technique

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i]; // current fixed number (first element of the triplet)
            
            // skip duplicates for 'a' to avoid redundant triplets
            if (i > 0 && a == nums[i - 1]) {
                continue;
            }

            // it now shrinks down to two sum II technique
            int l = i + 1; // left pointer starts after i
            int r = nums.size() - 1; // right pointer starts from the end
            while (l < r) {
                int threeSum = a + nums[l] + nums[r];

                if (threeSum > 0) {
                    r--;
                }
                else if (threeSum < 0) {
                    l++;
                }
                else {
                    res.push_back({a, nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r) { // move left forward but do not include any duplicate again
                        l++;
                    }
                }
            }
        }
        return res;
    }
};