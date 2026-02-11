#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size(), n2 = nums2.size();

        int l=0, r=n1;

        while(l<=r){
            int px = l+(r-l)/2; // total elements from nums1 in left half
            int py = (n1+n2+1)/2-px; // total elements from nums2in left half;

            // extreme right elements of nums1 and nums2 in left half
            int x1 = (px == 0)? INT_MIN : nums1[px-1];
            int x2 = (py == 0)? INT_MIN : nums2[py-1];

            // extreme left elements of nums1 and nums2 in right half 
            int x3 = (px == n1)? INT_MAX : nums1[px];
            int x4 = (py == n2)? INT_MAX : nums2[py];

            if(x1 <= x4 && x2 <= x3){
                if((n1+n2)%2){
                    return max(x1, x2);
                }
                return (max(x1, x2) + min(x3, x4))/2.0;
            }
            if(x1 > x4) r = px-1;
            else l = px+1;
        }

        return -1;
    }
};

int main(){
    vector<int> nums1 = {1, 2, 3, 4, 5, 8, 9, 10};
    vector<int> nums2 = {5, 6, 8, 11, 13, 51};
    Solution sol;
    cout << "Median of nums1 and nums2: " << sol.findMedianSortedArrays(nums1, nums2) << endl;
}