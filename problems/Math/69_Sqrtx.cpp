class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;  // edge case

        int left = 1;
        int right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid < x / mid) {  // (mid * mid < x) will cause overflow issues so we divide mid on both sides to avoid it
                left = mid + 1;
            } else if (mid > x / mid) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return right;
    }
};