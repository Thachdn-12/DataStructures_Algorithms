/*
    20. Valid Parentheses
*/

#include <iostream>
#include <stack>

using namespace std;

class solution{
    public:
        bool isValid(string s){
            stack<char> st;
            for(char c:s){
                if(c == '(' || c == '{' || c == '['){
                    st.push(c);
                }else{
                    if(st.empty()){
                        return false;
                    }
                    if(st.top() == '(' && c != ')') return false;
                    if(st.top() == '{' && c != '}') return false;
                    if(st.top() == '[' && c != ']') return false;

                    st.pop();
                }
            }
            return st.empty();
        }
};


int main(){
    solution sol;
    string s = "([)]";

    bool ret = sol.isValid(s);
    cout<<ret<<endl;

    return 0;
}