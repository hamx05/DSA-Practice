class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int maxIndex = 0;
        int jumps = 0;
        int currentEnd = 0;

        for (int i=0; i<n-1; i++) {
            maxIndex = max(maxIndex, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = maxIndex;
            }
        }

        return jumps;
    }
};

/* Similar to Jump Game I, we're just tracking the farthest we can reach. When we reach the end of the current jump range, we jump and update it. 
Since reaching n-1 is guaranteed, we just count how many jumps it takes.

time complexity: O(n)
space compexity: O(1) */