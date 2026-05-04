#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution{
    public:
        string encode(vector<string>& strs){
            if(strs.empty()) return "";
            string res = "";
            for(auto s:strs){
                res += to_string(s.size()) +'#' + s;
            }
            return res;
        }

        vector<string> decode(string s){
            vector<string> res;
            int i = 0;
            while(i < s.size()){
                int j = i;
                while(s[j] != '#'){
                    j += 1;
                }
                int length = s[j-1] - '0';
                int c = 0;
                string temp_str = "";
                while(c < length){
                    temp_str += s[j + c +1];
                    c++;
                }
                res.push_back(temp_str);
                i = j + 1 + length;
            }
            return res;
        }
        
};

int main(){
    solution sol;
    vector<string> strs = {"hello", "world", "C++14"};
    string encoded = sol.encode(strs);
    cout << "Encoded string: " << encoded << endl;
    vector<string> decoded = sol.decode(encoded);
    cout<< "Decode string: "<<endl;
    for(string str:decoded){
        cout<<str<<" ";
    }
    return 0;
}