#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
        int maxAreaBruteForce(vector<int>& heights){
            int height = 0;
            int sumTemp = 0;
            for(int i=0; i <heights.size(); i++){
                for(int j=i+1; j <heights.size(); j++){
                    //if(heights[i] < heights[j]){
                    //    sumTemp = heights[i]*(j-i);
                    //}else{
                    //    sumTemp = heights[j]*(j-i);
                    //}
                    sumTemp = min(heights[i],heights[j])*(j-i);
                    height = max(height,sumTemp);
                }
            }
            return height;
        }

        int maxAreaTwoPointer(vector<int>& heights){
            int height = 0;
            int l = 0;
            int r = heights.size() -1;
            while(l<r){
                int tmpArea = min(heights[l], heights[r])*(r-l);
                if(heights[l]<=heights[r]){
                    l++;
                }else{
                    r --;
                }
                height = max(height,tmpArea);
            }
            return height;
        }
};
int main(){
    solution sol;
    vector<int> heights = {1,7,2,5,4,7,3,6};

    //int res = sol.maxAreaBruteForce(heights);
    int res = sol.maxAreaTwoPointer(heights);
    cout<<"Max Area: "<< res;
    return 0;
}