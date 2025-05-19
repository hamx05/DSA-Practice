// Solution for LeetCode problem: 3SumClosest
// Problem number: 16

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // sort the array for two-pointer technique
        int resultSum = nums[0] + nums[1] + nums[2];
        int minDifference = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++) {
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

                if (threeSum == target) {
                    return target; // exact match found
                }

                int diffToTarget = abs(threeSum - target);
                if (diffToTarget < minDifference) {
                    // update the result sum
                    resultSum = threeSum;
                    minDifference = diffToTarget;
                }

                if (threeSum > target) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return resultSum;
    }
};