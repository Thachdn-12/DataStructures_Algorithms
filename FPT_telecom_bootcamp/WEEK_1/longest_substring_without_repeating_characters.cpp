/**
 * 3. Longest Substring Without Repeating Characters
 */

#include <iostream>

using namespace std;


class solution{
    public:
        int lengthOfLongSubstring(string s){
            int left = 0;
            int right = 0;
            int longestLength = 0;
            for(int i=0; i<s.length(); i++){
                for(int j=0; j<i; j++){
                    if(s[i] == s[j]){
                        left = i+1;
                    }
                }
                right ++;
                longestLength = max(longestLength, (right - left));
            }
            return longestLength;
            
        }
};

int main(){
    solution sol;
    string s = "abaccbb";

    int ret = sol.lengthOfLongSubstring(s);
    cout<<"The longest lenght of substring is "<<ret<<endl;
    return 0;
}