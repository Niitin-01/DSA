#include <iostream> 
#include <vector>
using namespace std; 

class Solution {
public:
    int lower_bound(vector<int>& nums, int target){
        int start=0, end=nums.size()-1, lb=-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                lb=mid;
                end = mid-1;
            } 
            else if(target > nums[mid]) start = mid+1;
            else end = mid-1;
        }
        return lb;
    }
    
    int last_occurence(vector<int>& nums, int target){
        int start=0, end=nums.size()-1, ub=-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                ub=mid;
                start = mid+1;
            } 
            else if(target > nums[mid]) start = mid+1;
            else end = mid-1;
        }
        return ub;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int last = last_occurence(nums, target);
        return {first, last};
    }
};

int main(){
    vector<int> v = {1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7, 7, 8};
    int target = 7;
    Solution obj;
    vector<int> ans = obj.searchRange(v, target);
    cout << "First and last occurence of " << target << ": ";
    cout << "[ ";
    for (int x : ans) cout << x << " ";
    cout << "]";

}