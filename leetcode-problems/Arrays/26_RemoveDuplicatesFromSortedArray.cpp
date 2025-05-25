class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        int k = 0;

        temp[k++] = nums[0]; // first element is always unique

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) { // ignore duplicate elements
                nums[k++] = nums[i];
            }
        }
        
        return k;
    }
};

// time complexity = O(n)
// space complexity = (1) , not using any additional space