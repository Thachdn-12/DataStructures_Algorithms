/**
 * 383. Ransom Note
 */

#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
        bool canConstruct(string ransomNote, string magazine){
            /**
             * Create containter to contain all character in magazine
             */
            vector<int> charCount(26,0);
            /**
             * Count frequence of character in magazine
             */
            for(char c:magazine){
                charCount[c - 'a'] ++;
            }

            /**
             * Check all character in ransomNote, is there enough the character of magazine in ransomNote
             */
            for(char c:ransomNote){
                charCount[c-'a'] --;
                if(charCount[c-'a'] < 0){
                    return false;
                }
            }
            return true;
        }
};

int main(){
    solution sol;
    string ransomNote = "aa";
    string magazine = "aba";
    bool ret;
    ret = sol.canConstruct(ransomNote,magazine);
    cout<<ret<<endl;
    return 0;
}