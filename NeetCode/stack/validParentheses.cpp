#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class solution{
    public:
        bool isValid_bruteForce(string s){
            while(true){
                size_t position = string::npos;
                if((position = s.find("()")) != string::npos){
                    s.erase(position,2);
                    continue;
                }
                if((position = s.find("{}")) != string::npos){
                    s.erase(position,2);
                    continue;
                }
                if((position = s.find("[]")) != string::npos){
                    s.erase(position,2);
                    continue;
                }
                break;
            }
            return s.empty();
        }
        bool isValid_stack(string s){
            unordered_map<char,char> mp = { 
                {')','('},
                {'}','{'},
                {']','['}
            };
            stack<char> st;
            for(char c:s){
                if(mp.count(c)){
                    if(!st.empty() && st.top() == mp[c]){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    st.push(c);
                }
            }
            return st.empty();
        }
};

int main(){
    solution sol;
    string s = "([{}])";

    if(sol.isValid_stack(s) == true){
        cout<<"Valid !";
    }else{
        cout<<"In valid !";
    }

    return 0;
}