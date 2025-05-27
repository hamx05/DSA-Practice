class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate = -1;

        for (int i=0; i<n; i++) {
            if (count == 0) {
                candidate = nums[i];
                count++;
            }

            else if (nums[i] == candidate) {
                count++;
            }

            else {
                count--;
            }
        }

        return candidate;
    }
};

/* if count is zero, we just pick the current element as our candidate and set count to 1, since we’ve seen it once now.
As we keep going, if the element matches the candidate, we increase the count. If it doesn’t, we decrease the count.
By doing this, we’re basically canceling out different elements, and the majority one survives in the end.

practice dry runs
nums = [3, 3, 4]
nums = [2, 1, 2, 1, 2]
nums = [1, 1, 2, 2, 2, 2]
nums = [4, 4, 4, 2, 3, 1]
nums = [5, 5, 5, 5]
nums = [1, 2, 1, 2, 1, 1]

*/
