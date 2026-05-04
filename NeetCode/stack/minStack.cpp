#include <iostream>
#include <stack>

using namespace std;
class minStack{
    public:
        stack<int> stk;
        minStack(){

        }

        void push(int val){
            stk.push(val);
        }

        void pop(){
            stk.pop();
        }

        int top(){
            return stk.top();
        }
        
        int getMin(){
            stack<int> tmp;
            int min_v = stk.top();
            while(stk.size()){
                min_v = min(min_v,stk.top());
                tmp.push(stk.top());
                stk.pop();
            }

            while(tmp.size()){
                stk.push(tmp.top());
                tmp.pop();
            }

            return min_v;
        }
};

class minStack_twoStack{
    public:
        stack<int> stk;
        stack<int> minStack;

        void push(int val){
            stk.push(val);
            val = min(val,(minStack.empty()? val:minStack.top()));
            minStack.push(val);
        }

        void pop(){
            stk.pop();
        }
        
        int top(){
           return stk.top();
        }

        int getMin(){
            return minStack.top();
        }
};
int main(){

    cout<<"Method: Brute Force\n";
    minStack mst;
    mst.push(1);
    mst.push(3);
    mst.push(2);
    mst.push(4);
    mst.push(5);

    cout<<"Min value is: "<<mst.getMin()<<endl;

    cout<<"Method: Two stack\n";
    minStack_twoStack mst_2stk;
    mst_2stk.push(1);
    mst_2stk.push(3);
    mst_2stk.push(2);
    mst_2stk.push(4);
    mst_2stk.push(5);

    cout<<"Min value is: "<<mst_2stk.getMin()<<endl;

    return 0;
}