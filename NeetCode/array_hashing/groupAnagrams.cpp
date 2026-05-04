#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs){
            unordered_map<string , vector<string>> map;
            for(const  auto& s:strs){ // The key word const means that the value of variable can not change during program execution, so we can only read its value, not modify it.
                vector<int> count(26,0);
                for(char c: s){
                    count[c - 'a'] ++;
                }
                string key = to_string(count[0]);
                for(int i = 1; i < 26; ++i){
                    key += ',' + to_string(count[i]);
                    cout<<"Key: "<<key<<"\n";
                }
                cout<<"+++++++++++++++++++++++++++++++++++++++++++\n";
                map[key].push_back(s);
            }
            vector<vector<string>> result;
            for(const auto& pair: map){
                result.push_back(pair.second);
                cout<<"Pair 1: "<<pair.first<<"\n";
            }

            return result;
        }
};

int main(){
    solution mySolution;
    vector<string> strs = {"act","pots","tops","cat","stop","hat"};

    vector<vector<string>> groupAnagram =  mySolution.groupAnagrams(strs);

    for(auto& group : groupAnagram){
        cout << "Pair 2 : [ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    return 0;
}