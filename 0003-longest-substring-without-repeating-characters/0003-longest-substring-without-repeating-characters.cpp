class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longestLength = 0;

        for (int right = 0; right < s.length(); right++) {
            for (int i = left; i < right; i++) {

                if (s[i] == s[right]) {
                    left = i + 1;
                    break;
                }
            }
            longestLength = max(longestLength, right - left + 1);
        }

        return longestLength;
    }
};