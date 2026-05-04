#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
        int trapBruteForce(vector<int>& heights){
            if(heights.empty()){
                return 0;
            }
            int res = 0;
            for(int i=0; i<heights.size(); i++){
                int leftMax = heights[i];
                int rightMax = heights[i];
                for(int j=0; j<i; j++){
                    leftMax = max(leftMax,heights[j]);
                }
                for(int k =i+1; k<heights.size(); k++){
                    rightMax = max(rightMax, heights[k]);
                }
                res += min(leftMax, rightMax) - heights[i];
            }
            return res;
        }

        int trapTwoPointer(vector<int>& heights){
            if(heights.empty()){
                return 0;
            }
            int res = 0;
            int l = 0;
            int r = heights.size() -1;
            int maxL = heights[l];
            int maxR = heights[r];

            while(l<r){
                if(maxL < maxR){
                    l ++;
                    maxL = max(maxL, heights[l]);
                    res += maxL - heights[l];

                }else{
                    r --;
                    maxR = max(maxR,heights[r]);
                    res += maxR - heights[r];
                }
            }
            return res;
        }
};

int main(){
    solution sol;
    vector<int> heights = {0,2,0,3,1,0,1,3,2,1};

    int res = sol.trapTwoPointer(heights);
    cout<<"Trap value: "<<res;

    return 0;
}