class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pS = 0; int pT = 0;
        int sizeS = s.length();
        int sizeT = t.length();

        if (sizeS == 0) return true;
        if (sizeT == 0) return false;

        while (pT < sizeT) {
            if (s[pS] == t[pT]) {
                pS++; pT++;

                if (pS == sizeS) {
                    return true;
                }
            }

            else {
                pT++;
            }           
        }

        return false;

    }
};