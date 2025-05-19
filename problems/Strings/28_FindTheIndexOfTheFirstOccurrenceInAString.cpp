class Solution {
public:
    int strStr(string haystack, string needle) {
    int m = needle.size(), n = haystack.size();
    if (m == 0) return 0;

    // compute LPS array
    vector<int> lps(m, 0);
    for (int i = 1, j = 0; i < m; ) {
        if (needle[i] == needle[j]) 
            lps[i++] = ++j;
        else if (j != 0) 
            j = lps[j - 1];
        else 
            lps[i++] = 0;
    }

    // kmp search
    for (int i = 0, j = 0; i < n; ) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
            if (j == m)
                return i - j;  // match found
        } else if (j != 0) 
            j = lps[j - 1];  // backtrack
        else 
            i++;
    }
    
    return -1;
}
};