/*
    Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
    An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

    Constraints:
        s and t consist of lowercase English letters.
*/

#include <iostream>
#include <vector>

class solution{
    public:
        bool isAnagram(std::string s, std::string t){
            if(s.length() != t.length()){
                return false;
            }
            std::vector<int> count(26,0);
            
            for(int i = 0; i < s.length(); i++){
                count[s[i] - 'a'] ++;
                count[t[i] - 'a'] --;
                std::cout<<"count[s["<<i<<"] - 'a'] = "<<count[s[i] - 'a']<<"\n";
                std::cout<<"count[t["<<i<<"] - 'a'] = "<<count[t[i] - 'a']<<"\n";
            }
            std::cout<<"\n----------------------------------\n";
            for(int value:count){
                if(value != 0){
                    std::cout<<"Value: "<<value<<"\n";
                    return false;
                }
            }
            return true;
        }
};

int main(){
    solution mySolution;

    std::string s = "racecar";
    std::string t = "carrace";

    mySolution.isAnagram(s,t);
    return 0;
}