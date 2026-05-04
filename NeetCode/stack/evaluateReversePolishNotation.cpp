#include <iostream>
#include <stack>
#include <vector>

using namespace std;
/*
    Return the integer that represents the evaluation of the expression.
        The operands may be integers or the results of other operations.
        The operators include '+', '-', '*', and '/'.
        Assume that division between integers always truncates toward zero.
*/
class Solution{
    public:
        int evalRPN_bruteForce(vector<string>& token){
            while(token.size() >1){
                for(int i=0; i<token.size(); i++){
                    if(token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/"){
                        int a = stoi(token[i-2]);
                        int b = stoi(token[i-1]);
                        int res = 0;

                        if(token[i] == "+"){
                            res = a+b;
                        }else if(token[i] == "-"){
                            res = a-b;
                        }else if(token[i] == "*"){
                            res = a*b;
                        }else if(token[i] == "/"){
                            res = a/b;
                        }

                        token.erase(token.begin() + i - 2, token.begin() + i + 1);
                        token.insert(token.begin() + i - 2, to_string(res));

                        break;
                    }
                }
            }
            
            return stoi(token[0]);
        }
};
