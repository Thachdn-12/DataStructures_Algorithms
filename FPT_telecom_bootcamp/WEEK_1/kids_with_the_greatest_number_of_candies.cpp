#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
            vector<bool> res;
            for(int i=0; i<candies.size(); i++){
                int flag = 0;
                int greatest = candies[i] + extraCandies;
                for(int j=0; j<candies.size(); j++){
                    if(greatest < candies[j]){
                        flag = 1;
                    }
                }
                if(flag == 0){
                    res.push_back(true);
                }else{
                    res.push_back(false);
                }
                
            }
            return res;
        }

        vector<bool> kidsWithCandies_other(vector<int>& candies, int extraCandies) {
            int maxCandies = 0;
            for (int candy : candies) {
                maxCandies = max(maxCandies, candy);
            }

            vector<bool> result;
            for (int candy : candies) {
                result.push_back(candy + extraCandies >= maxCandies);
            }

            return result;
        }

};


int main(){
    vector<int> candies = {2,3,5,1,3};
    vector<bool> ret;
    int extraCandies = 3;
    solution sol;
    ret = sol.kidsWithCandies(candies,extraCandies);
    for(auto item:ret){
        cout<<item<<" ";
    }
    return 0;
}