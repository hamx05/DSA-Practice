class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;

        for (int i=0; i<n; i++) {
            if (i > maxIndex) {
                return false; // 
            }
            maxIndex = max(maxIndex, i + nums[i]);
        }

        // if we're reaching here, means we faced no difficulty reaching the end, so return true
        return true;
    }
};

/* Greedy algorithm: basically, calculate the maximum jump you can make at every step.
If you reach an index greater than the maximum jump reachable so far, return false because you were never supposed to get there.
If the loop ends, return true because that means you faced no challenges reaching the end or beyond.

time complexity: O(n)
space compexity: O(1) 
video guide: https://www.youtube.com/watch?v=tZAa_jJ3SwQ */