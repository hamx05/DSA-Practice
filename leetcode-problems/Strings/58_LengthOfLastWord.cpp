// logic:
// start from the end, remove the extra spaces after the last word from the string
// once the spaces are removed, start loop from end of the string and count the letters of the word until u find a space

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;

        // first skip trailing spaces
        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        // once done, then count characters of last word
        int length = 0;
        while (end >= 0 && s[end] != ' ') {
            length++;
            end--;
        }

        return length;
    }
};