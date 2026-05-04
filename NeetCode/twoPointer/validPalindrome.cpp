/*
    A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.
*/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

class solution{
    public:
        bool isPalindrome(string s){
            char r,l;
            while (l<r)
            {
                while (l<r && !isalnum(s[l]))
                {
                    l ++;
                }
                while(r>l && !isalnum(s[r])){
                    r --;
                }
                if(tolower(s[r]) !=  tolower(s[l])){
                    return false;
                }
                r --;
                l ++;
            }
            return true;
        }
};

int main(){
    string s = "Was it a car or a cat I saw?";
    solution sol;
    if(sol.isPalindrome(s)){
        cout<<"TRUE";
    }else{
        cout<<"FALSE";
    }

    return 0;
}