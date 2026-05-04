/*
    88. Merge Sorted Array
*/

#include <iostream>
#include <vector>

using namespace std;

class solution{
    public:
        void merge_leftToRight(vector<int>& nums1, int m, vector<int>& nums2, int n){
            int i=0, j=0;
            vector<int> temp;
            while(i < m && j < n){
                if(nums1[i] < nums2[j]){
                    temp.push_back(nums1[i]);
                    i++;
                }else{
                    temp.push_back(nums2[j]);
                    j++;
                }
            }
            while(i<m){
                temp.push_back(nums1[i]);
                i++;
            }

            while(j<n){
                temp.push_back(nums2[j]);
                j++;
            }

            for(int h=0; h<(m+n); h++){
                nums1[h] = temp[h];
            }

            for(int i =0; i < m+n; i++){
                cout<<"nums1["<<i<<"] = "<<nums1[i]<< endl;
            }
        }

        void merge_rightToLeft(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                int i=m-1;
                int j=n-1;
                int k=(m+n)-1;

                while(i>=0 && j>=0){
                    if(nums1[i] > nums2[j]){
                        nums1[k] = nums1[i];
                        i--;
                    }else{
                        nums1[k] = nums2[j];
                        j--;
                    }
                    k--;
                }
                while(j>=0){
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                }
                for(int r=0; r<(n+m); r++){
                    cout<<"nums1["<<r<<"] = "<<nums1[r]<< endl;
                }
        }

};

int main(){
    solution ret;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;

    //ret.merge_leftToRight(nums1,m,nums2,n);
    cout<<"\n ++++++++++++++++++++++++++ \n";
    ret.merge_rightToLeft(nums1, m, nums2, n);
    
    return 0;
}