// using the concept of merging from merge sort algorithm.
// time complexity will be O(2*(m+n)), dropping the constants, it'll be O(m+n)
// we're using 1 temp array to store and copy elements, so space complexity will be O(m+n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> temp(m + n);
        int currIndex = 0;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp[currIndex] = nums1[i];
                currIndex++; i++;
            }
            else if (nums2[j] < nums1[i]) {
                temp[currIndex] = nums2[j];
                currIndex++; j++;
            }
        }

        while (i < m) {
            temp[currIndex] = nums1[i];
            currIndex++; i++;
        }

        while (j < n) {
            temp[currIndex] = nums2[j];
            currIndex++; j++;
        }

        for (int k=0; k<m+n; k++) {
            nums1[k] = temp[k];
        }
    }
};