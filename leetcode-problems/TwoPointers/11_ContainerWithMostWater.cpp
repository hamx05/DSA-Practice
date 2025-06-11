class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int minHeight = min(height[left], height[right]);
            int distance = right - left;
            int area = minHeight * distance;
            maxArea = max(maxArea, area);

            // move the pointer thats at the shorter line because only that one has a chance of increasing the area
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};

/* Start from both ends and keep checking the area between the lines.
Always move the pointer at the shorter line, that’s the only chance to find a taller line and possibly a bigger area.
Do this while left < right, by the end, we’ll have tried all the best possible height combinations and maxArea will be stored. */