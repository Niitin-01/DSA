#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& nums, int start, int end, int target){
    if(start > end) return -1;
    int mid = start + (end-start)/2;
    if(nums[mid] == target) return mid;
    if(nums[mid] > target) return binarySearch(nums, start, mid-1, target);
    else return binarySearch(nums, mid+1, end, target);
}

int main(){
    int n, target;
    cin >> n;

    vector<int> nums(n, 0);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    cin >> target;

    int idx = binarySearch(nums, 0, n - 1, target);
    if(idx == -1)
        cout << "target not found";
    else
        cout << "target is found at index: " << idx;

}