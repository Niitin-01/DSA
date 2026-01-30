#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0, maxsum = nums[0];
        for(int i:nums){
            currsum = max(currsum+i, i);
            maxsum = max(maxsum, currsum);
        }
        return maxsum;


        // sliding-window style Kadane.
        
        // int e=0, sum=0, maxsum=INT_MIN;
        // while(e<nums.size()){
        //     sum += nums[e];
        //     maxsum = max(sum, maxsum);
        //     if(sum < 0){
        //         sum=0;
        //     }
        //     e++;
        // }
        // return maxsum;
    }
};


int main(){
    vector<int> v = {1, 3, -2, -8, 5, 10};
    Solution obj;
    cout << "max sub-subarray: " << obj.maxSubArray(v);
}