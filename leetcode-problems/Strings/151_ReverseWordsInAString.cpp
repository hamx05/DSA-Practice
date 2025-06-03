class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        if (n == 0) return "";

        int left = n - 1;
        string ans;

        while (left >= 0) {
            // skip trailing spaces
            while (left >= 0 && s[left] == ' ')
                left--;
            
            if (left < 0) break;

            int right = left; // right = last letter of the word

            // now, move left to the beginning of the word
            while (left >= 0 && s[left] != ' ')
                left--;

            // append space if needed
            if (!ans.empty()) ans += ' ';

            // append the word
            for (int i = left + 1; i <= right; i++) {
                ans += s[i];
            }
        }

        return ans;
    }
};

/* my logic: we move from the end of the string, skip spaces, and pick words one by one by tracking their start and end.
each word gets added to the result string, and we only add a space if it's not the first word.
this keeps the spacing clean and reverses the word order at the same time.

dry run this for better understanding:
s = "  hello world  "       */