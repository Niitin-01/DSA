#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int currsum=0, maxsum=nums[0], n=nums.size(), totalsum = 0;
        for(int i:nums){
            totalsum += i;
            currsum = max(currsum+i, i);
            maxsum = max(maxsum, currsum);
        }

        int minsum = nums[0];
        currsum = 0;
        for(int i:nums){
            currsum = min(currsum + i, i);
            minsum = min(minsum, currsum);
        }
        if(totalsum == minsum) return maxsum;
        return max(maxsum, totalsum-minsum);
    }
};

int main(){
    vector<int> v = {1, 3, -2, -8, 5, 10};
    Solution obj;
    cout << "max sub-subarray: " << obj.maxSubarraySumCircular(v);
}