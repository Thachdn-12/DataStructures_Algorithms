/*
    Requirement: 
        You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

        Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. 
        If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.
*/

#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures){
            vector<int> res(temperatures.size());
            for(int i = 0; i < temperatures.size(); i++){
                int j = i+1;
                int num_day = 1;
                while(j < temperatures.size()){
                    if(temperatures[j] > temperatures[i]){
                        break;
                    }
                    num_day ++;
                    j ++;
                }
                num_day = (j == temperatures.size())? 0: num_day;
                res[i] = num_day;
            }
            return res;
        }
};

int main(){
    solution sol;
    vector<int> temp = {30,38,30,36,35,40,28};
    vector<int> res = sol.dailyTemperatures(temp);
    cout<<"Here"<<endl;
    for(int i=0 ; i<res.size(); i++){
        cout<< res[i] << endl;
    }
    

    return 0;
}