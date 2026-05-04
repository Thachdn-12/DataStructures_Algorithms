/**
 *  389. Find the Difference
 */

#include <iostream>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(char c:s){
            r ^=c;
        } 
        for(char c:t){
            r ^=c;
        } 
        return r;
    }
};

int main(){
    Solution sol;
    string s = "abcd";
    string t = "abcde";
    char c;
    c = sol.findTheDifference(s,t);
    cout<<c<<endl;
    return 0;
}